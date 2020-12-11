#include "Cube.h"

Cube::Cube()
{	
}

Cube::~Cube()
{
}

void Cube::setup(int _dim)
{
	dim = _dim;
	assert(dim % 2 == 1);

	cubeSize = floor(dim / 2.0);

	//Only able to build odd number cubes for now. 
	for (int i = -cubeSize; i <= cubeSize; i++) {
		for (int j = -cubeSize; j <= cubeSize; j++) {
			for (int k = -cubeSize; k <= cubeSize; k++) {
				if (abs(i) == cubeSize ||
					abs(j) == cubeSize ||
					abs(k) == cubeSize ||
					(i == 0 && j == 0 && k == 0))

					//only render outer cubies
					cube.push_back(Cubie(i, j, k));
			}
		}
	}

	for (int i = 0; i < cube.size(); i++) {
		cube[i].setup();
	}
	
	moving = 0;
}


void Cube::update()
{ 
	switch(moving){
		case 0:
			if (movesQueue.size() > 0) {
				char move = movesQueue.front();
				movesQueue.pop_front();
				applyMove(move);
			}
			break;
		case 1:
			for (int i = 0; i < cube.size(); i++) {
				if (cube[i].pos.x == 0 && cube[i].pos.y == 0) {
					if (cube[i].zAngle % 90 != 0) {
						animateZ(cube[i].pos.z, cube[i].zAngle, cube[i].currentDir);
						break;
					}
					moving = 0;
				}
			}
			break;
		case 2:
			for (int i = 0; i < cube.size(); i++) {
				if (cube[i].pos.x == 0 && cube[i].pos.z == 0) {
					if (cube[i].yAngle % 90 != 0) {
						animateY(cube[i].pos.y, cube[i].yAngle, cube[i].currentDir);
						break;
					}
					moving = 0;
				}
			}
			break;
		case 3:
			for (int i = 0; i < cube.size(); i++) {
				if (cube[i].pos.y == 0 && cube[i].pos.z == 0) {
					if (cube[i].xAngle % 90 != 0) {
						animateX(cube[i].pos.x, cube[i].xAngle, cube[i].currentDir);
						break;
					}
					moving = 0;
				}
			}
			break;
		default:
			cout << "OH NO!" << endl;
			}
}

void Cube::draw()
{
	for (int i = 0; i < cube.size(); i++) {
		cube[i].draw();
	}
}

//This all needs to be refactored badly. Since I started with ortoganol only turns, the call stack is weird.
//Turns are "started off" using the turn{ZYX} methods, and then the update function repeatedly calls these animate functions to get the turn
//from 1-90 degrees. Not ideal. 
void Cube::animateZ(int index, int _zAngle, int dir) {
	int zAxis = _zAngle;
	int zModulo = zAxis % 90;

	if (zModulo != 0) {
		turnZ(index, dir);	
	}
}
void Cube::animateY(int index, int _yAngle, int dir) {
	int yAxis = _yAngle;
	int yModulo = yAxis % 90;

	if (yModulo != 0) {
		turnY(index, dir);
	}
}
void Cube::animateX(int index, int _xAngle, int dir) {
	int xAxis = _xAngle;
	int xModulo = xAxis % 90;

	if (xModulo != 0) {
		turnX(index, dir);
	}
}



void Cube::turnZ(int index, int dir)
{
	
	for (int i = 0; i < cube.size(); i++) {
		if (roundf(cube[i].pos.z) == index)
		{
			moving = 1;
			cube[i].currentDir = dir;
			cube[i].rotate(dir, { 0,0,1 }, 5);
		}
	}
}

void Cube::turnY(int index, int dir)
{
	for (int i = 0; i < cube.size(); i++) {
		if (roundf(cube[i].pos.y) == index)
		{
			moving = 2;
			cube[i].currentDir = dir;
			cube[i].rotate(dir, { 0,1,0 }, 5);
		}
	}
}

void Cube::turnX(int index, int dir)
{
	for (int i = 0; i < cube.size(); i++) {
		if (roundf(cube[i].pos.x) == index)
		{
			moving = 3;
			cube[i].currentDir = dir;
			cube[i].rotate(dir, { 1,0,0 }, 5);
		}
	}
}

void Cube::randomiseCube(int turns)
{
	char moves[] = { 'u', 'U', 'l', 'L', 'r', 'R', 'd', 'D', 'f', 'F', 'b', 'B' };
	for (int i = 0; i < turns; i++)
	{
		int index = floor(ofRandom(0, 12));
		char move = moves[index];
		movesQueue.push_back(move);
		//applyMove(move);
	}
}

void Cube::readAlgorithm(string path)
{
	//TODO
}

void Cube::applyMove(char move)
{
	switch (move) {
	case 'F':
		turnZ(1, 1);
		break;
	case 'f':
		turnZ(1, -1);
		break;
	case 'B':
		turnZ(-1, -1);
		break;
	case 'b':
		turnZ(-1, 1);
		break;

	case 'U':
		turnY(1, 1);
		break;
	case 'u':
		turnY(1, -1);
		break;
	case 'D':
		turnY(-1, -1);
		break;
	case 'd':
		turnY(-1, 1);
		break;

	case 'L':
		turnX(-1, -1);
		break;
	case 'l':
		turnX(-1, 1);
		break;
	case 'R':
		turnX(1, 1);
		break;
	case 'r':
		turnX(1, -1);
		break;

	//These break the animation as they move the centres. 
	/*case 'm':
		turnX(0, 1);
		break;
	case 'M':
		turnX(0, -1);
		break;*/
	}
}
