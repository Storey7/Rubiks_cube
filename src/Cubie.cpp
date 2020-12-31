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
	currentAngle = 0;
	zAngle = 0;
	yAngle = 0;
	xAngle = 0;

	int length = 1;
	box.set(length*.95);
	borderBox.set(length);
	borderBox.setMode(ofPrimitiveMode::OF_PRIMITIVE_LINES);

	//These were set backwards and may not correspond to their names. They LOOK right though. 
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

	ofSetLineWidth(2);
	ofTranslate(pos);
	//ofFill();
	box.draw();
	

	//box.drawWireframe();
	ofPopMatrix();
}

void Cubie::rotate(int dir, ofVec3f axis, int angle) {
	currentAngle = (currentAngle + dir*angle) % 360;
	//currentAngle = (currentAngle + angle) % 360;
	
	if (axis == ofVec3f{0, 0, 1}) {
		zAngle = currentAngle;
	}
	else if (axis == ofVec3f{0, 1, 0}) {
		yAngle = currentAngle;
	}
	else if (axis == ofVec3f{1, 0, 0}) {
		xAngle = currentAngle;
	}
	
	box.rotateDeg(dir * angle, axis);
	pos.rotate(dir * angle, axis);
}


void Cubie::animateRotation(int dir, ofVec3f axis)
{

}

