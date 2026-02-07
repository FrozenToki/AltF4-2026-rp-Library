#pragma once
#include <Arduino.h>
#include "Sensorik/SensorBase/SensorBase.h"
#include "BallDetection/Vector/Vector.h"

class IrSensor : public SensorBase {
private:
	int pin;
	float angle;
	float avrgAngle;
	float calculatedValue;
	Vector vec;
public:
	IrSensor(int p, String n, float a);
	void update() override;
	float getValue() override;
	float getCalculatedValue();
	void setCalculatedValue(float v);
	void resetValue();
	
	void setVector(const Vector& v);
	Vector getVector();

	float getAngle();
	
	void setAvrgAngle(float v);
	float getAvrgAngle();
};  