#pragma once
#include <Arduino.h>

class Vector {

private:
	float x;
	float y;
public:
  Vector();
	Vector(float x, float y);
	float getX() const;
	float getY() const;
	void setX(float xValue);
	void setY(float yValue);
};