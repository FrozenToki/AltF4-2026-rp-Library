#pragma once
#include <Arduino.h>
#include "Sensorik/SensorBase/SensorBase.h"

class IrSensor : public SensorBase {
private:
    int pin;
		float angle;
public:
    IrSensor(int p, String n, float a);
    void update() override;
		float getValue() override;
		void resetValue();

		float getAngle();
};  