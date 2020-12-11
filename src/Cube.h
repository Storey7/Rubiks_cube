#pragma once
#include "ofMain.h"
#include "Cubie.h"

class Cube {
public:
	Cube();
	~Cube();

	void setup(int _dim);
	void update();
	void draw();

	void turnZ(int index, int dir);
	void turnY(int index, int dir);
	void turnX(int index, int dir);

	void randomiseCube(int turns);
	void readAlgorithm(string path);
	
	void animateZ(int index, int dir, int _zAngle);
	void animateY(int index, int dir, int _yAngle);
	void animateX(int index, int dir, int _xAngle);

	void applyMove(char move);

	int dim;

	vector<Cubie> cube;
	float cubeSize;
};