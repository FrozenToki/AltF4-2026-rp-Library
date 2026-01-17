#include "OutputManger.h"
#include "app/Application.h"

OutputManager::OutputManager(Application* a) : app(a) {}

void OutputManager::createTeensy(UART* s, String n) {
	Teensy* t = new Teensy(s, n); 
	app->getOutputList().addOutput(t);
}

Teensy* OutputManager::getTeensyByName(String n) {
	OutputBase* output = app->getOutputList().getOutputByName(n);
	String outputType;
	outputType = output->getType();
	//if(sensor_type != SensorBase::BUTTON){
	//	__throw_invalid_argument( "Sensor is not a button, dude!" );
	//}
	return static_cast<Teensy*>(output);
}
