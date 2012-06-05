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
#include "ofxSimpleSet.h"

class ofxLivedrawEngine;
class AssetManager;

class BufferManager : public ofxOscRouterNode {
public:
    
    BufferManager(AssetManager* manager);
    virtual ~BufferManager();
    
    void update();  // takes care of sinking, etc
    
    void processOscMessage(string pattern, ofxOscMessage& m);

    FrameBuffer* createNewBuffer(string alias);
    FrameBuffer* createNewBuffer(string alias, int _bufferSize);
    FrameBuffer* createNewBuffer(string alias, int _bufferSize, ofVideoBufferType _type);
    
    bool remove(MediaAsset* asset);
        
private:
    
    AssetManager* assetManager;
    ofxSimpleSet<FrameBuffer*> buffers;   
};
