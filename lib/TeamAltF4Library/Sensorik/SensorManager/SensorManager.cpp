#include "SensorManager.h"
#include "app/Application.h"

SensorManager::SensorManager(Application* a) : app(a) {


	this->createIrSensor(Config::IR_SENSOR_PINS[0],Config::IR_SENSOR_NAMES[0],Config::IR_SENSOR_ANGLES[0]);	
	this->createIrSensor(Config::IR_SENSOR_PINS[1],Config::IR_SENSOR_NAMES[1],Config::IR_SENSOR_ANGLES[1]);	
	this->createIrSensor(Config::IR_SENSOR_PINS[2],Config::IR_SENSOR_NAMES[2],Config::IR_SENSOR_ANGLES[2]);	
	this->createIrSensor(Config::IR_SENSOR_PINS[3],Config::IR_SENSOR_NAMES[3],Config::IR_SENSOR_ANGLES[3]);	
	this->createIrSensor(Config::IR_SENSOR_PINS[15],Config::IR_SENSOR_NAMES[15],Config::IR_SENSOR_ANGLES[15]);	

	for (int i = 0; i < 3; i++)	{

		//this->createIrSensor(Config::IR_SENSOR_PINS[i], Config::IR_SENSOR_NAMES[i], 
		//							 Config::IR_SENSOR_ANGLES[i]);	
	}	

	for (int i = 0; i < Config::COUNT_IR_SENSOR; i++)	{
    

		// this->createIrSensor(Config::IR_SENSOR_PINS[i], Config::IR_SENSOR_NAMES[i], 
		// 							 Config::IR_SENSOR_ANGLES[i]);	
	}	
}

void SensorManager::createIrSensor(int p, String n, float a) {
	IrSensor* i = new IrSensor(p, n, a);
	app->getSensorList().addSensor(i);
}

IrSensor* SensorManager::getIrSensorByName(String n) {
	SensorBase* sensor = app->getSensorList().getSensorByName(n);
	String sensorType;
	sensorType = sensor->getType();
	//if(sensor_type != SensorBase::BUTTON){
	//	__throw_invalid_argument( "Sensor is not a button, dude!" );
	//}
	return static_cast<IrSensor*>(sensor);
}

IrSensor* SensorManager::getIrSensorByIndex(int i) {
	SensorBase* sensor = app->getSensorList().get(i);
	return static_cast<IrSensor*>(sensor);
}