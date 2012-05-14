//
//  FrameBuffer.cpp
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 5/13/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#include "FrameBuffer.h"


//--------------------------------------------------------------
FrameBuffer::FrameBuffer(FrameBuffer& mom) : ofxVideoBuffer(mom) {
    
}

//--------------------------------------------------------------
FrameBuffer::FrameBuffer(int _bufferSize) : ofxVideoBuffer(_bufferSize) {
    
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
