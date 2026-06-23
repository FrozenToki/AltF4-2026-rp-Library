#pragma once
#include <Arduino.h>

 
class Config {
public:
	static const int IR_SENSOR_PINS[16];
	static const char* IR_SENSOR_NAMES[16];
	static const float IR_SENSOR_ANGLES[16];

	static constexpr int COUNT_IR_SENSOR = 16;
};
