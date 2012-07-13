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
    CacheableAsset();
    virtual ~CacheableAsset();

    void processOscMessage(const string& pattern, const ofxOscMessage& m);    

    virtual bool doCache()   = 0; // must implement in subclasses
    virtual bool doUncache() = 0; // must implement in subclasses

    void cache();
    void uncache();
    bool isCached();
    BufferAsset* getCacheBuffer();
    void setCacheBuffer(BufferAsset* _cacheBuffer);
    
protected:
    bool cached;
    BufferAsset* cacheBuffer;
        
};