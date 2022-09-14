#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "../batterySensors/chargeStatus/chargeStatus.hpp"
#include "../batterySensors/temperature/temperature.hpp"
#include <vector>

using namespace std;

int readDataFromConsole(int pip[], char writeBuffer[])
{
    //char writeBuffer[1000];
    memset(writeBuffer, 0, 500);
    read(pip[0], writeBuffer, 450);
    //cout<<writeBuffer;
    cout<<strlen(writeBuffer);
    return strlen(writeBuffer);
}
