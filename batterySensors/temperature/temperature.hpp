#pragma once
#include <vector>

#define TEMPERATURE_MIN_VALUE  (-50)
#define TEMPERATURE_MAX_VALUE  (150)

using namespace std;

vector<int> getTemperatureInCelcious(int min, int max, int numberOfReadings);



