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

#include "CanvasRenderer.h"

//--------------------------------------------------------------
CanvasRenderer::CanvasRenderer() : ofxOscRouterNode("/canvas") {
    addOscNodeAlias("/c");
    addOscNodeAlias("/can");
    
    x = 0;
    y = 0;
    width = 1024;
    height = 768;

    init();
}

//--------------------------------------------------------------
CanvasRenderer::~CanvasRenderer() {
    
}

void CanvasRenderer::init() {
    
//    layerManager = new CanvasLayerManager();
//    addOscChild(layerManager);
    
    
    addOscMethod("/position");
    addOscMethod("/size");
    addOscMethod("/background");
    addOscMethod("/fullscreen");
    addOscMethod("/fps");
    addOscMethod("/msaa");
    
    
    useMSAA = true;
        
    bgColor = ofColor(0,0,0,255);

    /*
     ofFbo::Settings s;
     s.width				= width;
     s.height			= height;
     s.numColorbuffers	= 1; // not sure how many I need.
     s.numSamples		= useMSAA ? ofFbo::maxSamples() : 0;
     
     fbo.setup(s);
     */
    
    fbo.allocate(width,height);
    
    //layerManager.setup();
}


//--------------------------------------------------------------
//void CanvasRenderer::setEffectsManager(EffectsManager* _effectsManager) {
//    effectsManager = _effectsManager;
//    layerManager.setEffectsManager(effectsManager);
//}

//--------------------------------------------------------------
void CanvasRenderer::update() {
//    layerManager.update();
}

//--------------------------------------------------------------
void CanvasRenderer::render() {
    fbo.begin(); // start the FBO
    // clear the background
    
    glClearColor(bgColor.r/255.0,bgColor.g/255.0,bgColor.b/255.0,bgColor.a/255.0);
    glClear(GL_COLOR_BUFFER_BIT);

    
//    ofSetColor(bgColor);
//    ofFill();
//    ofRect(0,0,fbo.getWidth(),fbo.getHeight());

//    layerManager.draw();
    fbo.end(); // end the fbo
}

//--------------------------------------------------------------
void CanvasRenderer::draw() {
    fbo.draw(0,0);
}

//--------------------------------------------------------------
void CanvasRenderer::processOscMessage(const string& pattern, const ofxOscMessage& m) {
    // got one for the canvas!

    ofLog(OF_LOG_NOTICE, "CanvasRenderer:const string& pattern, const ofxOscMessage& m(const string& pattern, ofxOscMessage& m) : " + m.getAddress());
    
    if(isMatch(pattern, "/position")) {
        if(validateOscSignature("[if][if]",m)) {
            cout << m.getAddress() << endl;
            int _x = m.getArgAsInt32(0);
            int _y = m.getArgAsInt32(1);
            
            ofSetWindowPosition(_x,_y); // TODO: this will behave differently when the GUI comes online
                                      // actual window position will be handled one level shallower
            setPosition(x,y);
        }
        
    } else if(isMatch(pattern,"/size")) {
        if(validateOscSignature("[if][if]",m)) {
            int w = MAX(0,m.getArgAsInt32(0));
            int h = MAX(0,m.getArgAsInt32(1));
            
            ofSetWindowShape(w,h);  // TODO: this will be have differently when the GUI comes online
                                     // actual window shape will be handled one level shallower
            setSize(w,h);
        }
        
    } else if(isMatch(pattern,"/background")) {
        if(validateOscSignature("[if][if][if][if]?",m)) {
            ofColor _bgColor;
            if(m.getNumArgs() >= 3) {
                int r = ofClamp(m.getArgAsInt32(0),0,255);
                int g = ofClamp(m.getArgAsInt32(1),0,255);
                int b = ofClamp(m.getArgAsInt32(2),0,255);
                _bgColor = ofColor(r,g,b);
            }
            
            if(m.getNumArgs() == 4) {
                int a = ofClamp(m.getArgAsInt32(3),0,255);
                _bgColor = ofColor(_bgColor, a);
            }
            
            setBackground(_bgColor); // redundant ...
        }            
    } else if(isMatch(pattern,"/fullscreen")) {
        if(validateOscSignature("[if]",m)) {
            ofSetFullscreen(getArgAsBoolean(m,0));
        }
    } else if(isMatch(pattern,"/msaa")) {
        if(validateOscSignature("[if]",m)) {
            setMsaa(getArgAsBoolean(m,0));
        }
    } else if(isMatch(pattern,"/fps")) {
        if(validateOscSignature("[if]",m)) {
            setFPS(MAX(0,m.getArgAsInt32(0)));
        }
    } else {
        ofLog(OF_LOG_WARNING, "CanvasRenderer: Unknown command: " + pattern);
    }
}

//--------------------------------------------------------------
void CanvasRenderer::setFullscreen(bool _fullscreen) {
    ofSetFullscreen(_fullscreen);
}

//--------------------------------------------------------------
void CanvasRenderer:: setBackground(ofColor _color) {
    bgColor = _color;
}

//--------------------------------------------------------------
void CanvasRenderer:: setSize(int w, int h) {
    if(width != w || height != h) { 
        width = w;
        height = h;
        //setup(); // TODO: why is this giving : OF_ERROR: FRAMEBUFFER_INCOMPLETE_ATTACHMENT on resize
    }
}

//--------------------------------------------------------------
void CanvasRenderer:: setPosition(int _x, int _y) {
    x = _x;
    y = _y;

}

//--------------------------------------------------------------
void CanvasRenderer::setFPS(int _fps) {
    ofSetFrameRate(_fps);
}

//--------------------------------------------------------------
void CanvasRenderer::setMsaa(bool _useMSAA) {
    if(_useMSAA != useMSAA) {
        useMSAA = _useMSAA;
        // setup(); // TODO: why is this giving : OF_ERROR: FRAMEBUFFER_INCOMPLETE_ATTACHMENT on resize?
    }
}

//--------------------------------------------------------------
void CanvasRenderer::resize(int w, int h) {
    fbo.allocate(w,h);
}


////--------------------------------------------------------------
//CanvasLayerManager* CanvasRenderer::getCanvasLayerManager() {
//    return layerManager;
//}
//
//
////--------------------------------------------------------------
//void CanvasRenderer::setEngine(ofxLivedrawEngine* _engine) {
//    engine = _engine;
//    layerManager->setEngine(_engine);
//};
//
////--------------------------------------------------------------
//ofxLivedrawEngine* CanvasRenderer::getEngine() {return engine;}    


