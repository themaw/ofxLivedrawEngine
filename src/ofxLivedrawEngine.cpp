
#include "ofxLivedrawEngine.h"

//--------------------------------------------------------------
ofxLivedrawEngine::ofxLivedrawEngine() {
    
}

//--------------------------------------------------------------
ofxLivedrawEngine::~ofxLivedrawEngine() {
    
}


//--------------------------------------------------------------
void ofxLivedrawEngine::setup() {
    guiManager.setup();
    sessionManager.setup();
    assetManager.setup();
	effectsManager.setup();
    
    canvas.setup();
    canvas.setAssetManager(&assetManager);
    //canvas.setEffectsManager(&effectsManager);
    
	oscManager.setup(OSC_PORT);
    oscManager.addOscChild(&canvas);
    oscManager.addOscChild(&effectsManager); 
    oscManager.addOscChild(&sessionManager); 

}

//--------------------------------------------------------------
void ofxLivedrawEngine::update() {
    // OSC gets checked first
    oscManager.update();  
    
    // session manager
    sessionManager.update();
    
    // run asset manager updates (look for new files, etc)
    assetManager.update();
    
    // updated effects
    effectsManager.update();
	
    // canvas gets updated
    canvas.update();
    
    // GUI gets checked last to reflect any changes in state
    guiManager.update();

}

void ofxLivedrawEngine::draw() {
    
    
    ofSetColor(255,0,0);
    ofFill();
    ofRect(0,0, 300,300);
    
    
    canvas.render(); // accumulate everything onto the fbo.
    
    // here is where we can do the transformations before projection
    canvas.draw();
    
    // draw the gui
    guiManager.draw();
    
    ofSetColor(255);

}