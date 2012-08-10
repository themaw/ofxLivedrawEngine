/*==============================================================================
 
 Copyright (c) 2010, 2011, 2012 Christopher Baker <http://christopherbaker.net>
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 
 ==============================================================================*/

#include "StreamAsset.h"

//--------------------------------------------------------------
StreamAsset::StreamAsset(const string& _name, StreamType _type, string _url, string _username, string _password) {
    canSource = true;
    
    assetType  = MEDIA_ASSET_STREAM;
    streamType = _type;

    addAlias(_name);
    
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
    
    addOscMethod("open");
    addOscMethod("close");
//    addOscMethod("size");  // TODO: this is tricky to do 
}

//--------------------------------------------------------------
StreamAsset::~StreamAsset() {
    // ofPtr!
}

void StreamAsset::update() {
    if(isIpVideo) {
        ipcam->update();
    } else {
        qtcam->update();
    }

    // everybody has some work
    ofxVideoSourceInterface::update();
}
//--------------------------------------------------------------
void StreamAsset::processOscCommand(const string& command, const ofxOscMessage& m) {

    if(isMatch(command,"open")) {
        open();
    } else if(isMatch(command, "close")) {
        close();
    }
}

//--------------------------------------------------------------
bool StreamAsset::dispose() {
    cout << "disposing of stream " << getName() << ":" << getUrl() << endl;
    detachFromSinks();
    return true;
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
void StreamAsset::open() {
    cout << "opening stream asset " << getName() << ":" << getUrl() << endl;
    if(isIpVideo) {
        ipcam->connect();
    } else {
        qtcam->loadMovie(url);
    }
}

//--------------------------------------------------------------
void StreamAsset::close()  {
    cout << "closing stream asset " << getName()  << ":" << getUrl() << endl;

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
