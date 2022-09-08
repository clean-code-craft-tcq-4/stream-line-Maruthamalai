#include <iostream>
#include "temperature.hpp"
#include "random"

using namespace std;

vector<int> getTemperatureInCelcious(int min, int max, int numberOfReadings)
{

  std::random_device rd;                         // obtain a random number from hardware
  std::mt19937 gen(rd());                        // seed the generator
  std::uniform_int_distribution<> distr(min, max); // define the range

  vector<int> temperatureListInCelcious;
  
  for (int readCount = 0; readCount < numberOfReadings; readCount++)
  {
    temperatureListInCelcious.push_back(distr(gen));
  }
  return temperatureListInCelcious;
}



