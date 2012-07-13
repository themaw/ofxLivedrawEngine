//
//  ImageAsset.cpp
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 7/12/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#include "ImageAsset.h"

//--------------------------------------------------------------
ImageAsset::ImageAsset(const string& _name, string _filename) : DiskBasedAsset(_filename) {
    assetType = MEDIA_ASSET_IMAGE;
    name      = _name;
    
    // go directly to the frame source file
    frame = ofPtr<ofImage>(new ofImage());
    frame->loadImage(filename);
}

//--------------------------------------------------------------
ImageAsset::~ImageAsset() {}

//--------------------------------------------------------------
void ImageAsset::processOscMessage(const string& pattern, const ofxOscMessage& m) {
    cout << "processing image asset " << getName() << endl;
}

//--------------------------------------------------------------
bool ImageAsset::dispose() {
    detachFromAllSinks();
    cout << "disposing of image " << getName() << endl;
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
