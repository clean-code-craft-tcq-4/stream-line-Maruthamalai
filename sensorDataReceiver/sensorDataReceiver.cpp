#include <cstring>
#include <cstdio>
#include <unistd>
#include <iostream>
#include "../batterySensors/chargeStatus/chargeStatus.hpp"
#include "../batterySensors/temperature/temperature.hpp"
#include <vector>
#include "sensorDataSender.hpp"

using namespace std;

void readDataFromConsole(int pip[])
{
    char writeBuffer[1000];
    memset(writeBuffer, 0, sizeof(writeBuffer));
    read(pip[0], writeBuffer, 450);
    cout<<writeBuffer;
}
