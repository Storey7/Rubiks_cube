#include "Cubie.h"

Cubie::Cubie(float x, float y, float z)
{
	pos = {x,y,z};
}

Cubie::~Cubie()
{
}

void Cubie::setup()
{
	int length = 1;
	box.set(length);
	box.setSideColor(box.SIDE_FRONT, ofColor::green);
	box.setSideColor(box.SIDE_LEFT, ofColor::orange);
	box.setSideColor(box.SIDE_RIGHT, ofColor::red);
	box.setSideColor(box.SIDE_TOP, ofColor::yellow);
	box.setSideColor(box.SIDE_BACK, ofColor::blue);
	box.setSideColor(box.SIDE_BOTTOM, ofColor::white);
}

void Cubie::update()
{
}

void Cubie::draw()
{
	ofPushMatrix();

	ofSetLineWidth(1);
	ofTranslate(pos);
	box.draw();
	//box.drawWireframe();
	ofPopMatrix();
}

void Cubie::rotateZ()
{
	ofPushMatrix();
	box.rotateDeg(90, {0,0,1});
	ofPopMatrix();
}

void Cubie::rotateY()
{
	ofPushMatrix();
	box.rotateDeg(90, { 0,1,0 });
	ofPopMatrix();
}

void Cubie::rotateX()
{
	ofPushMatrix();
	box.rotateDeg(90, { 1,0,0 });
	ofPopMatrix();
}

