//
//  BaseVideoSink.cpp
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 6/5/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#include "BaseVideoSink.h"


//--------------------------------------------------------------
BaseVideoSink::BaseVideoSink() {

}

//--------------------------------------------------------------
BaseVideoSink::~BaseVideoSink() {
    vector<BaseVideoSource*> _sources = getSources();
    for(int i = 0; i < _sources.size(); i++) {
        if(!_sources[i]->sinkWasDetached(this)) {
            cout << "error detatching ..." << endl;
        }
    }
    sources.clear();
}

//--------------------------------------------------------------
bool BaseVideoSink::isConnected() { 
    sources.size() > 0; 
}

//--------------------------------------------------------------
bool BaseVideoSink::connectTo(BaseVideoSource* source) {
    source->sinkWasAttached(this);
}

//--------------------------------------------------------------
bool BaseVideoSink::disconnectFrom(BaseVideoSource* source) {
    source->sinkWasAttached(this);
}

//--------------------------------------------------------------
bool BaseVideoSink::sourceWasDetached(BaseVideoSource* source) {
    sources.remove(source);
}

//--------------------------------------------------------------
vector<BaseVideoSource*> BaseVideoSink::getSources() {
    return sources.toArray();
}
