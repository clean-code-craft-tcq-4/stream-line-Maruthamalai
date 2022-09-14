#include <cstring>
//#include <cstdio>
//#include <cstdlib>
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "bmsStatistics.hpp"

using namespace std;

void sortBmsData(int currList[], int tempList[]) {
    for (int index=0; index<(WRITE_COUNT-1); index++) {
        for (int innerIndex=0; innerIndex<(WRITE_COUNT-index-1); innerIndex++) {
            if (currList[innerIndex] > currList[innerIndex + 1]) {
                int temp = currList[innerIndex];
                currList[innerIndex] = currList[innerIndex + 1];
                currList[innerIndex + 1] = temp;
            }
            if (tempList[innerIndex] > tempList[innerIndex + 1]) {
                int temp = tempList[innerIndex];
                tempList[innerIndex] = tempList[innerIndex + 1];
                tempList[innerIndex + 1] = temp;
            }
        }
    }
}

int minBmsData(int bmsList[]) {
  return bmsList[MIN_RANGE];
}

int maxBmsData(int bmsList[]) {
  return bmsList[MAX_RANGE-1];
}

void movingAvgOfBmsData(int currList[], int tempList[]) {
  int currAvg =0;
  int tempAvg =0;
  for(int index=WRITE_COUNT-5; index<WRITE_COUNT; index++) {
    currAvg |= currList[index];
    tempAvg |= tempList[index];
  }
  cout<<"Moving Average of last 5 values:\n"<<"Current Average: %d\n"<<currAvg<<"Temperature Average: %d\n"<<tempAvg;
}

void splitBmsData(int bmsDataList[], int currList[], int tempList[]) {
  int currIndex=0, tempIndex=50;
  for(int index=0; index<WRITE_COUNT; index++, currIndex++, tempIndex++) {
    currList[index]=bmsDataList[currIndex];
    tempList[index]=bmsDataList[tempIndex];
  }
}

void bmsDataCharToInt(char writeBuffer[], int buffSize, int bmsDataList[]) {
  int tempArrIndex;
  //int dataIndex =0;
  int currIndex=0, tempIndex=50;
  for(int index=0; index<buffSize; currIndex++, tempIndex++) {
    char temp[4];
    memset(temp, '\0', sizeof(temp));
    tempArrIndex = 0;
    while((writeBuffer[index]!=',') && (writeBuffer[index]!='\n')) {
      temp[tempArrIndex] = writeBuffer[index];
      tempArrIndex++;
      index++;
    }
    index++;
    bmsDataList[currIndex] = stoi(temp);
    cout<<bmsDataList[currIndex]<<"\n";
    memset(temp, '\0', sizeof(temp));
    tempArrIndex = 0;
    while(writeBuffer[index]!='\n') {
      temp[tempArrIndex] = writeBuffer[index];
      tempArrIndex++;
      index++;
    }
    index++;
    bmsDataList[tempIndex] = stoi(temp);
    cout<<bmsDataList[tempIndex]<<"\n";
  }
}

void bmsDataStatistics(char writeBuffer[], int buffSize) {
  int bmsDataList[WRITE_COUNT*2];
  int currList[WRITE_COUNT];
  int tempList[WRITE_COUNT];
  bmsDataCharToInt(writeBuffer, buffSize, bmsDataList);
  splitBmsData(bmsDataList,currList, tempList);
  movingAvgOfBmsData(currList, tempList);
  sortBmsData(currList, tempList);
  cout<<"Minimum Current: %d\n"<<minBmsData(currList)<<"Maximum Current: %d\n"<<maxBmsData(currList);
  cout<<"Minimum Temperature: %d\n"<<minBmsData(tempList)<<"Maximum Temperature: %d\n"<<maxBmsData(tempList);
}
