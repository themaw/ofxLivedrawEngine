//
//  Header.h
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 5/13/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#pragma once

#include "ofMain.h"
#include <set>
#include "BaseMediaAsset.h"
#include "ofxVideoBuffer.h"

enum FrameBufferType {
    FRAMEBUFFER_DISK,
    FRAMEBUFFER_RAM
};

class FrameBuffer {
public:
    FrameBuffer(FrameBuffer& mom);
    FrameBuffer(int _bufferSize = 1);
    virtual ~FrameBuffer();
    
    string getId();
    void   setId(string bufferId);
    
    void setSource(BaseMediaAsset* _source);
    BaseMediaAsset* getSource();
    bool hasSource();
    
protected:
    
    
    
    BaseMediaAsset* source; // only one source at a time
    
    string bufferId;
    
    FrameBufferType bufferType;
    
private:

};