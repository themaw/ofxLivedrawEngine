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
#include "FrameBuffer.h"
#include "ofxVideoPlayer.h"

class Sampler {
public:
    Sampler();
    virtual ~Sampler();
    
    string getId();
    void   setId(string bufferId);
    
    void setBuffer(FrameBuffer* _source);
    FrameBuffer* getBuffer();
    bool hasBuffer();
    
protected:
    

    
    FrameBuffer* buffer; // only one source at a time
    
    string samplerId;
    
private:

};