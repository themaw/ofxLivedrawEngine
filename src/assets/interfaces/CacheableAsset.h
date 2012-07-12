//
//  CacheableInterface.h
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 7/6/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#pragma once

#include "BaseMediaAsset.h"

class BufferAsset;

class CacheableAsset : public virtual BaseMediaAsset 
{
public:
    CacheableAsset() {
        cacheBuffer = NULL;

        canCache = true;
        cached = false;
        //buffer.setReadOnly(true);
  
        addOscMethod("/cache");
        addOscMethod("/uncache");
        
//        addOscPlugMethod("/cache", bind(&Cacheable::cache, ref(*this)));
//        addOscPlugMethod("/uncache", bind(&Cacheable::uncache, ref(*this)));
    }

    virtual ~CacheableAsset() {}

    void processOscMessage(const string& pattern, const ofxOscMessage& m) {
        if(isMatch(pattern, "/cache")) {
            cache();
        } else if(isMatch(pattern, "/uncache")) {
            uncache();
        } else {
            cout << "unknown pattern in cache." << endl;
        }
    }

    
    
    virtual bool doCache()   = 0;
    virtual bool doUncache() = 0;

    void cache() {
        if(!isCached()) {
            cached = doCache();
        }
    }
    
    void uncache() {
        if(isCached()) {
            if(doUncache()) {
                cached = false;
            } else {
                cached = true;
            }
        }
    };

    bool isCached() {return cached;}

    BufferAsset* getCacheBuffer() {
        return cacheBuffer;
    }
    
    void setCacheBuffer(BufferAsset* _cacheBuffer) {
        cacheBuffer = _cacheBuffer;
    }
    
protected:
    bool cached;
    BufferAsset* cacheBuffer;
        
};