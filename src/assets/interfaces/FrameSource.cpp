//
//  FrameSource.cpp
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 7/7/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#include "FrameSource.h"


//--------------------------------------------------------------
FrameSource::FrameSource() {
    canSource = true;

    openOnFirstConnection = true;
    closeOnLastDisconnect = true;
    

    ofAddListener(ofEvents().update,this,&FrameSource::update);
    
}

//--------------------------------------------------------------
FrameSource::~FrameSource() {
    std::set<FrameSink*>::iterator iter = sinks.begin();
    while(iter != sinks.end()) detachFromSink(*iter++);
    sinks.clear();
    
    ofRemoveListener(ofEvents().update,this,&FrameSource::update);
}

void FrameSource::update(ofEventArgs& eventsArgs) {
    sourceFrame();
}


//--------------------------------------------------------------
void FrameSource::sourceFrame() {
    if(sinks.isEmpty()) return; 
    
    if(isFrameNew()) {
        // anyone who referenced the old frame will keep it.
        // This source does not keep it, but gets a new one.
        frame = ofPtr<ofImage>(new ofImage()); 
        frame->setFromPixels(getPixelsRef());

        std::set<FrameSink*>::iterator iter = sinks.begin();
        while(iter != sinks.end()) (*iter++)->sink(frame);
        
        frameSourced(frame);
    }
}

//--------------------------------------------------------------
bool FrameSource::hasSinks() const { 
    return sinks.size() > 0; 
}

//--------------------------------------------------------------
bool FrameSource::attachToSink(FrameSink* sink) {
    if(openOnFirstConnection && !hasSinks() && !isLoaded()) {
        open();
        
        if(!isLoaded()) {
            ofLog(OF_LOG_ERROR, "ofxVideoSourceInterface::open() : error opening source.");   
        }
    }
    
    if(sinks.add(sink)) {
        sinkWasAttached(sink);
        return true;
    } else {
        ofLog(OF_LOG_ERROR, "ofxVideoSourceInterface::attachToSink() : error attaching to sink.");
        if(closeOnLastDisconnect && !hasSinks() && isLoaded()) {
            close();
            //            if(!close())  ofLog(OF_LOG_ERROR, "ofxVideoSourceInterface::close() : error closing source.");
        }
        return false;
    }
}

//--------------------------------------------------------------
bool FrameSource::detachFromSink(FrameSink* sink) {
    if(sinks.remove(sink)) {
        sinkWasDetatched(sink);
        if(closeOnLastDisconnect && !hasSinks() && isLoaded()) {
            close();
            //            if(!close())  ofLog(OF_LOG_ERROR, "ofxVideoSourceInterface::close() : error closing source.");
        }
        return true;
    } else {
        ofLog(OF_LOG_ERROR, "ofxVideoSourceInterface::attachToSink() : error attaching to sink.");
        return false;
    }
}

//--------------------------------------------------------------
vector<FrameSink*> FrameSource::getSinks() const {
    return sinks.toArray();
}

//--------------------------------------------------------------
void FrameSource::setOpenOnFirstConnect(bool v) {
    openOnFirstConnection = v;
}

//--------------------------------------------------------------
void FrameSource::setCloseOnLastDisconnect(bool v) {
    closeOnLastDisconnect = v;
}

//--------------------------------------------------------------
bool FrameSource::getOpenOnFirstConnect() {
    return openOnFirstConnection;
}

//--------------------------------------------------------------
bool FrameSource::getCloseOnLastDisconnect() {
    return closeOnLastDisconnect;
}
