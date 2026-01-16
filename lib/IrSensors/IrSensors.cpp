#include "IrSensors.h"

IrSensor::IrSensor(int p) : pin(p) {
    pinMode(p, INPUT);
    
}

float IrSensor::getValue() {
    return value;
}

void IrSensor::setValue(float v) {
    value = v;
}
