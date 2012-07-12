//
//  FrameSink.cpp
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 7/7/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#include "FrameSink.h"


//bool attachToSource(ofxVideoSourceInterface* source);    
//bool detatchFromSource(ofxVideoSourceInterface* source);
//
//// callbacks
//bool sourceWasAttached(ofxVideoSourceInterface* source)  {}; // these callbacks are available
//bool sourceWasDetatched(ofxVideoSourceInterface* source) {}; // these callbacks are available
//
//// get source list
//vector<ofxVideoSourceInterface*> getSources();


//--------------------------------------------------------------
FrameSink::FrameSink() {
    canSink = true;
    sinking = true;
}

//--------------------------------------------------------------
FrameSink::~FrameSink() {
    vector<FrameSource*> _sources = getSources();
    for(int i = 0; i < _sources.size(); i++) {
        detatchFromSource(_sources[i]);
    }
    sources.clear();
}

//--------------------------------------------------------------
bool FrameSink::sink(ofxVideoFrame frame) {
    if(isSinking()) {
        return frameReceived(frame);
    } else {
        return false;
    }
}

//--------------------------------------------------------------
bool FrameSink::isConnected() { 
    return sources.size() > 0; 
}

//--------------------------------------------------------------
bool FrameSink::attachToSource(FrameSource* source) {
    if(source->attachToSink(this)) {
        sources.add(source);
        return true;
    } else {
        ofLog(OF_LOG_ERROR, "ofxVideoSourceInterface::attachToSource() : error attaching to source.");
        return false;
    }
}

//--------------------------------------------------------------
bool FrameSink::detatchFromSource(FrameSource* source) {
    if(source->detachFromSink(this)) {
        sources.remove(source);
        return true;
    } else {
        ofLog(OF_LOG_ERROR, "ofxVideoSourceInterface::detatchFromSource() : error detatching from source.");
        return false;
    }
}

//--------------------------------------------------------------
bool FrameSink::isSinking() {
    return sinking;
}

//--------------------------------------------------------------
void FrameSink::setSinking(bool _sinking) {
    if(_sinking != sinking) {
        sinking = _sinking;
        if(sinking) {
            sinkingEnabled();
        } else {
            sinkingDisabled();
        }
    }
}

