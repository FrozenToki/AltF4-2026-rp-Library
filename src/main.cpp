#include <Arduino.h>
#include "app/Application.h"
#include "config/Config.h"

Application app;

//Teensy* te = app.getOutputManager().getTeensyByName("tennsy");
IrSensor* s[Config::COUNT_IR_SENSOR];

void setup() {
	for (int i = 0; i < Config::COUNT_IR_SENSOR; i++) {
		s[i] =app.getSensorManager().getIrSensorByIndex(i);
	}
	
	Serial.begin(9600);


}

void loop() {
  
	app.getIrSensorReader().readAll(255,false,3000);
	app.getIrSensorReader().setAll();
	app.getBallPositionReader().setValues();
	
	std::vector<float> values = app.getBallPositionReader().getValues();

	for (int i = 0; i < 16; i++) {
		Serial.print(values[i]);
		Serial.print(" : ");
		
	}
	
	app.getBallPositionReader().setHighestSensor();
	Serial.print(app.getBallPositionReader().getMean());

	app.getBallPositionReader().setHighestSensVec();
	app.getBallPositionReader().addHighestSensVec();
	Vector v = app.getBallPositionReader().getBallVector();
	
	Serial.print(" : ");
	Serial.print(v.getX());
	Serial.print(" : ");
	Serial.print(v.getY());

	//for (size_t i = 0; i < hochsteSens.size(); i++) {
	//	Serial.print(hochsteSens[i]->getAngle());
	//	Serial.print(" : ");
	//}
	Serial.println(" ; ");

	delay(100);
	
}
