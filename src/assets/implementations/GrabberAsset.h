//
//  GrabberAsset.h
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 7/6/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#pragma once

#include "BaseMediaAsset.h"
#include "FrameSourceAsset.h"

class GrabberAsset : public virtual BaseMediaAsset, 
                     public virtual FrameSourceAsset 
{
public:
    GrabberAsset(const string& _name, int _devId, int _width, int _height);
    virtual ~GrabberAsset();

    bool dispose();
    void processOscMessage(const string& pattern, const ofxOscMessage& m);
    bool isFrameNew();
    ofPixelsRef getPixelsRef();
    void open();
    void close();
    bool isLoaded();

protected:
    int width;
    int height;
    int devId;
    
    ofPtr<ofVideoGrabber> grabber;
    
};
