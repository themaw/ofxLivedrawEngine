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

#pragma once

#include "ofMain.h"
#include "ofxLivedrawEngineInterface.h"
#include "ofxOscRouterNode.h"

#include "AlphaMask.h"
#include "Curves.h"
#include "XFader.h"

class EffectsManager : public ofxOscRouterNode {
    
public:
    EffectsManager();
    virtual ~EffectsManager();

    // basic functions
    void setup();
    
    // basic functions
    void update();
    
    // deal with OSC
    void processOscCommand(const string& command, const ofxOscMessage& m);

    // get access to shaders
    AlphaMask& getAlphaMaskRef();
    Curves& getCurvesRef();
    XFader& getXFaderRef();
    
    
    ofxLivedrawEngineInterface* getEngineInterface() { return engine;}
    void setEngineInterface(ofxLivedrawEngineInterface* _engine) {engine = _engine;}
    
protected:
    
    ofxLivedrawEngineInterface* engine;
    
private:

    // we keep a single collection of shaders here
    // all shader use links back to these shaders so we don't 
    // have to load multiple shaders onto the GPU
    AlphaMask alphaMask;
    Curves    curves;
    XFader     xfader;
    
    
};