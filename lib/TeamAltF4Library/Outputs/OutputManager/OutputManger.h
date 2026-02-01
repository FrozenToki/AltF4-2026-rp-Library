#pragma once
#include "Arduino.h"
#include "Outputs/OutputList/OutputList.h"
#include "Outputs/OutputBase/Teensy/Teensy.h"


// forward declaration
class Application;

// Used to create all the outputs.
class OutputManager {
private:
	Application* app;
public:
	OutputManager(Application* a);

	// Creates an instance of the led class and add's that to the outputlist.
	void createTeensy(UART& s, String n);
	// Searches all sensors for the given name and returns it, 
	// as an instance of the led class. 
	Teensy* getTeensyByName(String n);

};
