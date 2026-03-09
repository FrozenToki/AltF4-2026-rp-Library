#pragma once
#include <Arduino.h>

// Used to get variables that will not be change while running the programm.
// 
// Easy acces about app->getConfig().NameOfTheVariable when the variable is used 
// while the programm is running. If the variable is essential for the compiler, 
// it needs to be accesed directly with Config::NameOfTheVariable.  
class Config {
public:
	static constexpr int MAX_SENSORS = 20; 
	static constexpr int MAX_ERROR_MESSAGES = 5;

	static constexpr int COUNT_IR_SENSOR = 16; 
	static const int IR_SENSOR_PINS[COUNT_IR_SENSOR];
	static const char* IR_SENSOR_NAMES[COUNT_IR_SENSOR];
	static const float IR_SENSOR_ANGLES[COUNT_IR_SENSOR];

	static constexpr int COUNT_MOVING_AVERAGE = 3;

	
};
