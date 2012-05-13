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
#include "OscNodeListener.h"

#include "ShaderAlphaMask.h"
#include "ShaderCurves.h"

class EffectsManager : public OscNodeListener {
    
public:
    EffectsManager();
    virtual ~EffectsManager();
    
    // basic functions
    void setup();
    void update();
    
    // deal with OSC
    void processOscMessage(string pattern, ofxOscMessage& m);

    
    // get access to shaders
    ShaderAlphaMask* getShaderAlphaMask();
    ShaderAlphaMask* getShaderCurves();
    
private:

    // we keep a single collection of shaders here
    // all shader use links back to these shaders so we don't 
    // have to load multiple shaders onto the GPU
    ShaderAlphaMask alphaMaskShader;
    ShaderCurves    curvesShader;
    
    
};