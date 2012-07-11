//
//  SyphonPixelClient.h
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 7/11/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#pragma once

#include "ofxSyphonClient.h"

class ofxSyphonVideoClient : public ofxSyphonClient, 
                             public ofBaseVideo

{
public:
    ofxSyphonVideoClient() {}
    virtual ~ofxSyphonVideoClient() {}
    
    void update() {
    }
    
    unsigned char* getPixels() {
        if(isFrameNew()) {
            fillPixels();
        }
        return pixels.getPixels();
    }
    
	virtual ofPixelsRef getPixelsRef() {
        if(isFrameNew()) {
            fillPixels();
        }
        return pixels;
    }

    virtual bool isFrameNew() {
        // TODO: no way to check this just yet
        return true;
    }
    
    void open() {
        // TODO: not implemented
    }
    
    void close() {
        // TODO: not implemented
    }

    bool isConnected() {
        // TODO: not implemented
        return true;
    }
    
protected:
    void fillPixels() {
        // TODO: this should only be called as needed
        // there is likely no reason to do a readback here.  
        // probably can just bind to the texture directly.
        // but we need to bring it into the shared pointer 
        mTex.readToPixels(pixels);
    }
    
    ofPixels pixels;

};
