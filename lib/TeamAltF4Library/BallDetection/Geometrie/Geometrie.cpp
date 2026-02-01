#include "BallDetection/Geometrie/Geometrie.h"
#include "Geometrie.h"

Geometrie::Geometrie(Application* a) : app(a) {}

Vector Geometrie::angleToVector(float angle, float strength) {
	float x = cos(angleToRad(angle) * strength);
	float y = sin(angleToRad(angle) * strength);
	return Vector(x,y);
}

float Geometrie::angleToRad(float angle) {
	float rad = (angle / 360) * 2 * PI;
	return rad;
}

float Geometrie::getMean(std::vector<float> ar) {
	float allArrayValues = 0.0f;
	for (size_t i = 0; i < ar.size(); i++) {
		allArrayValues += ar[i];
	}
	float mean = allArrayValues / ar.size();
	return mean;
}

Vector Geometrie::addVectors(const Vector& vec1, const Vector& vec2) {

	float x = (vec1.getX() + vec2.getX()) * 0.5;
	float y = (vec1.getY() + vec2.getY()) * 0.5;

	return Vector(x, y);
}
