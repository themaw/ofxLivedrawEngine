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
        
    void createCache();
    void close() {};

    
	//ofxVideoStreamer streamer;
};

