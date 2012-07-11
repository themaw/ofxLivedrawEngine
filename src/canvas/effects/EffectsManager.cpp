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
EffectsManager::EffectsManager() : ofxOscRouterNode("/effects") {
    addOscNodeAlias("/eff");
    addOscNodeAlias("/e");
}

//--------------------------------------------------------------
EffectsManager::~EffectsManager() {
    
}

// basic functions

//--------------------------------------------------------------
void EffectsManager::update() {
    
}

// deal with OSC

//--------------------------------------------------------------
void EffectsManager::processOscMessage(const string& pattern, const ofxOscMessage& m) {
 
    cout << "effects manager"  << endl;
    
    
}

// get access to shaders
//--------------------------------------------------------------
ShaderAlphaMask* EffectsManager::getShaderAlphaMask() {
    
}

//--------------------------------------------------------------
ShaderAlphaMask* EffectsManager::getShaderCurves() {
    
}
