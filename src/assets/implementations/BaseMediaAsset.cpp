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
	cacheWidth = 80;
	cacheHeight = 60;
	isCached = false;
	cacheFPS = 1;
	
	generateAssetID();
	
}

//--------------------------------------------------------------
BaseMediaAsset::~BaseMediaAsset()
{
	// anything here for the base class
	clearCache();
}

//--------------------------------------------------------------
bool BaseMediaAsset::generateAssetID()
{
	if(assetID.empty()) {
		assetID = assetURI.toString();
		return true;
	} else{
		ofLog(OF_LOG_WARNING, "Asset ID already set to " + assetID);
		return false;	
	}
	

}

//--------------------------------------------------------------
void BaseMediaAsset::setAssetId(string id) { assetID = id; }
//--------------------------------------------------------------
string BaseMediaAsset::getAssetId() { return assetID; } 
//--------------------------------------------------------------
Poco::URI BaseMediaAsset::getAssetURI(){ return assetURI; }
//--------------------------------------------------------------
//--------------------------------------------------------------
//--------------------------------------------------------------



//--------------------------------------------------------------
enum MediaAssetType BaseMediaAsset::getAssetType() 
{
	return assetType;
}

//--------------------------------------------------------------
void BaseMediaAsset::setCacheImageSize(int w, int h)
{
	if(w != cacheWidth || h != cacheHeight) {
		cacheWidth = w;
		cacheHeight = h;
		createCache();  // recreate cache
	} else {
		ofLog(OF_LOG_WARNING, "Cache size not changed.");
	}
	
}

//--------------------------------------------------------------
void BaseMediaAsset::setCacheFPS(int _fps)
{
	if(_fps != cacheFPS) {
		cacheFPS = _fps;
		createCache(); // recreate cache
	} else {
		ofLog(OF_LOG_WARNING, "Cache FPS not changed.");
	}
}

//--------------------------------------------------------------
float BaseMediaAsset::getCacheFPS() 
{
	return cacheFPS;
}

//--------------------------------------------------------------
ofImage* BaseMediaAsset::getCacheImageAtPosition(float f)
{
	if(!imageCache.empty()) {
		return imageCache.size() == 1 ? imageCache[0] : (imageCache[(int) (CLAMP(f,0,1) * imageCache.size())]);
	} else {
		return NULL;
	}
}

//--------------------------------------------------------------
ofImage* BaseMediaAsset::getCacheImage() { 
	return imageCache.empty() ? NULL : imageCache[0]; // return the first image
} 

//--------------------------------------------------------------
void BaseMediaAsset::clearCache() {
	if (isCached && !imageCache.empty()) {
		imageCache.clear(); // should call all of the ofImage destructors
	}
}

// ACTIVE INSTANCES
//--------------------------------------------------------------
bool BaseMediaAsset::removeActiveInstance(BaseMediaSource* instance)
{
	std::vector<BaseMediaSource*>::iterator result;
	result = find(activeInstances.begin(), activeInstances.end(), instance);
	activeInstances.erase(result);
	
}

//--------------------------------------------------------------
bool BaseMediaAsset::addActiveInstance(BaseMediaSource* instance)
{
	if (!hasInstance(instance)) {
		activeInstances.push_back(instance);
		return true;
	} else {
		ofLog(OF_LOG_ERROR, "Instance was already listed.");
		return false;
	}
}
//--------------------------------------------------------------
vector<BaseMediaSource*>* BaseMediaAsset::getInstances()
{
	return &activeInstances;
}

//--------------------------------------------------------------
bool BaseMediaAsset::hasAnyActiveInstances()
{
	return !activeInstances.empty();
}

//--------------------------------------------------------------
bool BaseMediaAsset::hasInstance(BaseMediaSource* instance)
{
	std::vector<BaseMediaSource*>::iterator result;
	result = find(activeInstances.begin(), activeInstances.end(), instance);
	return result != activeInstances.end();
}


//--------------------------------------------------------------
//--------------------------------------------------------------
//--------------------------------------------------------------
//--------------------------------------------------------------
//--------------------------------------------------------------



