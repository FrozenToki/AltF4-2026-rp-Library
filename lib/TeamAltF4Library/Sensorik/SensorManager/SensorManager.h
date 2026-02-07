#pragma once
#include "Arduino.h"
#include "Config/Config.h"
#include "Sensorik/SensorBase/IrSensors/IrSensors.h"
#include "Sensorik/SensorList/SensorList.h"

// forward declaration
class Application; 

// Used to create all the sensors.
class SensorManager {
private:
	Application* app;

public:
	SensorManager(Application* a);

	// Creates an instance of the button class and add's that to the sensorlist.
	void createIrSensor(int p, String n, float a);
	// Searches all sensors for the given name and returns it, 
	// as an instance of the button class.
	IrSensor* getIrSensorByName(String n);
	IrSensor* getIrSensorByIndex(int i);
	IrSensor* getIrSensorByAngle(float angle);
};

