//
//  StreamAsset.cpp
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 7/12/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#include "StreamAsset.h"

//--------------------------------------------------------------
StreamAsset::StreamAsset(const string& _name, StreamType _type, string _url, string _username, string _password) {
    assetType  = MEDIA_ASSET_STREAM;
    streamType = _type;
    name       = _name;
    url        = _url;
    username   = _username;
    password   = _password;
    
    isIpVideo = streamType == STREAM_TYPE_IPCAM;
    
    if(isIpVideo) {
        ipcam = ofPtr<ofxIpVideoGrabber>(new ofxIpVideoGrabber());
        ipcam->setURI(url);
        ipcam->setUsername(username);
        ipcam->setPassword(password);
    } else {
        qtcam = ofPtr<ofVideoPlayer>(new ofVideoPlayer());
        qtcam->loadMovie(url); // TODO: construct correct user/pass string
    }
    
    addOscMethod("/open");
    addOscMethod("/close");
    addOscMethod("/start");
    addOscMethod("/stop");
    addOscMethod("/size");
}

//--------------------------------------------------------------
StreamAsset::~StreamAsset() {
    // ofPtr!
}

//--------------------------------------------------------------
void StreamAsset::processOscMessage(const string& pattern, const ofxOscMessage& m) {
    cout << "Stream asset processing osc." << endl;
}

//--------------------------------------------------------------
bool StreamAsset::dispose() {
    detachFromAllSinks();
    cout << "disposing of stream " << getName() << endl;
}

//--------------------------------------------------------------
bool StreamAsset::isFrameNew() {
    if(isIpVideo) {
        return ipcam->isFrameNew();
    } else {
        return qtcam->isFrameNew();
    }
}

//--------------------------------------------------------------
ofPixelsRef StreamAsset::getPixelsRef() {
    if(isIpVideo) {
        return ipcam->getPixelsRef();
    } else {
        return qtcam->getPixelsRef();
    }
}

//--------------------------------------------------------------
void StreamAsset::open()   {
    if(isIpVideo) {
        ipcam->connect();
    } else {
        qtcam->loadMovie(url);
    }
}

//--------------------------------------------------------------
void StreamAsset::close()  {
    if(isIpVideo) {
        ipcam->close();
    } else {
        qtcam->close();;
    }
}

//--------------------------------------------------------------
bool StreamAsset::isLoaded() {
    if(isIpVideo) {
        return ipcam->isConnected();
    } else {
        return qtcam->isLoaded();
    }
}

//--------------------------------------------------------------
string StreamAsset::getUrl() {
    return url;
}

//--------------------------------------------------------------
string StreamAsset::getUsername() {
    return username;
}

//--------------------------------------------------------------
string StreamAsset::getPassword() {
    return password;
}

//--------------------------------------------------------------
StreamType StreamAsset::getStreamType() {
    return streamType;
}
