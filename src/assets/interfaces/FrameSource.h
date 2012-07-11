//
//  SourceAsset.h
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 7/6/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.

#pragma once

#include "BaseMediaAsset.h"
#include "ofxSimpleSet.h"

class FrameSink;

class FrameSource : public virtual BaseMediaAsset {
public:
    FrameSource();
    virtual ~FrameSource();
    
    virtual ofxVideoFrame getFrame() = 0;
    
    void source(); // push frames
    virtual void frameSent(ofxVideoFrame frame) {};
    
    virtual bool close() = 0;
    virtual bool open() = 0;
    virtual bool isOpen() = 0;
    
    bool isConnected();
    
    bool attachToSink(FrameSink* sink); // sinks call this to be fed by this source
    bool detachFromSink(FrameSink* sink); // sinks call this to be cut off from this source
    
    void sinkWasAttached(FrameSink* sink)  {}; // these callbacks are available
    void sinkWasDetatched(FrameSink* sink) {}; // these callbacks are available
    
    void setOpenOnFirstConnect(bool v);
    void setCloseOnLastDisconnect(bool v);
    
    bool getOpenOnFirstConnect();
    bool getCloseOnLastDisconnect();
    
    vector<FrameSink*> getSinks() const;
    
private:
    
    ofxVideoFrame frame;
    
    bool openOnFirstConnection;
    bool closeOnLastDisconnect;
    
    // no subclass access.  all access done via getters 
    // and setters so events will be called
    ofxSimpleSet<FrameSink*> sinks;
};

