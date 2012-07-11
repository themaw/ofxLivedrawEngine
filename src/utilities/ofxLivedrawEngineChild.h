//
//  ofxLivedrawEngineChild.h
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 6/5/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#pragma once

#include "ofxLivedrawEngine.h"

class ofxLivedrawEngine;

class ofxLivedrawEngineChild {
public:
    ofxLivedrawEngineChild() {}
    virtual ~ofxLivedrawEngineChild() {}

    void setEngine(ofxLivedrawEngine* _engine) {engine = _engine;};
    ofxLivedrawEngine* getEngine() {return engine;}    
    
protected:
    ofxLivedrawEngine* engine;
};
