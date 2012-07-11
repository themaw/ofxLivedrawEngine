//
//  CacheableInterface.h
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 7/6/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#pragma once

#include "BaseMediaAsset.h"

class Cacheable : 
    public virtual BaseMediaAsset {
public:
    Cacheable() {
        canCache = true;
        cached = false;
        //buffer.setReadOnly(true);
    }

    virtual ~Cacheable() {}

    virtual bool doCache()   = 0;
    virtual bool doUnCache() = 0;

    bool cache() {
        if(!isCached()) {
            cached = doCache();
            return cached;
        } else {
            return true;
        }
    };
    bool unCache() {
        if(isCached()) {
            if(doUnCache()) {
                cached = false;
                return true;
            } else {
                cached = true;
                return false;
            }
        } else {
            return true;
        }
    };

    
    bool isCached() {return cached;}
    
protected:
    bool cached;
    //ofxVideoBuffer buffer;    
};