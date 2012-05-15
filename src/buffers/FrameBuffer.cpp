//
//  FrameBuffer.cpp
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 5/13/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#include "FrameBuffer.h"


//--------------------------------------------------------------
FrameBuffer::FrameBuffer(FrameBuffer& mom) {
    source = NULL;   
}

//--------------------------------------------------------------
FrameBuffer::FrameBuffer(int _bufferSize) {
    source = NULL;
}

//--------------------------------------------------------------
FrameBuffer::~FrameBuffer() {
    
}

//--------------------------------------------------------------
string FrameBuffer::getId() {
    return bufferId;
}
//--------------------------------------------------------------
void   FrameBuffer::setId(string _bufferId) {
    bufferId = _bufferId;
}

//--------------------------------------------------------------
void FrameBuffer::setSource(BaseMediaAsset* _source) {
    source = _source;
}

//--------------------------------------------------------------
BaseMediaAsset* FrameBuffer::getSource() {
    return source;
}

//--------------------------------------------------------------
bool FrameBuffer::hasSource() {
    return source == NULL;
}
