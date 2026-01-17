#include "IrSensors.h"

IrSensor::IrSensor(int p, String n, float a) : SensorBase(n), pin(p), angle(a) {
		type = IR_SENS;
    pinMode(p, INPUT_PULLUP);
}

float IrSensor::getAngle() {
	return angle;
}

void IrSensor::update() {
	if (digitalRead(pin) == LOW) {
		value++;
	}
}

float IrSensor::getValue() {
	return value;
}

void IrSensor::resetValue() {
	value = 0.0f;
}