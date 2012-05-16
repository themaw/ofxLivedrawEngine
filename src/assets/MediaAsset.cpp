/*
 *  MediaAsset.cpp
 *  livedraw
 *
 *  Created by Christopher P. Baker on 3/11/11.
 *  Copyright 2011 Murmur Labs LLC. All rights reserved.
 *
 */

#include "MediaAsset.h"

//--------------------------------------------------------------
MediaAsset::MediaAsset(MediaAssetType _assetType, string _assetId, string _assetURI) : 
ofxOscRouterNode("/" + _assetId ) {
    assetId = _assetId;
	assetType = _assetType;
	assetURI = Poco::URI(_assetURI); // create the uri from the loaded asset
}

//--------------------------------------------------------------
MediaAsset::~MediaAsset() {}

//--------------------------------------------------------------
void MediaAsset::processOscMessage(string pattern, ofxOscMessage& m) {
    cout << "MEDIA ASSET OSC NOT IMPLEMENTED" << endl;
}

//--------------------------------------------------------------
void MediaAsset::setAssetId(string id) { 
    assetId = id; 
}

//--------------------------------------------------------------
string MediaAsset::getAssetId() { 
    return assetId; 
} 

//--------------------------------------------------------------
Poco::URI MediaAsset::getAssetURI(){ 
    return assetURI; 
}

//--------------------------------------------------------------
MediaAssetType MediaAsset::getAssetType() {
	return assetType;
}

//--------------------------------------------------------------
bool MediaAsset::isUnknownAsset() {
    return assetType == MEDIA_ASSET_UNKNOWN;
}
//--------------------------------------------------------------
bool MediaAsset::isImageAsset() {
    return assetType == MEDIA_ASSET_IMAGE;
}
//--------------------------------------------------------------
bool MediaAsset::isVideoAsset() {
    return assetType == MEDIA_ASSET_VIDEO;
}
//--------------------------------------------------------------
bool MediaAsset::isGrabberAsset() {
    return assetType == MEDIA_ASSET_GRABBER;
}
//--------------------------------------------------------------
bool MediaAsset::isStreamAsset() {
    return assetType == MEDIA_ASSET_STREAM;
}
//--------------------------------------------------------------
bool MediaAsset::isBufferAsset() {
    return assetType == MEDIA_ASSET_BUFFER;
}
//--------------------------------------------------------------
bool MediaAsset::isSyphonAsset() {
    return assetType == MEDIA_ASSET_SYPHON;
}


//--------------------------------------------------------------
//--------------------------------------------------------------
//--------------------------------------------------------------
//--------------------------------------------------------------
//--------------------------------------------------------------



