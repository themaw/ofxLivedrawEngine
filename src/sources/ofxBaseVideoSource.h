//
//  BaseVideoSource.h
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 6/5/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#pragma once

#include "ofMain.h"
#include "ofxVideoBufferTypes.h"
#include "ofxSimpleSet.h"
#include "BaseVideoSink.h"
#include "MediaAsset.h"

class BaseVideoSink;
class MediaAsset;

class BaseVideoSource {
public:
    BaseVideoSource();
    virtual ~BaseVideoSource();
    virtual ofxVideoFrame& getCurrentFrame() = 0;
    
    virtual void close() = 0; // called when nobody else is connected 
    
    bool isConnected();
    bool sinkWasAttached(BaseVideoSink* sink);
    bool sinkWasDetached(BaseVideoSink* sink);
    vector<BaseVideoSink*> getSinks();

    void        setMediaAsset(MediaAsset* asset);
    MediaAsset* getMediaAsset();

private:
    MediaAsset* asset;
    ofxSimpleSet<BaseVideoSink*> sinks;
};
