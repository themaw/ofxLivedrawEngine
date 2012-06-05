//
//  BaseVideoSource.cpp
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 6/5/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#include "BaseVideoSource.h"


//--------------------------------------------------------------
BaseVideoSource::BaseVideoSource() {}

//--------------------------------------------------------------
BaseVideoSource::~BaseVideoSource() {
    vector<BaseVideoSink*> _sinks = getSinks();
    for(int i = 0; i < _sinks.size(); i++) {
        _sinks[i]->sourceWasDetached(this);
    }
    sinks.clear();
}

//--------------------------------------------------------------
bool BaseVideoSource::isConnected() { 
    sinks.size() > 0; 
}

//--------------------------------------------------------------
bool BaseVideoSource::sinkWasAttached(BaseVideoSink* sink) {
    if(!sinks.add(sink)) {
        cout << "Error attaching sink." << endl;
    }
}

//--------------------------------------------------------------
bool BaseVideoSource::sinkWasDetached(BaseVideoSink* sink) {
    if(!sinks.remove(sink)) {
        cout << "Error detaching sink." << endl;
    }
}

//--------------------------------------------------------------
vector<BaseVideoSink*> BaseVideoSource::getSinks() {
    return sinks.toArray();
}