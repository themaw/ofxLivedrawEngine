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

#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	// main window setup
	ofSetFrameRate(60);
	ofBackground(0);
	//ofSetLogLevel(OF_LOG_VERBOSE);
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
    } else if(key == 'a') {
//        AssetManager* man = livedraw.getAssetManager();
//        man->dump();
    } else if(key == 'b') {
//        LayerManager* man = livedraw.getLayerManager();
//        man->dump();
    } else if(key == 's') {
        int i = 0;
//        string s = livedraw.getOscRouter()->schemaToString(i);
//        cout << s << endl;
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
