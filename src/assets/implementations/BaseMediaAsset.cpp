/*
 *  BaseMediaAsset.cpp
 *  livedraw
 *
 *  Created by Christopher P. Baker on 3/11/11.
 *  Copyright 2011 Murmur Labs LLC. All rights reserved.
 *
 */

#include "BaseMediaAsset.h"

//--------------------------------------------------------------
BaseMediaAsset::BaseMediaAsset(MediaAssetType assetType, string _assetURI)		// set image cache
{
	this->assetType = assetType;
	this->assetURI = Poco::URI(_assetURI); // create the uri from the loaded asset
	
	// caching
//	cacheWidth = 80;
//	cacheHeight = 60;
//	isCached = false;
//	cacheFPS = 1;
	
	generateAssetID();
	
}

//--------------------------------------------------------------
BaseMediaAsset::~BaseMediaAsset()
{
	// anything here for the base class
//	clearCache();
}



//--------------------------------------------------------------
bool BaseMediaAsset::generateAssetID() {
	if(assetID.empty()) {
		assetID = assetURI.toString();
		return true;
	} else{
		ofLog(OF_LOG_WARNING, "Asset ID already set to " + assetID);
		return false;	
	}
}

//--------------------------------------------------------------
void BaseMediaAsset::setAssetId(string id) { 
    assetID = id; 
}

//--------------------------------------------------------------
string BaseMediaAsset::getAssetId() { 
    return assetID; 
} 

//--------------------------------------------------------------
Poco::URI BaseMediaAsset::getAssetURI(){ 
    return assetURI; 
}

//--------------------------------------------------------------
MediaAssetType BaseMediaAsset::getAssetType() {
	return assetType;
}

// buffer attachments
//--------------------------------------------------------------
void BaseMediaAsset::attachBuffer(ofxVideoBuffer* buffer) {
    buffers.insert(buffer);
}

//--------------------------------------------------------------
void BaseMediaAsset::detatchBuffer(ofxVideoBuffer* buffer) {
    buffers.erase(buffers.find(buffer));
}

//--------------------------------------------------------------
bool BaseMediaAsset::hasBuffers() {
    return !buffers.empty();
}

//--------------------------------------------------------------
int  BaseMediaAsset::getNumBuffers() {
    return (int)buffers.size();
}


////--------------------------------------------------------------
//void BaseMediaAsset::setCacheImageSize(int w, int h)
//{
//	if(w != cacheWidth || h != cacheHeight) {
//		cacheWidth = w;
//		cacheHeight = h;
//		createCache();  // recreate cache
//	} else {
//		ofLog(OF_LOG_WARNING, "Cache size not changed.");
//	}
//	
//}
//
////--------------------------------------------------------------
//void BaseMediaAsset::setCacheFPS(int _fps)
//{
//	if(_fps != cacheFPS) {
//		cacheFPS = _fps;
//		createCache(); // recreate cache
//	} else {
//		ofLog(OF_LOG_WARNING, "Cache FPS not changed.");
//	}
//}
//
////--------------------------------------------------------------
//float BaseMediaAsset::getCacheFPS() 
//{
//	return cacheFPS;
//}
//
////--------------------------------------------------------------
//ofImage* BaseMediaAsset::getCacheImage() { 
//	return imageCache.empty() ? NULL : imageCache[0]; // return the first image
//} 
//
////--------------------------------------------------------------
//void BaseMediaAsset::clearCache() {
//	if (isCached && !imageCache.empty()) {
//		imageCache.clear(); // should call all of the ofImage destructors
//	}
//}


//--------------------------------------------------------------
//--------------------------------------------------------------
//--------------------------------------------------------------
//--------------------------------------------------------------
//--------------------------------------------------------------



