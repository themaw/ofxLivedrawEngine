//
//  GrabberAsset.cpp
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 7/12/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#include "GrabberAsset.h"

//--------------------------------------------------------------
GrabberAsset::GrabberAsset(const string& _name, int _devId, int _width, int _height) {
    assetType = MEDIA_ASSET_GRABBER;
    name   = _name;
    width  = _width;
    height = _height;
    devId  = _devId;
    grabber = ofPtr<ofVideoGrabber>(new ofVideoGrabber());
    
    //        grabber->initGrabber(width, height);
}

//--------------------------------------------------------------
GrabberAsset::~GrabberAsset() {}

//--------------------------------------------------------------
bool GrabberAsset::dispose() {
    detachFromAllSinks();
    close();
}

//--------------------------------------------------------------
void GrabberAsset::processOscMessage(const string& pattern, const ofxOscMessage& m) {
    cout << "cout process osc message" << endl;
}

//--------------------------------------------------------------
bool GrabberAsset::isFrameNew() {
    return grabber->isFrameNew();
}

//--------------------------------------------------------------
ofPixelsRef GrabberAsset::getPixelsRef() {
    return grabber->getPixelsRef();
}

//--------------------------------------------------------------
void GrabberAsset::open() {
    grabber->setDeviceID(devId);
    grabber->initGrabber(width, height);
}

//--------------------------------------------------------------
void GrabberAsset::close() {
    grabber->close();
}

//--------------------------------------------------------------
bool GrabberAsset::isLoaded() {
    return grabber->isInitialized();
}
