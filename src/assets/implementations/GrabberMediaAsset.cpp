//
//  GrabberMediaAsset.cpp
//  livedraw
//
//  Created by Christopher P. Baker on 4/12/11.
//  Copyright 2011 Murmur Labs LLC. All rights reserved.
//

#include "GrabberMediaAsset.h"


//--------------------------------------------------------------
void GrabberMediaAsset::createCache() {
    // TODO: generate or load previews here

    ofImage* of = new ofImage(); // this must be deleted by the owner!
    of->loadImage("application/cache/media/grabbers/default_grabber.png");
    imageCache.push_back(of);

    ofLog(OF_LOG_VERBOSE, "Creating grabber cache");
}