/*
 *  EffectsManager.cpp
 *  livedraw
 *
 *  Created by Christopher P. Baker on 3/7/11.
 *  Copyright 2011 Murmur Labs LLC. All rights reserved.
 *
 */

#include "EffectsManager.h"

//--------------------------------------------------------------
EffectsManager::EffectsManager() : OscNodeListener("/effects") {
    
}

//--------------------------------------------------------------
EffectsManager::~EffectsManager() {
    
}

// basic functions
//--------------------------------------------------------------
void EffectsManager::setup() {
    
}

//--------------------------------------------------------------
void EffectsManager::update() {
    
}

// deal with OSC

//--------------------------------------------------------------
void EffectsManager::processOscMessage(string pattern, ofxOscMessage& m) {
 
    
    
    
}

// get access to shaders
//--------------------------------------------------------------
ShaderAlphaMask* EffectsManager::getShaderAlphaMask() {
    
}

//--------------------------------------------------------------
ShaderAlphaMask* EffectsManager::getShaderCurves() {
    
}
