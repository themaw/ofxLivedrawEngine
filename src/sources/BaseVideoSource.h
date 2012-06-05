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

class BaseVideoSink;

class BaseVideoSource {
public:
    BaseVideoSource();
    virtual ~BaseVideoSource();
    virtual ofxVideoFrame& getCurrentFrame();
    bool isConnected();
    bool sinkWasAttached(BaseVideoSink* sink);
    bool sinkWasDetached(BaseVideoSink* sink);
    vector<BaseVideoSink*> getSinks();
private:
    ofxSimpleSet<BaseVideoSink*> sinks;
};
