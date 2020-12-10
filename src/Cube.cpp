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
				if (abs(i) == cubeSize || abs(j) == cubeSize || abs(k) == cubeSize)
					//only render outer cubies
					cube.push_back(Cubie(i, j, k));
			}
		}
	}

	for (int i = 0; i < cube.size(); i++) {
		cube[i].setup();
	}
}

void Cube::update()
{
}

void Cube::draw()
{
	for (int i = 0; i < cube.size(); i++) {
		cube[i].draw();
	}
}

void Cube::turnZ(int index, int dir)
{
	for (int i = 0; i < cube.size(); i++) {
		if (roundf(cube[i].pos.z) == index)
		{
			cube[i].rotate(dir, { 0,0,1 });
		}
	}
}

void Cube::turnY(int index, int dir)
{
	for (int i = 0; i < cube.size(); i++) {
		if (roundf(cube[i].pos.y) == index)
		{
			cube[i].rotate(dir, { 0,1,0 });
		}
	}
}

void Cube::turnX(int index, int dir)
{
	for (int i = 0; i < cube.size(); i++) {
		if (roundf(cube[i].pos.x) == index)
		{
			cube[i].rotate(dir, { 1,0,0 });
		}
	}
}

void Cube::randomiseCube(int turns)
{
	char moves[] = { 'u', 'U', 'l', 'L', 'r', 'R', 'd', 'D', 'f', 'F', 'b', 'B' };
	for (int i = 0; i < turns; i++)
	{
		int index = floor(ofRandom(0, 12));
		applyMove(moves[index]);
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

	case 'm':
		turnX(0, 1);
		break;
	case 'M':
		turnX(0, -1);
		break;
	}
}
