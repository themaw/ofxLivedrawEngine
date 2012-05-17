
#include "ofxLivedrawEngine.h"

//--------------------------------------------------------------
ofxLivedrawEngine::ofxLivedrawEngine() {
}

//--------------------------------------------------------------
ofxLivedrawEngine::~ofxLivedrawEngine() {
    delete bufferManager;
    delete oscRouter;
    delete assetManager;
    delete effectsManager;
    
    delete canvasLayerManager;
    delete canvas;
    
    delete sessionManager;
}

//--------------------------------------------------------------
void ofxLivedrawEngine::setup() {
    
    bufferManager = new BufferManager();
    oscRouter     = new ofxOscRouter();
    oscRouter->setup("/livedraw", OSC_PORT);

    assetManager  = new AssetManager();
    assetManager->setup();

    effectsManager= new EffectsManager();
    effectsManager->setup();
    
    canvas        = new CanvasRenderer();
    canvas->setup();

    canvasLayerManager = new CanvasLayerManager();
    
    sessionManager = new SessionManager();
    sessionManager->setup();
    
    //
    oscRouter->addOscChild(canvas);
    oscRouter->addOscChild(effectsManager); 
    oscRouter->addOscChild(sessionManager); 
}

//--------------------------------------------------------------
void ofxLivedrawEngine::update() {

    // session manager
    sessionManager->update();
    
    // run asset manager updates (look for new files, etc)
    assetManager->update();
    
    // updated effects
    effectsManager->update();
	
    // canvas gets updated
    canvas->update();
    
}

void ofxLivedrawEngine::draw() {
    ofSetColor(255,0,0);
    ofFill();
    ofRect(0,0, 300,300);
    
    canvas->render(); // accumulate everything onto the fbo.
    // here is where we can do the transformations before projection
    canvas->draw();
}


void ofxLivedrawEngine::windowResized(int w, int h) {
    canvas->resize(w,h);
}
