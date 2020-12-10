#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetVerticalSync(true);
	ofSetWindowTitle("Rubiks Cube");

	// this uses depth information for occlusion
	// rather than always drawing things on top of each other
	ofEnableDepthTest();

	// draw the ofBox outlines with some weight
	ofSetLineWidth(.3);
	
	int dim = 3;
	cube.setup(dim);
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
	cube.draw();
	
	cam.end();
	ofPopMatrix();
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	cube.applyMove(key);
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
