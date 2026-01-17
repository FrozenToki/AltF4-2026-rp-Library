#pragma once 
#include <Arduino.h>
#include "Outputs/OutputBase/Outputs.h"

class Teensy : public OutputBase {
private: 
	UART* serialConnection;
public: 
	Teensy(UART* serial, String n);
	void send(String text);
};