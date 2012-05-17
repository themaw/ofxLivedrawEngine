//
//  ofxLivedrawEngine.h
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 5/13/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#pragma once

#include "ofMain.h"
#include "AssetManager.h"
#include "ofxOscRouterNode.h"
#include "FrameBuffer.h"
#include "ofxLivedrawEngine.h"

class ofxLivedrawEngine;

class BufferManager : public ofxOscRouterNode {
public:
    
    BufferManager();
    virtual ~BufferManager();
    
    void update();
    void processOscMessage(string pattern, ofxOscMessage& m);

    FrameBuffer* getNewAssetBackedBuffer(MediaAsset* _asset);
    FrameBuffer* getNewVideoBuffer(int _bufferSize = 1);

    void setEngine(ofxLivedrawEngine* _engine) {engine = _engine;};
    ofxLivedrawEngine* getEngine() {return engine;}    
    
protected:

    ofxLivedrawEngine* engine;
    
private:
    
    
    
    vector<ofxVideoBuffer> buffers;
    
};
