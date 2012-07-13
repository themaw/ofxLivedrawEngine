//
//  SyphonAsset.cpp
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 7/12/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#include "SyphonAsset.h"

SyphonAsset::SyphonAsset(const string& _name) {
    assetType = MEDIA_ASSET_SYPHON;
    name = _name;
    
    syphonClient = ofPtr<ofxSyphonVideoClient>(new ofxSyphonVideoClient());
    syphonClient->setup();
    syphonClient->setApplicationName("ofxLivedrawEngine Asset");
    syphonClient->setServerName("");
    
}

SyphonAsset::~SyphonAsset() {}

void SyphonAsset::processOscMessage(const string& pattern, const ofxOscMessage& m) {
    
}

bool SyphonAsset::dispose() {
    detachFromAllSinks();
    cout << "disposing of syphon " << getName() << endl;
}

bool SyphonAsset::isFrameNew() {
    return syphonClient->isFrameNew();
}

ofPixelsRef SyphonAsset::getPixelsRef() {
    return syphonClient->getPixelsRef();
}

void SyphonAsset::open() {
    syphonClient->open();
}

void SyphonAsset::close() {
    syphonClient->close();
}

bool SyphonAsset::isLoaded() {
    return syphonClient->isConnected();
}
