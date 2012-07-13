//
//  SyphonAsset.h
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 7/6/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#pragma once

#include "BaseMediaAsset.h"
#include "FrameSourceAsset.h"

#include "ofxSyphonVideoClient.h"

class SyphonAsset : public virtual BaseMediaAsset,
                    public virtual FrameSourceAsset 
{
public:
    SyphonAsset(const string& _name);
    virtual ~SyphonAsset();

    void processOscMessage(const string& pattern, const ofxOscMessage& m);
    bool dispose();
    bool isFrameNew();    
    ofPixelsRef getPixelsRef();
    void open();
    void close();
    bool isLoaded();
    
protected:
    
    ofPtr<ofxSyphonVideoClient> syphonClient;

};
