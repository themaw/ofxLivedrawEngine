#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	// main window setup
	ofSetFrameRate(60);
	ofBackground(0);
	ofSetLogLevel(OF_LOG_NOTICE);
    livedraw.setup();
}

//--------------------------------------------------------------
void testApp::update(){
    livedraw.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    livedraw.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed (int key){
	if(key == ' ') {
		ofToggleFullscreen();   
    }
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    livedraw.windowResized(w,h);
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo) {
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg) {

}
