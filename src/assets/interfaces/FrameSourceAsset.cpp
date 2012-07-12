//
//  FrameSource.cpp
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 7/7/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#include "FrameSourceAsset.h"


//--------------------------------------------------------------
FrameSourceAsset::FrameSourceAsset() {
    canSource = true;

    openOnFirstConnection = true;
    closeOnLastDisconnect = true;
    

    ofAddListener(ofEvents().update,this,&FrameSourceAsset::update);
    
}

//--------------------------------------------------------------
FrameSourceAsset::~FrameSourceAsset() {
    std::set<FrameSinkAsset*>::iterator iter = sinks.begin();
    while(iter != sinks.end()) detachFromSink(*iter++);
    sinks.clear();
    
    ofRemoveListener(ofEvents().update,this,&FrameSourceAsset::update);
}

void FrameSourceAsset::update(ofEventArgs& eventsArgs) {
    sourceFrame();
}


//--------------------------------------------------------------
void FrameSourceAsset::sourceFrame() {
    if(sinks.isEmpty()) return; 
    
    if(isFrameNew()) {
        // anyone who referenced the old frame will keep it.
        // This source does not keep it, but gets a new one.
        frame = ofPtr<ofImage>(new ofImage()); 
        frame->setFromPixels(getPixelsRef());

        std::set<FrameSinkAsset*>::iterator iter = sinks.begin();
        while(iter != sinks.end()) (*iter++)->sink(frame);
        
        frameSourced(frame);
    }
}

//--------------------------------------------------------------
bool FrameSourceAsset::hasSinks() const { 
    return sinks.size() > 0; 
}

//--------------------------------------------------------------
bool FrameSourceAsset::attachToSink(FrameSinkAsset* sink) {
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
bool FrameSourceAsset::detachFromSink(FrameSinkAsset* sink) {
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
bool FrameSourceAsset::detachFromAllSinks() {
    vector<FrameSinkAsset*> connected = sinks.toArray();
    for(int i = 0; i < connected.size(); i++) {
        detachFromSink(connected[i]);
    }
    return true;
}

//--------------------------------------------------------------
vector<FrameSinkAsset*> FrameSourceAsset::getSinks() const {
    return sinks.toArray();
}

//--------------------------------------------------------------
void FrameSourceAsset::setOpenOnFirstConnect(bool v) {
    openOnFirstConnection = v;
}

//--------------------------------------------------------------
void FrameSourceAsset::setCloseOnLastDisconnect(bool v) {
    closeOnLastDisconnect = v;
}

//--------------------------------------------------------------
bool FrameSourceAsset::getOpenOnFirstConnect() {
    return openOnFirstConnection;
}

//--------------------------------------------------------------
bool FrameSourceAsset::getCloseOnLastDisconnect() {
    return closeOnLastDisconnect;
}
