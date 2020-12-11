#pragma once
#include "ofMain.h"

class Cubie {
public:
	Cubie(float x, float y, float z);
	~Cubie();

	void setup();
	void update();
	void draw();

	void rotate(int dir, ofVec3f axis, int angle);

	void animateRotation(int dir, ofVec3f axis);
	
	int angle;
	int currentAngle;
	int currentDir;
	int zAngle;
	int yAngle;
	int xAngle;

	ofVec3f pos;

	ofBoxPrimitive box;

};