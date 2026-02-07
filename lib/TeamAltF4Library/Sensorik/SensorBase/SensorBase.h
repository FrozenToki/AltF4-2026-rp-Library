#pragma once
#include <Arduino.h>

// Used to create all
class SensorBase {
protected:
	float value;
	String name;
	String type;
private:
	static int sensorCount;
public:
	SensorBase(String n);

  static String IR_SENS;

	int getPin() const;
	String getName() const;
	String getType() const;

	int& getPinRef();
	String& getNameRef();

 	virtual float getAngle() = 0;

	virtual void update() = 0;
	virtual float getValue() = 0;
	
	// Updates the sensor and returns its raw data.
	float readSensor();

	SensorBase();
};





