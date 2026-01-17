#include <Arduino.h>
#include "app/Application.h"

Application app;

void setup() {
  Serial.begin(9600);
	app.getIrSensorReader().readAll(0,true,3000);
	float values[16];
	app.getIrSensorReader().getAllValues(values);
	Serial.begin(9600);
	for (int i = 0; i < 16; i++) {
		Serial.print(i);
		Serial.print(": ");
		Serial.println(values[i]);
	}
	

}

void loop() {
  
}
