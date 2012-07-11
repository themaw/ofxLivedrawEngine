//
//  BaseVideoSink.h
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 6/5/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#pragma once

#include "ofMain.h"
#include "ofxSimpleSet.h"

#include "BaseVideoSource.h"

class BaseVideoSource;

class BaseVideoSink {
public:
    BaseVideoSink();
    virtual ~BaseVideoSink();
    bool isConnected();
    bool connectTo(BaseVideoSource* source);    
    bool disconnectFrom(BaseVideoSource* source);
    bool sourceWasDetached(BaseVideoSource* source);
    vector<BaseVideoSource*> getSources();

private:

    ofxSimpleSet<BaseVideoSource*> sources;
        
};
