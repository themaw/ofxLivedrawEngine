//
//  SyphonMediaAsset.h
//  livedraw
//
//  Created by Christopher P. Baker on 4/12/11.
//  Copyright 2011 Murmur Labs LLC. All rights reserved.
//

#pragma once

#include "BaseMediaAsset.h"

//--------------------------------------------------------------
class SyphonMediaAsset : public BaseMediaAsset {
	
public:
	
	SyphonMediaAsset(string assetURI) : BaseMediaAsset(MEDIA_ASSET_SYPHON, assetURI) {
		createCache();
	}
	~SyphonMediaAsset() {}
        
    void createCache();
    void close() {};

    
	//ofxVideoStreamer streamer;
};

