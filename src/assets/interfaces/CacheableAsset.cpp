//
//  CacheableAsset.cpp
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 7/12/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#include "CacheableAsset.h"

//--------------------------------------------------------------
CacheableAsset::CacheableAsset() {
    cacheBuffer = NULL;
    
    canCache = true;
    cached = false;
    //buffer.setReadOnly(true);
    
    addOscMethod("/cache");
    addOscMethod("/uncache");
    
    //        addOscPlugMethod("/cache", bind(&Cacheable::cache, ref(*this)));
    //        addOscPlugMethod("/uncache", bind(&Cacheable::uncache, ref(*this)));
}

//--------------------------------------------------------------
CacheableAsset::~CacheableAsset() {}

//--------------------------------------------------------------
void CacheableAsset::processOscMessage(const string& pattern, const ofxOscMessage& m) {
    if(isMatch(pattern, "/cache")) {
        cache();
    } else if(isMatch(pattern, "/uncache")) {
        uncache();
    } else {
        cout << "unknown pattern in cache." << endl;
    }
}

//--------------------------------------------------------------
void CacheableAsset::cache() {
    if(!isCached()) {
        cached = doCache();
    }
}

//--------------------------------------------------------------
void CacheableAsset::uncache() {
    if(isCached()) {
        if(doUncache()) {
            cached = false;
        } else {
            cached = true;
        }
    }
}

//--------------------------------------------------------------
bool CacheableAsset::isCached() {return cached;}

//--------------------------------------------------------------
BufferAsset* CacheableAsset::getCacheBuffer() {
    return cacheBuffer;
}

//--------------------------------------------------------------
void CacheableAsset::setCacheBuffer(BufferAsset* _cacheBuffer) {
    cacheBuffer = _cacheBuffer;
}
