#pragma once
#include "Arduino.h"
#include "app/ApplicationInnit.h"
#include "Config/Config.h"

extern ApplicationInnit app;

extern IrSensor* s[Config::COUNT_IR_SENSOR];


void Setup();



