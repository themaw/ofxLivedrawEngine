
#include "ofxLivedrawEngine.h"

//--------------------------------------------------------------
ofxLivedrawEngine::ofxLivedrawEngine() {
}

//--------------------------------------------------------------
ofxLivedrawEngine::~ofxLivedrawEngine() {
}

//--------------------------------------------------------------
void ofxLivedrawEngine::setup() {
    sessionManager.setup();
    assetManager.setup();
	effectsManager.setup();
    
    canvas.setup();
    canvas.setAssetManager(&assetManager);
    //canvas.setEffectsManager(&effectsManager);
    
    oscRouter.setup("/livedraw", OSC_PORT);
    oscRouter.addOscChild(&canvas);
    oscRouter.addOscChild(&effectsManager); 
    oscRouter.addOscChild(&sessionManager); 
}

//--------------------------------------------------------------
void ofxLivedrawEngine::update() {

    // session manager
    sessionManager.update();
    
    // run asset manager updates (look for new files, etc)
    assetManager.update();
    
    // updated effects
    effectsManager.update();
	
    // canvas gets updated
    canvas.update();
    
}

void ofxLivedrawEngine::draw() {
    ofSetColor(255,0,0);
    ofFill();
    ofRect(0,0, 300,300);
    
    canvas.render(); // accumulate everything onto the fbo.
    // here is where we can do the transformations before projection
    canvas.draw();
}


void ofxLivedrawEngine::windowResized(int w, int h) {
    canvas.resize(w,h);
}
