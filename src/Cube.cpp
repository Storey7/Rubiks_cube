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
					(i == 0 && j == 0 && k == 0)) {

					//only render outer cubies
					cube.push_back(Cubie(i, j, k));
				}
			}
		}
	}

	for (int i = 0; i < cube.size(); i++) {
		cube[i].setup();
	}
	
	moving = -1;
}


void Cube::update()
{ 
	switch(moving){
	case -1:
		//Hold until ready
		break;
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
	ifstream myfile;
	string line;
	vector<string> inputVector;

	myfile.open(path);

	int count = 0;

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			inputVector.push_back(line);
		}
		myfile.close();
	}
	else cout << "Unable to open file " << path << endl;

	for (string line : inputVector)
	{
		stringstream ss(line);
		while (ss.good())
		{
			string move;
			getline(ss, move, ' ');
			notationToKeyboard(move);
		}
	}
}

void Cube::getState() 
{
	//TODO
	for (int i = 0; i < cube.size(); i++) {
		cube[i];
	}
}

void Cube::notationToKeyboard(string moveNotation)
{
	//Convention for typing was lowercase == clockwise. Hence this mess. 
	if (moveNotation.compare("F") == 0) {
		movesQueue.push_back('f');
	}
	else if (moveNotation.compare("F'") == 0) {
		movesQueue.push_back('F');
	}
	else if (moveNotation.compare("F2") == 0) {
		movesQueue.push_back('f');
		movesQueue.push_back('f');
	}

	else if (moveNotation.compare("B") == 0) {
		movesQueue.push_back('b');
	}
	else if (moveNotation.compare("B'") == 0) {
		movesQueue.push_back('B');
	}
	else if (moveNotation.compare("B2") == 0) {
		movesQueue.push_back('b');
		movesQueue.push_back('b');
	}

	else if (moveNotation.compare("R") == 0) {
		movesQueue.push_back('r');
	}
	else if (moveNotation.compare("R'") == 0) {
		movesQueue.push_back('R');
	}
	else if (moveNotation.compare("R2") == 0) {
		movesQueue.push_back('r');
		movesQueue.push_back('r');
	}

	else if (moveNotation.compare("L") == 0) {
		movesQueue.push_back('l');
	}
	else if (moveNotation.compare("L'") == 0) {
		movesQueue.push_back('L');
	}
	else if (moveNotation.compare("L2") == 0) {
		movesQueue.push_back('l');
		movesQueue.push_back('l');
	}

	else if (moveNotation.compare("U") == 0) {
		movesQueue.push_back('u');
	}
	else if (moveNotation.compare("U'") == 0) {
		movesQueue.push_back('U');
	}
	else if (moveNotation.compare("U2") == 0) {
		movesQueue.push_back('u');
		movesQueue.push_back('u');
	}

	else if (moveNotation.compare("D") == 0) {
		movesQueue.push_back('d');
	}
	else if (moveNotation.compare("D'") == 0) {
		movesQueue.push_back('D');
	}
	else if (moveNotation.compare("D2") == 0) {
		movesQueue.push_back('d');
		movesQueue.push_back('d');
	}
	else {
		cout << "Move not recognised : " << moveNotation << endl;
	}
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
