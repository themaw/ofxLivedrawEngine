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
#include "OscNodeListener.h"

#include "SessionPreset.h"
#include "SessionPerformance.h"

class SessionManager : public OscNodeListener {
	
public:
	
	SessionManager();
	virtual ~SessionManager();
    
    void setup();
    void update();
    
    void processOscMessage(string address, ofxOscMessage& m);
	
};


