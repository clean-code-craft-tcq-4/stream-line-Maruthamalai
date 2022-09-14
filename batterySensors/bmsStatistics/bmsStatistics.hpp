#pragma once

#define WRITE_COUNT  (50)
#define MIN_RANGE     0
#define MAX_RANGE     WRITE_COUNT

int minBmsData(int bmsList[]);
int maxBmsData(int bmsList[]);
void sortBmsData(int currList[], int tempList[]);
void movingAvgOfBmsData(int currList[], int tempList[]);
void bmsDataCharToInt(char writeBuffer[], int buffSize, int bmsDataList[]);
void splitBmsData(int bmsDataList[], int currList[], int tempList[]);
void bmsDataStatistics(char writeBuffer[], int buffSize);
