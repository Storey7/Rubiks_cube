#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(120);

	ofSetVerticalSync(true);
	ofSetWindowTitle("Rubiks Cube");
	
	gui.setup();
	gui.add(zRotation.setup("Front rotation", "0"));
	gui.add(color.setup("color", ofColor(100, 100, 140), ofColor(0, 0), ofColor(255, 255)));
	gui.setTextColor(ofColor::white);
	
	int dim = 3;
	cube.setup(dim);
	//cube.randomiseCube(100);
	cube.readAlgorithm("../algs/moves_list.txt");
}

//--------------------------------------------------------------
void ofApp::update(){
	zRotation = ofToString(cube.cube[5].currentAngle);
	cube.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

	ofBackgroundGradient(ofColor::gray, color);
	ofEnableDepthTest();

	ofPushMatrix();
	cam.begin(); 
	ofFill();
	ofScale(50);
	cube.draw();
	
	ofNoFill();
	cam.end();
	ofPopMatrix();
	ofDisableDepthTest();

	gui.draw();
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == ' ')
		cube.moving = 0;
	cube.movesQueue.push_back(key);
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
