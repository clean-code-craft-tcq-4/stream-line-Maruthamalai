
#include <iostream>
#include "../batterySensors/chargeStatus/chargeStatus.hpp"
#include "../batterySensors/temperature/temperature.hpp"
#include <vector>
#include "sensorDataSender.hpp"

using namespace std;

bool writeDataToConsole()
{
  bool writeStatus = false;
  vector<int> currentListInAmps = getCurrentListInAmps(AMP_MIN, AMP_MAX, WRITE_COUNT);
  vector<int> temperatureListInCelcious = getTemperatureInCelcious(TEMPERATURE_MIN_VALUE, TEMPERATURE_MAX_VALUE, WRITE_COUNT);

  if ((currentListInAmps.size() == WRITE_COUNT) && (temperatureListInCelcious.size() == WRITE_COUNT))
  {
    for (int counter = 0; counter < WRITE_COUNT; counter++)
    {
      cout << currentListInAmps[counter] << ", " << temperatureListInCelcious[counter] << endl;
    }

    writeStatus = true;
  }

  return writeStatus;
}
