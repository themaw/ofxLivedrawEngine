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

#include "ImageAsset.h"

//--------------------------------------------------------------
ImageAsset::ImageAsset(const string& _name, string _filename) : DiskBasedAsset(_filename) {
    assetType = MEDIA_ASSET_IMAGE;
    addAlias(_name);
//    name      = _name;
    
    // go directly to the frame source file
    frame = ofPtr<ofImage>(new ofImage());
    frame->loadImage(filename);
}

//--------------------------------------------------------------
ImageAsset::~ImageAsset() {}

//--------------------------------------------------------------
void ImageAsset::update() {
    // everybody has some work to do
    
    
    
    // everybod has some work to do
    DiskBasedAsset::update();
    FrameSourceAsset::update();
}

//--------------------------------------------------------------
void ImageAsset::processOscCommand(const string& command, const ofxOscMessage& m) {
    cout << "processing image asset " << getName() << endl;
}

//--------------------------------------------------------------
bool ImageAsset::dispose() {
    cout << "disposing of image " << getName() << endl;
    return detachFromAllSinks();
}

//--------------------------------------------------------------
bool ImageAsset::isFrameNew() {
    return false; // we loaded it once.
}

//--------------------------------------------------------------
ofPixelsRef ImageAsset::getPixelsRef() {
    return frame->getPixelsRef();
}

//--------------------------------------------------------------
void ImageAsset::open() {
    ofLog(OF_LOG_NOTICE, "ImageAsset::open() : open not implemented.");
}

//--------------------------------------------------------------
void ImageAsset::close() {
    ofLog(OF_LOG_NOTICE, "ImageAsset::close() : open not implemented.");
}

//--------------------------------------------------------------
bool ImageAsset::isLoaded() {
    return true;
}
