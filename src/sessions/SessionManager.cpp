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
SessionManager::SessionManager() : ofxOscRouterNode("/sessions") {
    addOscNodeAlias("/ses");
    addOscNodeAlias("/s");
}

//--------------------------------------------------------------
SessionManager::~SessionManager() {
    
}

//--------------------------------------------------------------
void SessionManager::update() {
    // nothin here
}

//--------------------------------------------------------------
void SessionManager::processOscMessage(const string& address, const ofxOscMessage& m) {
    cout << "got a message in the session manager " << address << endl;
}
