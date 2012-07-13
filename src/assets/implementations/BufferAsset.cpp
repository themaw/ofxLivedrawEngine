//
//  BufferAsset.cpp
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 7/12/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#include "BufferAsset.h"

//--------------------------------------------------------------
BufferAsset::BufferAsset(const string& _name, int size, ofxVideoBufferType t)
{
    assetType = MEDIA_ASSET_BUFFER;
    
    name = _name;
    
    buffer = ofPtr<ofxVideoBuffer>(new ofxVideoBuffer(size,t));
    
    addOscMethod("/type");    
    addOscMethod("/size"); 
    addOscMethod("/clear");
    addOscMethod("/framerate");
    
    cacheSource = NULL;
    
}

//--------------------------------------------------------------
BufferAsset::~BufferAsset() {}

//--------------------------------------------------------------
bool BufferAsset::dispose() {
    detachFromAllSources();
}

//--------------------------------------------------------------
void BufferAsset::processOscMessage(const string& address, const ofxOscMessage& m) {}

//--------------------------------------------------------------
bool BufferAsset::frameReceived(ofxVideoFrame frame) {};

//--------------------------------------------------------------
bool BufferAsset::isCacheBuffer() {
    return cacheSource != NULL;
}

//--------------------------------------------------------------
CacheableAsset* BufferAsset::getCacheSource() {
    return cacheSource;
}

//--------------------------------------------------------------
ofPtr<ofxVideoBuffer> BufferAsset::getBuffer() {
    return buffer;
}
