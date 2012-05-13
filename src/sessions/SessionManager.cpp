/*
 *  SessionManager.cpp
 *  livedraw
 *
 *  Created by Christopher P. Baker on 12/3/10.
 *  Copyright 2010 Murmur Labs LLC. All rights reserved.
 *
 */

#include "SessionManager.h"

//--------------------------------------------------------------
SessionManager::SessionManager() : OscNodeListener("/sessions") {
    
}

//--------------------------------------------------------------
SessionManager::~SessionManager() {
    
}

//--------------------------------------------------------------
void SessionManager::setup() {
    
}

//--------------------------------------------------------------
void SessionManager::update() {
    // nothin here
}

//--------------------------------------------------------------
void SessionManager::processOscMessage(string address, ofxOscMessage& m) {
    cout << "got a message in the session manager " << address << endl;
}
