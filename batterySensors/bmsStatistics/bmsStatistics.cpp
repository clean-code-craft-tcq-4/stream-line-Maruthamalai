#include <cstring>
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
  currAvg /=5;
  tempAvg /=5;
  cout<<"Moving Average of last 5 values:\n";
  cout<<"Current Average: "<<currAvg<<"\n";
  cout<<"Temperature Average: "<<tempAvg<<"\n";
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
  int currIndex=0, tempIndex=50;
  for(int index=0; index<buffSize; currIndex++, tempIndex++) {
    char temp[4];
    memset(temp, '\0', sizeof(temp));
    tempArrIndex = 0;
    while((writeBuffer[index]!=',') && (writeBuffer[index]!='\t')) {
      temp[tempArrIndex] = writeBuffer[index];
      tempArrIndex++;
      index++;
    }
    index+=2;
    bmsDataList[currIndex] = stoi(temp);
    //cout<<bmsDataList[currIndex]<<"\t";
    memset(temp, '\0', sizeof(temp));
    tempArrIndex = 0;
    while(writeBuffer[index]!='\n') {
      temp[tempArrIndex] = writeBuffer[index];
      tempArrIndex++;
      index++;
    }
    index++;
    bmsDataList[tempIndex] = stoi(temp);
    //cout<<bmsDataList[tempIndex]<<"\n";
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
  cout<<"Minimum Current: "<<minBmsData(currList)<<"\n";
  cout<<"Maximum Current: "<<maxBmsData(currList)<<"\n";
  cout<<"Minimum Temperature: "<<minBmsData(tempList)<<"\n";
  cout<<"Maximum Temperature: "<<maxBmsData(tempList)<<"\n";
}
