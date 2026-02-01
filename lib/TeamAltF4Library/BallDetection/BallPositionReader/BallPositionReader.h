#pragma once
#include "Arduino.h"
#include "BallDetection/Vector/Vector.h"
#include "Config/Config.h"
#include "Sensorik/SensorBase/IrSensors/IrSensors.h"
#include <vector>


// forward declaration
class Application;

class BallPositionReader {
private: 

	IrSensor* irSensList[Config::COUNT_IR_SENSOR];
	std::vector<float> valueList;
	std::vector<IrSensor*> hightestSensors;
	float mean;
	Application* app;

	Vector ballVector;
public: 
	BallPositionReader(Application* a);
	void setValues();
	std::vector<float> getValues();
	void setHighestSensor();
	float getMean();
	std::vector<IrSensor*> getHighestSensor();
	void setHighestSensVec();
	void addHighestSensVec();

	Vector getBallVector();
};