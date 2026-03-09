#include <Arduino.h>
#include "app/Application.h"
#include "config/Config.h"
#include <tuple>

Application app;

IrSensor* s[Config::COUNT_IR_SENSOR];

MovingAverage ballDistnaceAvrg(Config::COUNT_MOVING_AVERAGE);
MovingAverage ballAngleAvrg(Config::COUNT_MOVING_AVERAGE,true);

unsigned long sendingPeriod = 20;
unsigned long lastTime = 0;

void setup() {
	for (int i = 0; i < Config::COUNT_IR_SENSOR; i++) {
		s[i] =app.getSensorManager().getIrSensorByIndex(i);
	}
	
	Serial1.begin(115200); // Setup the connection to the Teensy

	//Serial.begin(9600);
}


std::vector <IrSensor*> highestSensors;

void loop() {
  // === READ IRSENSORS ===
	app.getIrSensorReader().readAll(255,false,3000);
	app.getIrSensorReader().setAll();
	
	// === GET HIGHEST SENSORS === 
	app.getBallPositionReader().setValues();
	app.getBallPositionReader().setHighestSensor();
	
	// === CALCULATE THE BALL VECTOR ===
	app.getBallPositionReader().setHighestSensVec();
	app.getBallPositionReader().addHighestSensVec();
	Vector ballVector = app.getBallPositionReader().getBallVector();
	
	// === CALCULATE THE BALLS DISTANCE AND ANGLE ===
	float angle = 0, strength = 0;
	std::tie(angle, strength) = app.getGeometrie().vectorToAngle(ballVector); 

	angle = app.getGeometrie().radToAngle(angle);
	
	// === GET THE MOVING AVERAGE OF THE BALLS POSITION ===
	ballDistnaceAvrg.newValue(strength);
	float newStrength = ballDistnaceAvrg.getAverage();

	ballAngleAvrg.newValue(angle);
	float newAngle = ballAngleAvrg.getAverage();

	// === SEND THE BALL ANGLE AND STRENGTH TO THE TEENSY ===
	if (millis() - lastTime > sendingPeriod) {

		//highestSensors = app.getBallPositionReader().getHighestSensors();
		 
		//Serial.println("___________");
		//for (size_t i = 0; i < 5; i++) {
		//	Serial.print(highestSensors[i]->getAngle());
		//  Serial.print("[");
		//	Serial.print(highestSensors[i]->getVector().getX());
		//  Serial.print(",");
		//	Serial.print(highestSensors[i]->getVector().getY());
		//  Serial.println("]");
		//}

		//Serial.print("[");
		//Serial.print(ballVector.getX());
		//Serial.print(",");
		//Serial.print(ballVector.getY());

		//Serial.print("] strength: ");
  	//Serial.print(strength);

		//Serial.print(" neuer Abstand: ");
		

		//Serial.print(" Winkel: ");
  	//Serial1.print(angle);

		//Serial.print(" neuer Winkel: ");
		Serial1.print("<");
		
		Serial1.print(newAngle);
		Serial1.print(",");
		Serial1.print(newStrength);

		Serial1.print(">");

		Serial1.flush();
		//Serial.println(" ; ");
		lastTime = millis();
	}	
}
