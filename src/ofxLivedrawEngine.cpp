
#include "ofxLivedrawEngine.h"

//--------------------------------------------------------------
ofxLivedrawEngine::ofxLivedrawEngine() {
}

//--------------------------------------------------------------
ofxLivedrawEngine::~ofxLivedrawEngine() {
    delete oscRouter;
    delete assetManager;
    delete effectsManager;
    
//    delete canvasLayerManager;
    delete canvas;
    
    delete sessionManager;
}

//--------------------------------------------------------------
void ofxLivedrawEngine::setup() {
    
    oscRouter     = new ofxOscRouter();
    oscRouter->setup("/livedraw", OSC_PORT);
    oscRouter->addOscNodeAlias("/l");
    oscRouter->addOscNodeAlias("/ld");

    assetManager  = new AssetManager();
    assetManager->setEngine(this);
    oscRouter->addOscChild(assetManager);
    
    effectsManager= new EffectsManager();
    effectsManager->setEngine(this);
    oscRouter->addOscChild(effectsManager);
    
    canvas        = new CanvasRenderer();
    canvas->setEngine(this);
    oscRouter->addOscChild(canvas);
    
    sessionManager = new SessionManager();
    sessionManager->setEngine(this);
    oscRouter->addOscChild(sessionManager); 
    
}

//--------------------------------------------------------------
void ofxLivedrawEngine::update() {

    // run asset manager updates (look for new files, etc)
    assetManager->update();

    // updated effects
    effectsManager->update();

    // canvas gets updated
    canvas->update();

    // session manager
    sessionManager->update();
    
}

//--------------------------------------------------------------
void ofxLivedrawEngine::draw() {
    ofSetColor(255,0,0);
    ofFill();
    ofRect(0,0, 300,300);
    
    canvas->render(); // accumulate everything onto the fbo.
    // here is where we can do the transformations before projection
    canvas->draw();
}

//--------------------------------------------------------------
void ofxLivedrawEngine::windowResized(int w, int h) {
    canvas->resize(w,h);
}

//--------------------------------------------------------------
ofxOscRouter* ofxLivedrawEngine::getOscRouter() {
    return oscRouter;
}
//--------------------------------------------------------------
AssetManager* ofxLivedrawEngine::getAssetManager() {
    return assetManager;
}
//--------------------------------------------------------------
EffectsManager* ofxLivedrawEngine::getEffectsManager() {
    return effectsManager;
}
//--------------------------------------------------------------
CanvasLayerManager* ofxLivedrawEngine::getCanvasLayerManager() {
    return canvas->getCanvasLayerManager();
}
//--------------------------------------------------------------
CanvasRenderer* ofxLivedrawEngine::getCanvasRenderer() {
    return canvas;
}
//--------------------------------------------------------------
SessionManager* ofxLivedrawEngine::getSessionManager() {
    return sessionManager;
}

