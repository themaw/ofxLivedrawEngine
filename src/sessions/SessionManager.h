/*
 *  SessionManager.h
 *  livedraw
 *
 *  Created by Christopher P. Baker on 12/3/10.
 *  Copyright 2010 Murmur Labs LLC. All rights reserved.
 *
 */

#pragma once

#include "ofMain.h"
#include "ofxOscRouterNode.h"

#include "SessionPreset.h"
#include "SessionPerformance.h"
#include "ofxLivedrawEngine.h"

class ofxLivedrawEngine;

class SessionManager : public ofxOscRouterNode {
	
public:
	
	SessionManager();
	virtual ~SessionManager();
    
    void update();
    
    void processOscMessage(string address, ofxOscMessage& m);
	
    void setEngine(ofxLivedrawEngine* _engine) {engine = _engine;};
    ofxLivedrawEngine* getEngine() {return engine;}    
    
protected:
    
    ofxLivedrawEngine* engine;

    
};


