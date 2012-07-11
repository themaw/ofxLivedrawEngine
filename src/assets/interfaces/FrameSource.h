//
//  SourceAsset.h
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 7/6/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.

#pragma once

#include "ofxSimpleSet.h"
#include "BaseMediaAsset.h"
#include "ofxVideoFrame.h"
#include "FrameSink.h"

class FrameSink;

class FrameSource : public virtual BaseMediaAsset {
public:
    FrameSource();
    virtual ~FrameSource();

    void update(ofEventArgs& eventsArgs);

    void sourceFrame(); // push frames to all receivers

    ///////////
    virtual void frameSourced(ofxVideoFrame frame) {};

    virtual bool isFrameNew() = 0;
    virtual ofPixelsRef getPixelsRef() = 0;
    
    virtual void open()   = 0;
    virtual void close()  = 0;

    virtual bool isLoaded() = 0;
    ///////////
    

    
    // sinks
    bool hasSinks() const;  // is connected to any receivers
    
    bool attachToSink(FrameSink* sink); // sinks call this to be fed by this source
    bool detachFromSink(FrameSink* sink); // sinks call this to be cut off from this source
    
    void sinkWasAttached(FrameSink* sink)  {}; // these callbacks are available
    void sinkWasDetatched(FrameSink* sink) {}; // these callbacks are available
    
    void setOpenOnFirstConnect(bool v);
    void setCloseOnLastDisconnect(bool v);
    
    bool getOpenOnFirstConnect();
    bool getCloseOnLastDisconnect();
    
    vector<FrameSink*> getSinks() const;

protected:
    ofxVideoFrame frame;
    
private:
    
    
    bool openOnFirstConnection;
    bool closeOnLastDisconnect;
    
    // no subclass access.  all access done via getters 
    // and setters so events will be called
    ofxSimpleSet<FrameSink*> sinks;
};

