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

#include "ofxLivedrawEngine.h"

//--------------------------------------------------------------
ofxLivedrawEngine::ofxLivedrawEngine() {
}

//--------------------------------------------------------------
ofxLivedrawEngine::~ofxLivedrawEngine() {
    // ofPtr magic.
}

//--------------------------------------------------------------
void ofxLivedrawEngine::setup() {
    
    oscRouter.setup("livedraw", OSC_PORT);
    oscRouter.addOscNodeAlias("l");
    oscRouter.addOscNodeAlias("ld");

    //  assetManager.setEngine(this);
    oscRouter.addOscChild(&assetManager);
    
    //  layerManager.setEngine(this);
    oscRouter.addOscChild(&layerManager);
    
    //  canvas.setEngine(this);
    oscRouter.addOscChild(&canvas);
    
//    effectsManager.setEngine(this);
//    oscRouter.addOscChild(&effectsManager);

//    sessionManager.setEngine(this);
//    oscRouter.addOscChild(&sessionManager); 
    
}

//--------------------------------------------------------------
void ofxLivedrawEngine::update() {

    oscRouter.update();
    
    // run asset manager updates (look for new files, etc)
    assetManager.update();

    // update layer manager
    layerManager.update();
    
    // update renderer
    canvas.update();
    
    // updated effects
    // effectsManager.update();

    // session manager
    // sessionManager.update();
    
}

//--------------------------------------------------------------
void ofxLivedrawEngine::draw() {
    ofSetColor(255,0,0);
    ofFill();
    ofRect(0,0, 300,300);
    
    // render to the canvas
    canvas.begin();
    layerManager.draw();
    canvas.end();

    // do any canvas warping (i.e. for triple head) here
    // canvasMapper.map(canvas.getFbo());
    
    // do work with canvas renderer fbo, or just draw it
    canvas.draw(0,0);
    
    // draw gui here.
    // gui.draw();
    
}

//--------------------------------------------------------------
void ofxLivedrawEngine::windowResized(int w, int h) {
    canvas.resize(w,h);
}

//--------------------------------------------------------------
ofxOscRouter* ofxLivedrawEngine::getOscRouter() {
    return &oscRouter;
}

//--------------------------------------------------------------
AssetManager* ofxLivedrawEngine::getAssetManager() {
    return &assetManager;
}

//--------------------------------------------------------------
LayerManager* ofxLivedrawEngine::getLayerManager() {
    return &layerManager;
}

//--------------------------------------------------------------
CanvasRenderer* ofxLivedrawEngine::getCanvasRenderer() {
    return &canvas;
}

////--------------------------------------------------------------
//EffectsManager* ofxLivedrawEngine::getEffectsManager() {
//    return &effectsManager;
//}



////--------------------------------------------------------------
//SessionManager* ofxLivedrawEngine::getSessionManager() {
//    return &sessionManager;
//}

