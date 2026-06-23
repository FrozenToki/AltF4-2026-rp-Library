#include "Setup.h"
#include "app/ApplicationInnit.h"


IrSensor* s[Config::COUNT_IR_SENSOR];



void Setup() {
	for (int i = 0; i < Config::COUNT_IR_SENSOR; i++)	{
		app.getSensorManager().createIrSensor(Config::IR_SENSOR_PINS[i], Config::IR_SENSOR_NAMES[i], 
								Config::IR_SENSOR_ANGLES[i]);	
	}
	
	Serial1.begin(115200); // Setup the connection to the Teensy

	//Serial.begin(9600);

	app.getIrSensorReader().initializeIrSensorReader(Config::COUNT_IR_SENSOR);
	app.getBallPositionReader().initializeBallPositionReader(Config::COUNT_IR_SENSOR);
}
