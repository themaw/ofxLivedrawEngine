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
