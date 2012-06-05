//
//  FrameBuffer.cpp
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 5/13/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#include "FrameBuffer.h"

//--------------------------------------------------------------
FrameBuffer::FrameBuffer(int _bufferSize) : ofxVideoBuffer(_bufferSize){
    bufferId     = "";
    backingAsset = NULL;
}

//--------------------------------------------------------------
FrameBuffer::FrameBuffer(string alias, int _bufferSize) : ofxVideoBuffer(_bufferSize){
    bufferId     = alias;
    backingAsset = NULL;
}

//--------------------------------------------------------------
FrameBuffer::~FrameBuffer() {}

//--------------------------------------------------------------
void FrameBuffer::setBackingAsset(MediaAsset* _asset) {
    backingAsset = _asset;
}

//--------------------------------------------------------------
string FrameBuffer::getId() {
    return bufferId;
}
//--------------------------------------------------------------
void FrameBuffer::setId(string _bufferId) {
    bufferId = _bufferId;
}

//--------------------------------------------------------------
bool FrameBuffer::hasBackingAsset() {
    return backingAsset != NULL;
}

//--------------------------------------------------------------
MediaAsset* FrameBuffer::getBackingAsset() {
    return backingAsset;
}

