//
//  FrameBuffer.cpp
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 5/13/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#include "FrameBuffer.h"

//--------------------------------------------------------------
FrameBuffer::FrameBuffer(string alias) : ofxVideoBuffer(), 
ofxOscRouterNode("/"+alias) 
{
    init(alias);
}

//--------------------------------------------------------------
FrameBuffer::FrameBuffer(string alias, int _bufferSize) : 
ofxVideoBuffer(_bufferSize), 
ofxOscRouterNode("/"+alias) 
{
    init(alias);
}

//--------------------------------------------------------------
FrameBuffer::FrameBuffer(string alias, int _bufferSize, ofVideoBufferType _type) : 
ofxVideoBuffer(_bufferSize, _type), 
ofxOscRouterNode("/"+alias)  
{
    init(alias);
}

void FrameBuffer::init(string alias) {
    bufferId = alias;
    addOscMethod("/type");    
    addOscMethod("/size"); 
    addOscMethod("/clear");
    addOscMethod("/framerate");
}

//--------------------------------------------------------------
FrameBuffer::~FrameBuffer() {}

//--------------------------------------------------------------
void FrameBuffer::processOscMessage(string pattern, ofxOscMessage& m) {
    cout << "got a buffer message " << pattern << endl;
    
    // size!
    // type!
    // clear!
    
}


////--------------------------------------------------------------
//void FrameBuffer::setBackingAsset(MediaAsset* _asset) {
//    backingAsset = _asset;
//}

//--------------------------------------------------------------
string FrameBuffer::getId() {
    return bufferId;
}
//--------------------------------------------------------------
void FrameBuffer::setId(string _bufferId) {
    bufferId = _bufferId;
}

////--------------------------------------------------------------
//bool FrameBuffer::hasBackingAsset() {
//    return backingAsset != NULL;
//}
//
////--------------------------------------------------------------
//MediaAsset* FrameBuffer::getBackingAsset() {
//    return backingAsset;
//}
//
