#include "SensorBase.h"

SensorBase::SensorBase(String n) : value(0.0f), name(n) {}

String SensorBase::IR_SENS = "IrSens";

float SensorBase::readSensor() {
	this->update();
	return this->getValue();
}

String& SensorBase::getNameRef() {
	return name;
}

String SensorBase::getName() const {
	return name;
}

String SensorBase::getType() const {
	return type;
}
