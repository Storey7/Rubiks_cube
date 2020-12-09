#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	int dim = 3;
	float cubieSize = 50.0f;
	ofSetVerticalSync(true);
	cubeSize = cubieSize * dim;

	// this uses depth information for occlusion
	// rather than always drawing things on top of each other
	ofEnableDepthTest();

	// draw the ofBox outlines with some weight
	ofSetLineWidth(.3);

	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			for (int k = -1; k <= 1; k++) {
				//ofTranslate(x,y,z)
				//cube.push_back(Cubie(i*cubieSize, j * cubieSize, k * cubieSize, cubieSize));
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

	ofBackground(0, 0, 0);

	ofPushMatrix();
	cam.begin();
	ofScale(50);
	for (int i = 0; i < cube.size(); i++) {
		cube[i].draw();
	}
	
	cam.end();
	ofPopMatrix();

}

void ofApp::turnZ() {
	for (int i = 0; i < cube.size(); i++) {
		if (roundf(cube[i].pos.z) == 1)
		{
			cube[i].rotateZ();
			cube[i].pos.rotate(90, { 0,0,1 });
		}
	}
}

void ofApp::turnY() {
	for (int i = 0; i < cube.size(); i++) {
		if (roundf(cube[i].pos.y) == 1)
		{
			cube[i].pos.rotate(90, { 0,1,0});
			cube[i].rotateY();
		}
	}
}

void ofApp::turnX() {
	for (int i = 0; i < cube.size(); i++) {
		if (roundf(cube[i].pos.x) == 1)
		{
			cube[i].pos.rotate(90, { 1,0,0 });
			cube[i].rotateX();
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'z') {
		turnZ();
	}
	if (key == 'y') {
		turnY();
	}
	if (key == 'x') {
		turnX();
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
