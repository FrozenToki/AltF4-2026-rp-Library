#include "BallDetection/Vector/Vector.h"

Vector::Vector() : x(0), y(0) {}
Vector::Vector(float x, float y) : x(x), y(y) {}


float Vector::getX() const {
	return x;
}

float Vector::getY() const {
	return y;
}

void Vector::setX(float xValue) {
	x = xValue;
} 

void Vector::setY(float yValue) {
	y = yValue;
}