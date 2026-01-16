#include <Arduino.h>
#include "IrSensors.h"



IrSensor S1(14);
IrSensor S2(4);
IrSensor S3(5);
IrSensor S4(8);
IrSensor S5(2);
IrSensor S6(12);
IrSensor S7(9);
IrSensor S8(11);
IrSensor S9(3);
IrSensor S10(10);
IrSensor S11(6);
IrSensor S12(13);
IrSensor S13(27);
IrSensor S14(26);
IrSensor S15(7);
IrSensor S16(15);

static IrSensor* senList[16] = {nullptr}; 
senList[1] = S1;





void setup() {
  
  
}

void loop() {
  
}
