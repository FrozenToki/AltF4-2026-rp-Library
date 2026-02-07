#include "IrSensorReader.h"
#include "app/Application.h"

IrSensorReader::IrSensorReader(Application* a) : app(a) {
	for (int i = 0; i < Config::COUNT_IR_SENSOR; i++){
		irSensList[i] = app->getSensorManager().getIrSensorByIndex(i);
	}
}
/*
* Kommentar
*/
void IrSensorReader::readAll(int ticks, bool useTimeMode, long unsigned int timeInMicSec) {
	for (int s = 0; s < Config::COUNT_IR_SENSOR; s++) {
		irSensList[s]->resetValue();
	}
	
	if (useTimeMode) {
		unsigned long start = micros(); 
		while (micros() - start < timeInMicSec) { 
			for (int s = 0; s < Config::COUNT_IR_SENSOR; s++) { 
				irSensList[s]->update(); 
			}
		}
		lastReadingTime = timeInMicSec;
	}	
	else {
		unsigned long start = micros();
		for (int i = 0; i < ticks; i++) {
			for (int s = 0; s < Config::COUNT_IR_SENSOR; s++) {
				irSensList[s]->update();
			}
		}
		lastReadingTime = micros() - start;
	}
}

float IrSensorReader::frequencyInMilSec(int timeInMicSec, float sensHits) {
	return sensHits / (timeInMicSec / 1000.0f);
}

void IrSensorReader::getAllValues(float array[]) {
	for (int i = 0; i < Config::COUNT_IR_SENSOR; i++) {
		array[i] = irSensList[i]->getCalculatedValue();
	}
}

/**
 * Werte in die Sensor Liste eintragen
 */
void IrSensorReader::setAll() {
	for (int i = 0; i < Config::COUNT_IR_SENSOR; i++) {
		irSensList[i]->setCalculatedValue(irSensList[i]->getValue()); 
	}
}

