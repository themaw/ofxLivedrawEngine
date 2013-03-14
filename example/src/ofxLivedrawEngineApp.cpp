/*==============================================================================
 
 Copyright (c) 2010, 2011, 2012 Christopher Baker <http://christopherbaker.net>
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 
 ==============================================================================*/

#include "ofxLivedrawEngineApp.h"

//--------------------------------------------------------------
void ofxLivedrawEngineApp::setup(){
	// main window setup
	ofSetFrameRate(60);
	ofBackground(0);
	ofSetLogLevel(OF_LOG_VERBOSE);
//    ofLogToFile("ofxLivedrawLog.log");
    
    livedraw.setup();
    
}

//--------------------------------------------------------------
void ofxLivedrawEngineApp::update(){
    livedraw.update();
}

//--------------------------------------------------------------
void ofxLivedrawEngineApp::draw(){
    livedraw.draw();
}

//--------------------------------------------------------------
void ofxLivedrawEngineApp::keyPressed (int key){
	if(key == ' ') {
		ofToggleFullscreen();   
    } else if(key == 'a') {
//        AssetManager* man = livedraw.getAssetManager();
//        man->dump();
    } else if(key == 'b') {
//        LayerManager* man = livedraw.getLayerManager();
//        man->dump();
    } else if(key == 's') {
//        int i = 0;
//        string s = livedraw.getOscRouter()->schemaToString(i);
//        cout << s << endl;
    }
}

//--------------------------------------------------------------
void ofxLivedrawEngineApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofxLivedrawEngineApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofxLivedrawEngineApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void ofxLivedrawEngineApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofxLivedrawEngineApp::windowResized(int w, int h){
    livedraw.windowResized(w,h);
}

//--------------------------------------------------------------
void ofxLivedrawEngineApp::dragEvent(ofDragInfo dragInfo) {
    
}

//--------------------------------------------------------------
void ofxLivedrawEngineApp::gotMessage(ofMessage msg) {

}
