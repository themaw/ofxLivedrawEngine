//
//  ImageMediaAsset.h
//  livedraw
//
//  Created by Christopher P. Baker on 4/12/11.
//  Copyright 2011 Murmur Labs LLC. All rights reserved.
//

#pragma  once

#include "BaseMediaAsset.h"

//--------------------------------------------------------------
class ImageMediaAsset : public BaseMediaAsset {
	
public:
	
	ImageMediaAsset(string assetURI) : BaseMediaAsset(MEDIA_ASSET_IMAGE, assetURI) {
		createCache();
	}
	~ImageMediaAsset() {
		ofLog(OF_LOG_VERBOSE, "Image asset " + assetID + " being destroyed");
	};
    
    void createCache();
    void close() {};

};

