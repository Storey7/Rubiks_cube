#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	int dim = 3;
	assert(dim % 2 == 1);

	ofSetVerticalSync(true);
	cubeSize = floor(dim / 2.0);

	// this uses depth information for occlusion
	// rather than always drawing things on top of each other
	ofEnableDepthTest();

	// draw the ofBox outlines with some weight
	ofSetLineWidth(.3);

	//Only able to build odd number cubes for now. 
	for (int i = -cubeSize; i <= cubeSize; i++) {
		for (int j = -cubeSize; j <= cubeSize; j++) {
			for (int k = -cubeSize; k <= cubeSize; k++) {
				if(abs(i) == cubeSize || abs(j) == cubeSize || abs(k) == cubeSize)
					//only render outer cubies
					cube.push_back(Cubie(i, j, k));
			}
		}
	}

	for (int i = 0; i < cube.size(); i++) {
		cube[i].setup();
	}
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofBackground(120);

	ofPushMatrix();
	cam.begin();
	ofScale(50);
	for (int i = 0; i < cube.size(); i++) {
		cube[i].draw();
	}
	
	cam.end();
	ofPopMatrix();

}

void ofApp::turnZ(int index, int dir) {
	for (int i = 0; i < cube.size(); i++) {
		if (roundf(cube[i].pos.z) == index)
		{
			cube[i].rotate(dir, { 0,0,1 });
			//cube[i].animateRotation(dir, { 0,0,1 });
		}
	}
}

void ofApp::turnY(int index, int dir) {
	for (int i = 0; i < cube.size(); i++) {
		if (roundf(cube[i].pos.y) == index)
		{
			cube[i].rotate(dir, { 0,1,0 });
		}
	}
}

void ofApp::turnX(int index, int dir) {
	for (int i = 0; i < cube.size(); i++) {
		if (roundf(cube[i].pos.x) == index)
		{
			cube[i].rotate(dir, { 1,0,0 });
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'F') {
		turnZ(1,1);
	}
	if (key == 'f') {
		turnZ(1, -1);
	}
	if (key == 'B') {
		turnZ(-1, -1);
	}
	if (key == 'b') {
		turnZ(-1, 1);
	}

	if (key == 'U') {
		turnY(1,1);
	}
	if (key == 'u') {
		turnY(1, -1);
	}
	if (key == 'D') {
		turnY(-1, -1);
	}
	if (key == 'd') {
		turnY(-1, 1);
	}

	if (key == 'L') {
		turnX(-1,-1);
	}
	if (key == 'l') {
		turnX(-1, 1);
	}
	if (key == 'R') {
		turnX(1, 1);
	}
	if (key == 'r') {
		turnX(1, -1);
	}

	if (key == 'm') {
		turnX(0, 1);
	}
	if (key == 'M') {
		turnX(0, -1);
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
