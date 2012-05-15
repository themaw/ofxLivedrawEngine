//
//  FrameBuffer.cpp
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 5/13/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#include "SamplerManager.h"


//--------------------------------------------------------------
SamplerManager::SamplerManager() : OscNodeListener("/samplers") {
    addOscCommand("new");
}

//--------------------------------------------------------------
SamplerManager::~SamplerManager() {
    
}

//--------------------------------------------------------------
void SamplerManager::update() {
}

//--------------------------------------------------------------
void SamplerManager::processOscMessage(string pattern, ofxOscMessage& m) {
    
}

//--------------------------------------------------------------
Sampler* SamplerManager::getNewSampler() {
    
}

//--------------------------------------------------------------
//--------------------------------------------------------------
//--------------------------------------------------------------
