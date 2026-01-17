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
	static constexpr int MAX_OUTPUTS = 1;  
	static constexpr int MAX_ERROR_MESSAGES = 5;

	static constexpr int COUNT_IR_SENSOR = 16; 
	static constexpr int IR_SENSOR_PINS[COUNT_IR_SENSOR] = {14, 4, 5, 8, 2, 12, 9, 11, 3, 10, 6, 13, 27, 26, 7, 15};
	static constexpr const char* IR_SENSOR_NAMES[COUNT_IR_SENSOR] = {"S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "S11", "S12", "S13", "S14", "S15", "S16"};
	static constexpr float IR_SENSOR_ANGLES[COUNT_IR_SENSOR] = {0.0f, 22.5f, 45.0f, 67.5f, 90.0f, 112.5f, 135.0f, 157.5f, 180.0f, 202.5f, 225.0f, 247.5f, 270.0f, 292.5f, 315.0f, 337.5f};
};
