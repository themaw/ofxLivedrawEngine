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
    addOscMethod("start");
    addOscMethod("stop");
    addOscMethod("size");
}

//--------------------------------------------------------------
StreamAsset::~StreamAsset() {
    // ofPtr!
}

//--------------------------------------------------------------
void StreamAsset::processOscCommand(const string& command, const ofxOscMessage& m) {
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
