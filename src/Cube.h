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

	void applyMove(char move);

	int dim;

	vector<Cubie> cube;
	float cubeSize;
};