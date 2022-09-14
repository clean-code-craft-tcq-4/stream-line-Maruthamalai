#include <cstring>
//#include <cstdio>
//#include <cstdlib>
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

/*int sortBmsData() {
  
}

int minBmsData() {
  
}

int maxBmsData() {
  
}

int movingAvgOfBmsData() {
  
}

int bmsDataCharToInt {
  
}*/

int bmsDataStatistics(char writeBuffer[], int buffSize) {
  int tempIndex;
  int currList[WRITE_COUNT];
  int tempList[WRITE_COUNT];
  int currIndex=0, tempIndex=0;
  for(int index=0; index<bufSize; currIndex++, tempIndex++) {
    char temp[4];
    memset(temp, '\0', sizeof(temp));
    tempIndex = 0;
    while(writeBuffer[index]!=',') {
      temp[tempIndex] = writeBuffer[index];
      tempIndex++;
      index++;
    }
    index++;
    currList[currIndex] = stoi(temp);
    cout<<currList[currIndex]<<"\t";
    memset(temp, '\0', sizeof(temp));
    tempIndex = 0;
    while(writeBuffer[index]!='\n') {
      temp[tempIndex] = writeBuffer[index];
      tempIndex++;
      index++;
    }
    index++;
    tempList[tempIndex] = stoi(temp);
    cout<<tempList[tempIndex]<<"\n";
  }
}
