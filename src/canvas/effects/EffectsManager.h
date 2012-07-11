/*
 *  EffectsManager.h
 *  livedraw
 *
 *  Created by Christopher P. Baker on 3/7/11.
 *  Copyright 2011 Murmur Labs LLC. All rights reserved.
 *
 */

#pragma once

#include "ofMain.h"
#include "ofxOscRouterNode.h"

#include "ShaderAlphaMask.h"
#include "ShaderCurves.h"

#include "ofxLivedrawEngine.h"

class ofxLivedrawEngine;

class EffectsManager : public ofxOscRouterNode {
    
public:
    EffectsManager();
    virtual ~EffectsManager();
    
    // basic functions
    void update();
    
    // deal with OSC
    void processOscMessage(const string& pattern, const ofxOscMessage& m);

    
    // get access to shaders
    ShaderAlphaMask* getShaderAlphaMask();
    ShaderAlphaMask* getShaderCurves();
   
    void setEngine(ofxLivedrawEngine* _engine) {engine = _engine;};
    ofxLivedrawEngine* getEngine() {return engine;}    
    
protected:
    
    ofxLivedrawEngine* engine;
private:

    // we keep a single collection of shaders here
    // all shader use links back to these shaders so we don't 
    // have to load multiple shaders onto the GPU
    ShaderAlphaMask alphaMaskShader;
    ShaderCurves    curvesShader;
    
    
};