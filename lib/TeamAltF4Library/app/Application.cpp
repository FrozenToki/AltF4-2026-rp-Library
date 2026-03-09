#include "Application.h"

Application::Application() : sensorManager(this), sensorList(this), 
	errorMessages(this), irSensorReader(this),
	ballPositionReader(this), geometrie(this) {} 

SensorList& Application::getSensorList() {
	return sensorList;
}

SensorManager& Application::getSensorManager() {
	return sensorManager;
}

Config& Application::getConfig() {
	return config;
}

ErrorMessages& Application::getErrorMessage() {
	return errorMessages;
}

IrSensorReader& Application::getIrSensorReader() {
	return irSensorReader;
}

BallPositionReader& Application::getBallPositionReader() {
	return ballPositionReader;
}

Geometrie& Application::getGeometrie() {
	return geometrie;
}