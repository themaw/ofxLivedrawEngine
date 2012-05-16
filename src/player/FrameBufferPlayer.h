//
//  FrameBufferPlayer.h
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 5/16/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#pragma once

#include "ofMain.h"
#include "ofxOscRouterNode.h"
#include "CanvasLayer.h"
#include "ofxVideoBufferPlayer.h"

class CanvasLayer; // forward!

class FrameBufferPlayer : public ofxVideoBufferPlayer, public ofxOscRouterNode {
public:
    FrameBufferPlayer();
    virtual ~FrameBufferPlayer();
    
    void processOscMessage(string address, ofxOscMessage& m);

    CanvasLayer* getParentLayer();
    void         setParentLayer(CanvasLayer* layer);
    bool         hasParentLayer();
    
private:
    string name;
    CanvasLayer* parentLayer;
};
