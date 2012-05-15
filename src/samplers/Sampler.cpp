//
//  FrameBuffer.cpp
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 5/13/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#include "Sampler.h"

//--------------------------------------------------------------
Sampler::Sampler() {
    buffer = NULL;
}

//--------------------------------------------------------------
Sampler::~Sampler() {
    
}

//--------------------------------------------------------------
string Sampler::getId() {
    return samplerId;
}
//--------------------------------------------------------------
void   Sampler::setId(string _samplerId) {
    samplerId = _samplerId;
}

//--------------------------------------------------------------
void Sampler::setBuffer(FrameBuffer* _buffer) {
    buffer = _buffer;
}

//--------------------------------------------------------------
FrameBuffer* Sampler::getBuffer() {
    return buffer;
}

//--------------------------------------------------------------
bool Sampler::hasBuffer() {
    return buffer == NULL;
}
