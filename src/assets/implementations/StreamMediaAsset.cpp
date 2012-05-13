//
//  StreamingMediaAsset.cpp
//  livedraw
//
//  Created by Christopher P. Baker on 4/12/11.
//  Copyright 2011 Murmur Labs LLC. All rights reserved.
//

#include "StreamMediaAsset.h"


//--------------------------------------------------------------
void StreamMediaAsset::createCache() {
		
    ofImage* of = new ofImage(); // this must be deleted by the owner!
    of->loadImage("application/cache/media/streams/default_stream.png");
    imageCache.push_back(of);
    
    ofLog(OF_LOG_VERBOSE, "Creating stream cache");
    
}