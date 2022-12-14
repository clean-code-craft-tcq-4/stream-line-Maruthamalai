#include <cstring>
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "../batterySensors/chargeStatus/chargeStatus.hpp"
#include "../batterySensors/temperature/temperature.hpp"
#include <vector>
#include "sensorDataSender.hpp"

using namespace std;

int writeDataToConsole(int pip[])
{
    int writeBuffSize = 0;
    char writeBuffer[550];
    memset(writeBuffer, '\0', sizeof(writeBuffer));
    vector<int> currentListInAmps = getCurrentListInAmps(AMP_MIN, AMP_MAX, WRITE_COUNT);
    vector<int> temperatureListInCelcious = getTemperatureInCelcious(TEMPERATURE_MIN_VALUE, TEMPERATURE_MAX_VALUE, WRITE_COUNT);

    if ((currentListInAmps.size() == WRITE_COUNT) && (temperatureListInCelcious.size() == WRITE_COUNT))
    {
        for (int counter = 0; counter < WRITE_COUNT; counter++)
        {
            char tempBuffer[11];
            memset(tempBuffer, '\0', sizeof(tempBuffer));
            sprintf(tempBuffer, "%d,\t%d\n", currentListInAmps[counter], temperatureListInCelcious[counter]);
            strcat(writeBuffer, tempBuffer);
        }
        writeBuffSize = strlen(writeBuffer);
        write(pip[1], writeBuffer, writeBuffSize);
    }
    return writeBuffSize;
}
