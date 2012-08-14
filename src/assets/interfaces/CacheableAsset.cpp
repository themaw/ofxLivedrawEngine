/*==============================================================================
 
 Copyright (c) 2010, 2011, 2012 Christopher Baker <http://christopherbaker.net>
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 
 ==============================================================================*/

#include "CacheableAsset.h"

//--------------------------------------------------------------
CacheableAsset::CacheableAsset(AssetManagerInterface* man, const string& _filename) : DiskBasedAsset(man, _filename), BaseMediaAsset(man){
    cacheProvider = NULL;
    cacheBuffer = NULL;
    
    canCache = true;
    cached = false;
    //buffer.setReadOnly(true);
    
    addOscMethod("cache");
    addOscMethod("uncache");
    
    //        addOscPlugMethod("/cache", bind(&Cacheable::cache, ref(*this)));
    //        addOscPlugMethod("/uncache", bind(&Cacheable::uncache, ref(*this)));
}

//--------------------------------------------------------------
CacheableAsset::~CacheableAsset() {
    // cachable assets do not destroy their cache buffer asset upon destruction
}

//--------------------------------------------------------------
void CacheableAsset::update() {

    // call super class
    DiskBasedAsset::update();
}

//--------------------------------------------------------------
void CacheableAsset::processOscCommand(const string& command, const ofxOscMessage& m) {
    
    if(isMatch(command,"cache")) {
        cache();
    } else if(isMatch(command,"uncache")) {
        uncache();
    } else {
       ofLogWarning() << "CacheableAsset::processOscCommand : unknown command for cache.";
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
    if(isCached() && cacheBuffer != NULL) {
        if(doUncache()) {
            cached = false;
        } else {
            cached = true;
        }
    }
}

//--------------------------------------------------------------
bool CacheableAsset::isCached() {
    return cached;
}

//--------------------------------------------------------------
BufferAsset* CacheableAsset::getCacheBuffer() {
    return cacheBuffer;
}

//--------------------------------------------------------------
void CacheableAsset::setCacheBuffer(BufferAsset* _cacheBuffer) {
    cacheBuffer = _cacheBuffer;
}

//--------------------------------------------------------------
bool CacheableAsset::hasCacheProvider() {
    return cacheProvider != NULL;
}

//--------------------------------------------------------------
void CacheableAsset::setCacheProvider(CacheProvider* _cacheProvider) {
    cacheProvider = _cacheProvider;
}

