//
//  EffectsChain.cpp
//  livedraw
//
//  Created by Christopher P. Baker on 5/18/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "EffectsChain.h"

//--------------------------------------------------------------
EffectsChain::EffectsChain() : OscNodeListener("/effects") {
    
}

//--------------------------------------------------------------
EffectsChain::~EffectsChain() {
    
}

//--------------------------------------------------------------
void EffectsChain::setup() {
    addOscChild(&alphaMaskSettings);
    addOscChild(&curvesSettings);
}

//--------------------------------------------------------------
void EffectsChain::update() {}

//--------------------------------------------------------------
void EffectsChain::draw() {}

//--------------------------------------------------------------
void EffectsChain::processOscMessage(string pattern, ofxOscMessage& m) {
    cout << "EFFECTS CHAIN GOT AN OSC MESSAGE";
}

//--------------------------------------------------------------
void EffectsChain::setEffectsManager(EffectsManager* _effectsManager) {
    effectsManager = _effectsManager;
}
