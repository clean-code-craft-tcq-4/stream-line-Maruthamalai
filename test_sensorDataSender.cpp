#define CATCH_CONFIG_MAIN
#include "test/catch.hpp"
#include <iostream>
#include "batterySensors/chargeStatus/chargeStatus.hpp"
#include "batterySensors/temperature/temperature.hpp"
#include <vector>
#include "sensorDataSender/sensorDataSender.hpp"
#include "sensorDataReceiver/sensorDataReceiver.hpp"
#include <cstring>

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
  int retStatus = true;
	int pid, pip[2]; 
	retStatus = pipe(pip);	
	if (retStatus != -1)
	{
	   pid = fork();
	   if (pid == 0) {
	      retStatus = writeDataToConsole(pip);
	      REQUIRE(retStatus == true);  
	   } else {
	      char readBuffer[500];
	      int buffSize = readDataFromConsole(pip, readBuffer);
	      cout<<"Test: "<<strlen(readBuffer);
	      //REQUIRE(buffSize == 450);
	      bmsDataStatistics(readBuffer, strlen(readBuffer));
	   }
  }
}


