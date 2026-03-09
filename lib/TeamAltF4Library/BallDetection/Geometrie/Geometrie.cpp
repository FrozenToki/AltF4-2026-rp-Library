#include "BallDetection/Geometrie/Geometrie.h"
#include "Geometrie.h"

Geometrie::Geometrie(Application* a) : app(a) {}

std::tuple<float, float> Geometrie::vectorToAngle(Vector v){
	float strength;
	strength = std::sqrt(v.getX() * v.getX() + v.getY() * v.getY());
	 
	float angle;
	angle = std::atan2(v.getY(), v.getX());
	//if(angle < 0) {
	//	angle += 360.0f;
	//}
	return std::make_tuple(angle, strength);
} 

/**
 * Vektor(x/y) aus Angle und Strength
 */
Vector Geometrie::angleToVector(float angle, float strength) {
	float x = cos(angleToRad(angle)) * strength;
	float y = sin(angleToRad(angle)) * strength;
	return Vector(x,y);
}

float Geometrie::radToAngle(float rad) {
	float angle = rad * 180 / PI;
	return angle;
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

Vector Geometrie::addVectors(const Vector& vec1, const Vector& vec2, const Vector& vec3, const Vector& vec4,const Vector& vec5) {

	float x = (vec1.getX() + vec2.getX() + vec3.getX() + vec4.getX() + vec5.getX()) / 5;
	float y = (vec1.getY() + vec2.getY() + vec3.getY() + vec4.getY() + vec5.getY()) / 5;

	return Vector(x, y);
}
