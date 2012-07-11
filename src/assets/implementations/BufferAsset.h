//
//  BufferAsset.h
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 7/6/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#pragma once

#include "BaseMediaAsset.h"
#include "FrameSink.h"

#include "ofxVideoBuffer.h"

//class FrameBuffer;


class BufferAsset : public virtual BaseMediaAsset, 
                    public virtual FrameSink
{
public:
    BufferAsset(const string& _name, int size, ofxVideoBufferType t)
    {
        assetType = MEDIA_ASSET_BUFFER;
        
        name = _name;
        
        buffer = ofPtr<ofxVideoBuffer>(new ofxVideoBuffer(size,t));
        
        addOscMethod("/type");    
        addOscMethod("/size"); 
        addOscMethod("/clear");
        addOscMethod("/framerate");
        
        
    }
    
    virtual ~BufferAsset();

    // From BaseMediaAsset
    bool dispose() {

    }
    
    void processOscMessage(const string& address, const ofxOscMessage& m) {}

    // From FrameSink
    bool frameReceived(ofxVideoFrame frame) {};



protected:
    ofPtr<ofxVideoBuffer> buffer;
};
