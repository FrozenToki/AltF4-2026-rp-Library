#include "BallPositionReader.h"
#include "app/Application.h"

BallPositionReader::BallPositionReader(Application* a) : app(a) {
	for (int i = 0; i < Config::COUNT_IR_SENSOR; i++){
		irSensList[i] = app->getSensorManager().getIrSensorByIndex(i);
	}
	valueList.resize(Config::COUNT_IR_SENSOR);
	highSensValAvrg.resize(5);
	highSensAngleAvrg.resize(5);

	for (size_t i = 0; i < 5; i++) {
		highSensAngleAvrg[i] = new MovingAverage(Config::COUNT_MOVING_AVERAGE);
		highSensValAvrg[i] = new MovingAverage(Config::COUNT_MOVING_AVERAGE);
	}
}
/**
 * Werte aus SensorListe in die Werte Liste eintragen
 */
void BallPositionReader::setValues() {
	for (int i = 0; i < Config::COUNT_IR_SENSOR; i++) {
		valueList.at(i)  = irSensList[i]->getCalculatedValue();
	}
}

/**
 * Finde den Sensor mit dem höchsten Wert
 * und jeweils 2 links und rechts davon
 */
void BallPositionReader::setHighestSensor() {

	hightestSensors.clear();
	
	IrSensor* hightestSensor = irSensList[0];
	int highestSensorIndex=0;
	for (size_t i = 1; i < Config::COUNT_IR_SENSOR; i++) {
		if (hightestSensor->getCalculatedValue() <= irSensList[i]->getCalculatedValue()) {
			hightestSensor = irSensList[i];
	    highestSensorIndex = i;
		}
	}

	hightestSensors.push_back(hightestSensor);
	
	for (int i = 0; i < 2; i++) {
		int index = highestSensorIndex + (1 + i);
		if (index > 15 ) {
			index -= 16;
		}
		hightestSensors.push_back(app->getSensorManager().getIrSensorByIndex(index));	
	}
	
	for (int i = 0; i < 2; i++) {
		int index = highestSensorIndex - (1 + i);
		if (index < 0 ) {
			index += 16;
		}
		hightestSensors.push_back(app->getSensorManager().getIrSensorByIndex(index));	
	}


	//for (size_t i = 0; i < 5; i++) {
	//	highSensValAvrg[i]->newValue(hightestSensors[i]->getCalculatedValue());
	//	hightestSensors[i]->setCalculatedValue(highSensValAvrg[i]->getAverage());
	
	////	highSensAngleAvrg[i]->newValue(hightestSensors[i]->getAngle());
	////	hightestSensors[i]->setAvrgAngle(highSensAngleAvrg[i]->getAverage());
	//}
	
	
}

std::vector<IrSensor*> BallPositionReader::getHighestSensors() {
	return hightestSensors;
}

void BallPositionReader::setHighestSensVec() {
	for (size_t i = 0; i < hightestSensors.size(); i++) {
		hightestSensors[i]->setVector(app->getGeometrie().angleToVector(hightestSensors[i]->getAngle(), 
																	hightestSensors[i]->getCalculatedValue()));
	}
}

void BallPositionReader::addHighestSensVec() {	
	ballVector = app->getGeometrie().addVectors(hightestSensors[0]->getVector(), hightestSensors[1]->getVector(), hightestSensors[2]->getVector(), hightestSensors[3]->getVector(), hightestSensors[4]->getVector());

}

Vector BallPositionReader::getBallVector(){
	return ballVector;
}

std::vector<float> BallPositionReader::getValues() {
	return valueList;
}