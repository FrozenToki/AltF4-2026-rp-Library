#include "BallPositionReader.h"
#include "app/Application.h"

BallPositionReader::BallPositionReader(Application* a) : app(a) {
	for (int i = 0; i < Config::COUNT_IR_SENSOR; i++){
		irSensList[i] = app->getSensorManager().getIrSensorByIndex(i);
	}
	valueList.resize(Config::COUNT_IR_SENSOR);

}

void BallPositionReader::setValues() {
	for (int i = 0; i < Config::COUNT_IR_SENSOR; i++) {
		valueList.at(i)  = irSensList[i]->getCalculatedValue();
	}
}

void BallPositionReader::setHighestSensor() {

	
	mean = app->getGeometrie().getMean(valueList);

	hightestSensors.clear();

	for (int i = 0; i < Config::COUNT_IR_SENSOR; i++) {
		if (irSensList[i]->getCalculatedValue() >= mean) {
			hightestSensors.push_back(irSensList[i]);
		}
	}
}

float BallPositionReader::getMean() {
	return mean;
}

std::vector<IrSensor*> BallPositionReader::getHighestSensor() {
	return hightestSensors;
}

void BallPositionReader::setHighestSensVec() {
	for (size_t i = 0; i < hightestSensors.size(); i++) {
		hightestSensors[i]->setVector(app->getGeometrie().angleToVector(hightestSensors[i]->getAngle(), 
																	hightestSensors[i]->getCalculatedValue()));
	}
}

void BallPositionReader::addHighestSensVec() {
	
	ballVector = hightestSensors[0]->getVector();

	for (size_t i = 1; i < hightestSensors.size(); i++) {
		ballVector = app->getGeometrie().addVectors(hightestSensors[i]->getVector(), ballVector);
	}

}

Vector BallPositionReader::getBallVector(){
	return ballVector;
}

std::vector<float> BallPositionReader::getValues() {
	return valueList;
}