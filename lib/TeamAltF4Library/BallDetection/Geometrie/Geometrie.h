#pragma once 
#include <Arduino.h>
#include "BallDetection/Vector/Vector.h"
#include <vector>

// forward declaration
class Application;

class Geometrie {
private: 
	Application* app;
public:
	Geometrie(Application* a);

	std::tuple<float, float> vectorToAngle(Vector v);

	Vector angleToVector(float angle, float strength);
	float radToAngle(float rad);
	float angleToRad(float angle);
	float getMean(std::vector<float> ar);
	Vector addVectors(const Vector& vec1, const Vector& vec2, const Vector& vec3, const Vector& vec4,const Vector& vec5);
};