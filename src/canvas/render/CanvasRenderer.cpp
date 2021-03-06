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
CanvasRenderer::CanvasRenderer() : ofxOscRouterNode("canvas") {
    
    engine = NULL;
    
    addOscNodeAlias("c");
    addOscNodeAlias("can");
    
    x = 0;
    y = 0;
    width = 1024;
    height = 768;

    addOscMethod("position");
    addOscMethod("size");
    addOscMethod("background");
    addOscMethod("fullscreen");
    addOscMethod("fps");
    addOscMethod("msaa");
    
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
}

//--------------------------------------------------------------
CanvasRenderer::~CanvasRenderer() {}


//--------------------------------------------------------------
void CanvasRenderer::update() {
    // 
}

//--------------------------------------------------------------
void CanvasRenderer::processOscCommand(const string& command, const ofxOscMessage& m) {
    if(isMatch(command,"position")) {
        if(validateOscSignature("[if][if]",m)) {
            int _x = getArgAsIntUnchecked(m,0);
            int _y = getArgAsIntUnchecked(m,1);
            
            ofSetWindowPosition(_x,_y); // TODO: this will behave differently when the GUI comes online
            // actual window position will be handled one level shallower
            setPosition(x,y);
        }
        
    } else if(isMatch(command,"size")) {
        if(validateOscSignature("[if][if]",m)) {
            int w = MAX(0,getArgAsIntUnchecked(m,0));
            int h = MAX(0,getArgAsIntUnchecked(m,1));
            
            ofSetWindowShape(w,h);  // TODO: this will be have differently when the GUI comes online
            // actual window shape will be handled one level shallower
            setSize(w,h);
        }
        
    } else if(isMatch(command,"background")) {
        if(validateOscSignature("[if][if][if][if]?",m)) {
            setBackground(getArgsAsColor(m, 0)); // redundant ...
        }
    } else if(isMatch(command,"fullscreen")) {
        if(validateOscSignature("[if]",m)) {
            ofSetFullscreen(getArgAsBoolUnchecked(m,0));
        }
    } else if(isMatch(command,"msaa")) {
        if(validateOscSignature("[if]",m)) {
            setMsaa(getArgAsBoolUnchecked(m,0));
        }
    } else if(isMatch(command,"fps")) {
        if(validateOscSignature("[if]",m)) {
            setFPS(MAX(0,getArgAsIntUnchecked(m,0)));
        }
    } else {
        ofLogWarning() << "CanvasRenderer::processOscCommand() : Unknown command: " << command;
    }
}


//--------------------------------------------------------------
void CanvasRenderer::begin() {
    fbo.begin(); // start the FBO
    // clear the background
    ofClear(bgColor);
}

//--------------------------------------------------------------
void CanvasRenderer::end() {
    fbo.end(); // end the fbo
}

//--------------------------------------------------------------
void CanvasRenderer::draw(float x, float y) {
    fbo.draw(x,y);
}

//--------------------------------------------------------------
void CanvasRenderer::draw(float x, float y, float w, float h) {
    fbo.draw(x,y,w,h);
}

//--------------------------------------------------------------
float CanvasRenderer::getHeight() {
    return fbo.getHeight();
}

//--------------------------------------------------------------
float CanvasRenderer::getWidth() {
    return fbo.getWidth();
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
void CanvasRenderer::setSize(int w, int h) {
    if(width != w || height != h) { 
        width = w;
        height = h;
        //setup(); // TODO: why is this giving : OF_ERROR: FRAMEBUFFER_INCOMPLETE_ATTACHMENT on resize
    }
}

//--------------------------------------------------------------
void CanvasRenderer::setPosition(int _x, int _y) {
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