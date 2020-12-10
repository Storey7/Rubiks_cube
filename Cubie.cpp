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
	angle = 0;

	int length = 1;
	box.set(length);

	//These were set backwards nad may not correspond to their names. They LOOK right though. 
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

void Cubie::rotate(int dir, ofVec3f axis) {
	box.rotateDeg(dir * 90, axis);
	pos.rotate(dir * 90, axis);
}

void Cubie::animateRotationZ(int dir)
{
	while (angle <= 90) {
		box.rotateDeg(dir*.1, { 0,0,1 });
		angle += .1;

		if (angle > 90) {
			box.rotateDeg(-dir * .1, { 0,0,1 });
			break;
		}
	}
}

