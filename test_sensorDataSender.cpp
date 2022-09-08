#define CATCH_CONFIG_MAIN
#include "test/catch.hpp"
#include <iostream>
#include "batterySensors/chargeStatus/chargeStatus.hpp"
#include "batterySensors/temperature/temperature.hpp"
#include <vector>
#include "sensorDataSender/sensorDataSender.hpp"

using namespace std;

TEST_CASE("TestTemperatureSensorValues") {
  vector<int> generatedTemperatureValues = getTemperatureInCelcious(AMP_MIN ,AMP_MAX, WRITE_COUNT);

  REQUIRE(generatedTemperatureValues.size() == WRITE_COUNT);
}

TEST_CASE("TestCurrentSensorValues") {
  vector<int> currentListInAmps = getCurrentListInAmps(AMP_MIN ,AMP_MAX, WRITE_COUNT);
  
  REQUIRE(currentListInAmps.size() == WRITE_COUNT);
}

TEST_CASE("TestWriteStatus") {
  
  REQUIRE(writeDataToConsole() == true);
}


