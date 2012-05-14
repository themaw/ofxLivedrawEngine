//
//  StreamingMediaAsset.h
//  livedraw
//
//  Created by Christopher P. Baker on 4/12/11.
//  Copyright 2011 Murmur Labs LLC. All rights reserved.
//

#pragma once

#include "BaseMediaAsset.h"

//--------------------------------------------------------------
class StreamMediaAsset : public BaseMediaAsset {
	
public:
	
	StreamMediaAsset(string assetURI) : BaseMediaAsset(MEDIA_ASSET_STREAM, assetURI) {
		createCache();
	}
	~StreamMediaAsset() {}

    void update();
    
    // base video
    bool isFrameNew() {};
	void close() {};
    
    // has pixels
    unsigned char * getPixels() {};
	ofPixels & getPixelsRef() {};
        
    void createCache();

    // username
    // password
    
    
	//ofxVideoStreamer streamer;
};

