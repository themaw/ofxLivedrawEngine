//
//  Header.h
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 5/13/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#pragma once

#include "ofMain.h"
#include "ofxVideoBuffer.h"

class FrameBuffer : public ofxVideoBuffer {
public:
    FrameBuffer(FrameBuffer& mom);
    FrameBuffer(int _bufferSize = 1);
    virtual ~FrameBuffer();
    
    string getId();
    void   setId(string bufferId);
    
protected:
    
    string bufferId;
    
private:

};