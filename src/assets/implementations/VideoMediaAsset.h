//
//  VideoMediaAsset.h
//  livedraw
//
//  Created by Christopher P. Baker on 4/12/11.
//  Copyright 2011 Murmur Labs LLC. All rights reserved.
//

#pragma once

#include "BaseMediaAsset.h"

//--------------------------------------------------------------
class VideoMediaAsset : public BaseMediaAsset {
	
public:
	
	VideoMediaAsset(string assetURI) : BaseMediaAsset(MEDIA_ASSET_VIDEO, assetURI) {
		createCache();
	}
	~VideoMediaAsset() {}
	
	void createCache();
    void close() {};

	
};

