#pragma once
#include <Arduino.h>
#include "Sensorik/SensorBase/SensorBase.h"
#include "Sensorik/SensorManager/SensorManager.h"
#include "Sensorik/SensorList/SensorList.h"
#include "Outputs/OutputManager/OutputManger.h"
#include "Outputs/OutputList/OutputList.h"
#include "Config/Config.h"
#include "Debugging/Errors/ErrorMessages.h"
#include "BallDetection/IrSensorReader/IrSensorReader.h"
#include "BallDetection/BallPositionReader/BallPositionReader.h"
#include "BallDetection/Geometrie/Geometrie.h"


// Used to get acces to all the parts of the library from anywhere in the programm.
// It has instances of all the different main parts of the library.
class Application {
private:
	SensorManager sensorManager;
	SensorList sensorList;

	OutputManager outputManager;
	OutputList outputList;

	Config config;

	ErrorMessages errorMessages;

	IrSensorReader irSensorReader;

	BallPositionReader ballPositionReader;

	Geometrie geometrie;
public:
	SensorList& getSensorList();
	SensorManager& getSensorManager();
	
	OutputList& getOutputList();
	OutputManager& getOutputManager();

	Config& getConfig();

	ErrorMessages& getErrorMessage();

	IrSensorReader& getIrSensorReader();

	BallPositionReader& getBallPositionReader();

	Geometrie& getGeometrie();
	
	Application();
};
	
