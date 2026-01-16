#pragma once
#include <Arduino.h>

class IrSensor {
private:
    int pin;
    float value;
public:
    IrSensor(int p);
    float getValue();
    void setValue(float v);
    
    
};  