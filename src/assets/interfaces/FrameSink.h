//
//  SinkAsset.h
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 7/6/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#pragma once

#include "ofMain.h"
#include "ofxSimpleSet.h"
#include "ofxVideoFrame.h"
#include "FrameSource.h"
#include "BaseMediaAsset.h"


class FrameSource;

class FrameSink : public virtual BaseMediaAsset {
public:
    FrameSink();
    
    virtual ~FrameSink();
    
    bool sink(ofxVideoFrame frame);
    virtual bool frameReceived(ofxVideoFrame frame) = 0;
    
    // connect / disconnect
    bool isConnected();
    bool attachToSource(FrameSource* source);    
    bool detatchFromSource(FrameSource* source);
    
    //    bool remoteAttachToSource(ofxVideoSourceInterface* source);
    //    bool remoteDetachFromSource(ofxVideoSourceInterface* source);
    
    // callbacks
    void sourceWasAttached(FrameSource* source)  {}; // these callbacks are available
    void sourceWasDetatched(FrameSource* source) {}; // these callbacks are available
    
    void sinkingEnabled() {};
    void sinkingDisabled() {};
    
    // get source list
    vector<FrameSource*> getSources();
    
    bool isSinking();
    void setSinking(bool _sinking);
private:
    
    bool sinking;
    
    ofxSimpleSet<FrameSource*> sources;
};
