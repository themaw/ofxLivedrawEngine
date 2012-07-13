//
//  BufferPlayerAsset.h
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 7/6/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#pragma once

#include "ofxVideoBufferPlayer.h"

#include "BaseMediaAsset.h"
#include "FrameSourceAsset.h"


class BufferPlayerAsset : public virtual BaseMediaAsset, 
                          public virtual FrameSourceAsset 
{
public:
    BufferPlayerAsset(const string& _name);
    virtual ~BufferPlayerAsset();

    // Base media asset
    bool dispose();
    
    void processOscMessage(const string& pattern, const ofxOscMessage& m);

    void  draw(float x,float y);
	void  draw(float x,float y,float w, float h);

    // Frame Source
    bool isFrameNew();
    
    ofPixelsRef getPixelsRef();
    
    void open();
    void close();
    bool isLoaded();
    
protected:
    ofPtr<ofxVideoBufferPlayer> player;
};
