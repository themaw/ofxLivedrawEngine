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
#include "FrameSourceAsset.h"
#include "BaseMediaAsset.h"


class FrameSourceAsset;

class FrameSinkAsset : public virtual BaseMediaAsset {
public:
    FrameSinkAsset();
    
    virtual ~FrameSinkAsset();
    
    bool sink(ofxVideoFrame frame);
    virtual bool frameReceived(ofxVideoFrame frame) = 0;
    
    // connect / disconnect
    bool isConnected();
    bool attachToSource(FrameSourceAsset* source);    
    bool detachFromAllSources();
    bool detachFromSource(FrameSourceAsset* source);
    
    //    bool remoteAttachToSource(ofxVideoSourceInterface* source);
    //    bool remoteDetachFromSource(ofxVideoSourceInterface* source);
 

    // callbacks
    void sourceWasAttached(FrameSourceAsset* source)  {}; // these callbacks are available
    void sourceWasDetatched(FrameSourceAsset* source) {}; // these callbacks are available
    
    void sinkingEnabled() {};
    void sinkingDisabled() {};
    
    // get source list
    vector<FrameSourceAsset*> getSources();
    
    bool isSinking();
    void setSinking(bool _sinking);
private:
    
    bool sinking;
    
    ofxSimpleSet<FrameSourceAsset*> sources;
};
