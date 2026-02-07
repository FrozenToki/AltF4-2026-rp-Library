#include "SensorManager.h"
#include "app/Application.h"

SensorManager::SensorManager(Application* a) : app(a) {

	for (int i = 0; i < Config::COUNT_IR_SENSOR; i++)	{
    

		 this->createIrSensor(Config::IR_SENSOR_PINS[i], Config::IR_SENSOR_NAMES[i], 
		 							 Config::IR_SENSOR_ANGLES[i]);	
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

IrSensor *SensorManager::getIrSensorByAngle(float angle) {
	SensorBase* sensor = app->getSensorList().getSensorByAngle(angle);
	return static_cast<IrSensor*>(sensor);
}
