//
//  FrameSink.cpp
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 7/7/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#include "FrameSinkAsset.h"


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
FrameSinkAsset::FrameSinkAsset() {
    canSink = true;
    sinking = true;
}

//--------------------------------------------------------------
FrameSinkAsset::~FrameSinkAsset() {
    vector<FrameSourceAsset*> _sources = getSources();
    for(int i = 0; i < _sources.size(); i++) {
        detachFromSource(_sources[i]);
    }
    sources.clear();
}

//--------------------------------------------------------------
bool FrameSinkAsset::sink(ofxVideoFrame frame) {
    if(isSinking()) {
        return frameReceived(frame);
    } else {
        return false;
    }
}

//--------------------------------------------------------------
bool FrameSinkAsset::isConnected() { 
    return sources.size() > 0; 
}

//--------------------------------------------------------------
bool FrameSinkAsset::attachToSource(FrameSourceAsset* source) {
    if(source->attachToSink(this)) {
        sources.add(source);
        return true;
    } else {
        ofLog(OF_LOG_ERROR, "ofxVideoSourceInterface::attachToSource() : error attaching to source.");
        return false;
    }
}

//--------------------------------------------------------------
bool FrameSinkAsset::detachFromAllSources() {
    vector<FrameSourceAsset*> connected = sources.toArray();
    for(int i = 0; i < connected.size(); i++) {
        detachFromSource(connected[i]);
    }
    return true;
}


//--------------------------------------------------------------
bool FrameSinkAsset::detachFromSource(FrameSourceAsset* source) {
    if(source->detachFromSink(this)) {
        sources.remove(source);
        return true;
    } else {
        ofLog(OF_LOG_ERROR, "ofxVideoSourceInterface::detatchFromSource() : error detatching from source.");
        return false;
    }
}

//--------------------------------------------------------------
bool FrameSinkAsset::isSinking() {
    return sinking;
}

//--------------------------------------------------------------
void FrameSinkAsset::setSinking(bool _sinking) {
    if(_sinking != sinking) {
        sinking = _sinking;
        if(sinking) {
            sinkingEnabled();
        } else {
            sinkingDisabled();
        }
    }
}

