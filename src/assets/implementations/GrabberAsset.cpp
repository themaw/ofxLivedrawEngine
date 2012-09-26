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

#include "GrabberAsset.h"

//--------------------------------------------------------------
GrabberAsset::GrabberAsset(AssetManagerInterface* man, const string& _name, int _devId, int _width, int _height) : BaseMediaAsset(man){
    
    canSource = true;
    
    assetType = MEDIA_ASSET_GRABBER;

    addAlias(_name);
    
    width  = _width;
    height = _height;
    devId  = _devId;
    grabber = ofPtr<ofVideoGrabber>(new ofVideoGrabber());
    
    addOscMethod("open");
    addOscMethod("close");
    
    //        grabber->initGrabber(width, height);
}

//--------------------------------------------------------------
GrabberAsset::~GrabberAsset() {}

//--------------------------------------------------------------
void GrabberAsset::update() {
    if(grabber->isInitialized()) {
        grabber->update();
    }
    
    // everybody has some work to do
    ofxVideoSourceInterface::update();
}

//--------------------------------------------------------------
bool GrabberAsset::dispose() {
    detachFromSinks();
    return true;
}

//--------------------------------------------------------------
void GrabberAsset::processOscCommand(const string& command, const ofxOscMessage& m) {
    if(isMatch(command,"open")) {
        open();
    } else if(isMatch(command, "close")) {
        close();
    }
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
