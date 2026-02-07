#include <Arduino.h>
#include "app/Application.h"
#include "config/Config.h"
#include <tuple>

Application app;

//Teensy* te = app.getOutputManager().getTeensyByName("tennsy");
IrSensor* s[Config::COUNT_IR_SENSOR];

MovingAverage ballDistnaceAvrg(Config::COUNT_MOVING_AVERAGE);
MovingAverage ballAngleAvrg(Config::COUNT_MOVING_AVERAGE,true);

void setup() {
	for (int i = 0; i < Config::COUNT_IR_SENSOR; i++) {
		s[i] =app.getSensorManager().getIrSensorByIndex(i);
	}
	
	Serial1.begin(9600);


}

float lastTime = 0;

std::vector <IrSensor*> ve;
void loop() {
  
	app.getIrSensorReader().readAll(255,false,3000);
	app.getIrSensorReader().setAll();
	app.getBallPositionReader().setValues();
	app.getBallPositionReader().setHighestSensor();
	app.getBallPositionReader().setHighestSensVec();
	app.getBallPositionReader().addHighestSensVec();
	Vector v = app.getBallPositionReader().getBallVector();
	
	float angle = 0, strenght = 0;

	std::tie(angle, strenght) = app.getGeometrie().vectorToAngle(v); 

	angle = app.getGeometrie().radToAngle(angle);
	

	ballDistnaceAvrg.newValue(strenght);
	float newStrenght = ballDistnaceAvrg.getAverage();

	ballAngleAvrg.newValue(angle);
	float newAngle = ballAngleAvrg.getAverage();


	if (millis() - lastTime > 100) {

		ve = app.getBallPositionReader().getHighestSensor();
		 
		//Serial.println("___________");
		//for (size_t i = 0; i < 5; i++) {
		//	Serial.print(ve[i]->getAngle());
		//  Serial.print("[");
		//	Serial.print(ve[i]->getVector().getX());
		//  Serial.print(",");
		//	Serial.print(ve[i]->getVector().getY());
		//  Serial.println("]");
		//}

		//Serial.print("[");
		//Serial.print(v.getX());
		//Serial.print(",");
		//Serial.print(v.getY());

		//Serial.print("] strength: ");
  	//Serial.print(newStrenght);



		//Serial.print(" neuer Abstand: ");
		//Serial.print(newStrenght);

		//Serial.print(" Winkel: ");
  	Serial1.println(newAngle);

		//Serial.print(" neuer Winkel: ");
		//Serial.print(newAngle);

		//Serial.println(" ; ");
		lastTime = millis();
	}	
}
