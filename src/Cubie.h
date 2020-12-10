#pragma once
#include "ofMain.h"

class Cubie {
public:
	Cubie(float x, float y, float z);
	~Cubie();

	void setup();
	void update();
	void draw();

	void rotate(int dir, ofVec3f axis);

	void animateRotationZ(int dir);

	float angle;
	ofVec3f pos;
	ofMatrix3x3 matrix;

	ofBoxPrimitive box;

};