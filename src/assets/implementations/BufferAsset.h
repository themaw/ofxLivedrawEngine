//
//  BufferAsset.h
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 7/6/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#pragma once

#include "BaseMediaAsset.h"
#include "FrameSinkAsset.h"
#include "ofxVideoBuffer.h"

#include "CacheableAsset.h"

class BufferAsset : public virtual BaseMediaAsset, 
                    public virtual FrameSinkAsset
{
public:
    BufferAsset(const string& _name, int size, ofxVideoBufferType t);    
    virtual ~BufferAsset();

    // From BaseMediaAsset
    bool dispose();
    
    void processOscMessage(const string& address, const ofxOscMessage& m);

    // From FrameSink
    bool frameReceived(ofxVideoFrame frame);

    bool isCacheBuffer();
    CacheableAsset* getCacheSource();
    ofPtr<ofxVideoBuffer> getBuffer();
    
protected:
    CacheableAsset* cacheSource;
    ofPtr<ofxVideoBuffer> buffer;
};
