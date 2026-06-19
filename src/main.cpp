#include <Arduino.h>
#include "app/ApplicationInnit.h"
#include "config/Config.h"
#include <tuple>

ApplicationInnit app;

IrSensor* s[16];

MovingAverage ballDistnaceAvrg(3);
MovingAverage ballAngleAvrg(3,true);

unsigned long sendingPeriod = 20;
unsigned long lastTime = 0;

void setup() {

	for (int i = 0; i < 16; i++)	{
    

		app.getSensorManager().createIrSensor(Config::IR_SENSOR_PINS[i], Config::IR_SENSOR_NAMES[i], 
									Config::IR_SENSOR_ANGLES[i]);	
		}

	app.getSerialComm().startSerialConnection(false,false);

	app.getSerialComm().enableSerialComm();


	Serial.println("setup ok");

	for (int i = 0; i < 16; i++) {
		s[i] =app.getSensorManager().getIrSensorByIndex(i);
		app.getSerialValuePool().set("IR" + String(i), 0.0F);
	}
	
	//Serial1.begin(115200); // Setup the connection to the Teensy

	//Serial.begin(9600);

	app.getIrSensorReader().initializeIrSensorReader(16);
	app.getBallPositionReader().initializeBallPositionReader(16);

	app.getSerialValuePool().set("IR Dist" , 0.0F);
	app.getSerialValuePool().set("IR Angle", 0.0F);
}


std::vector <IrSensor*> highestSensors;

void loop() {
  // === READ IRSENSORS ===
	app.getIrSensorReader().readAll(255,false,3000);
	app.getIrSensorReader().setAll();
	
	// === GET HIGHEST SENSORS === 
	app.getBallPositionReader().setValues();
	app.getBallPositionReader().setHighestSensor();
	
	//// === CALCULATE THE BALL VECTOR ===
	app.getBallPositionReader().setHighestSensVec();
	app.getBallPositionReader().addHighestSensVec();
	Vector ballVector = app.getBallPositionReader().getBallVector();
	
	// === CALCULATE THE BALLS DISTANCE AND ANGLE ===
	float angle = 0, strength = 0;
	std::tie(angle, strength) = app.getGeometry().vectorToAngle(ballVector); 

	angle = app.getGeometry().radToAngle(angle);
	
	// === GET THE MOVING AVERAGE OF THE BALLS POSITION ===
	ballDistnaceAvrg.newValue(strength);
	float newStrength = ballDistnaceAvrg.getAverage();

	ballAngleAvrg.newValue(angle);
	float newAngle = ballAngleAvrg.getAverage();

	for (int i = 0; i < 16; i++) {
		
		app.getSerialValuePool().set("IR" + String(i), s[i]->getCalculatedValue());
	}

	app.getSerialValuePool().set("IR Dist" , newStrength);
	app.getSerialValuePool().set("IR Angle", newAngle);

	//// === SEND THE BALL ANGLE AND STRENGTH TO THE TEENSY ===
	//if (millis() - lastTime > sendingPeriod) {

	//	//highestSensors = app.getBallPositionReader().getHighestSensors();
		 
	//	//Serial.println("___________");
	//	//for (size_t i = 0; i < 5; i++) {
	//	//	Serial.print(highestSensors[i]->getAngle());
	//	//  Serial.print("[");
	//	//	Serial.print(highestSensors[i]->getVector().getX());
	//	//  Serial.print(",");
	//	//	Serial.print(highestSensors[i]->getVector().getY());
	//	//  Serial.println("]");
	//	//}

	//	//Serial.print("[");
	//	//Serial.print(ballVector.getX());
	//	//Serial.print(",");
	//	//Serial.print(ballVector.getY());

	//	//Serial.print("] strength: ");
  //	//Serial.print(strength);

	//	//Serial.print(" neuer Abstand: ");
		

	//	//Serial.print(" Winkel: ");
  //	//Serial1.print(angle);

	//	//Serial.print(" neuer Winkel: ");
	//	Serial1.print("<");
		
	//	Serial1.print(newAngle);
	//	Serial1.print(",");
	//	Serial1.print(newStrength);

	//	Serial1.print(">");

	//	Serial1.flush();
	//	//Serial.println(" ; ");
	//	lastTime = millis();
	//}	

	app.getSerialComm().sendingLoop();
}
