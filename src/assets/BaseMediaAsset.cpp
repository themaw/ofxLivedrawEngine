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
    buffer = NULL;
    
    addOscMethod("/open");
    

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
string MediaAsset::getAssetTypeString() {
    
    switch (assetType) {
        case MEDIA_ASSET_EMPTY:
            return "EMPTY";
            break;
        case MEDIA_ASSET_IMAGE:
            return "IMAGE";
            break;
        case MEDIA_ASSET_VIDEO:
            return "VIDEO";
            break;
        case MEDIA_ASSET_GRABBER:
            return "GRABBER";
            break;
        case MEDIA_ASSET_STREAM:
            return "STREAM";
            break;
        case MEDIA_ASSET_BUFFER:
            return "BUFFER";
            break;
        case MEDIA_ASSET_SYPHON:
            return "SYPHON";
            break;
        default:
            return "UNKNOWN";
            break;
    }
    
    
}


//--------------------------------------------------------------
bool MediaAsset::isEmptyAsset() {
    return assetType == MEDIA_ASSET_EMPTY;
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

//--------------------------------------------------------------
bool MediaAsset::addAlias(string alias) {
    return aliases.add(alias);
}

//--------------------------------------------------------------
bool MediaAsset::removeAlias(string alias) {
    return aliases.remove(alias);
}

//--------------------------------------------------------------
bool MediaAsset::containsAlias(string alias) {
    return aliases.contains(alias);
}


FrameBuffer* MediaAsset::getBuffer() {
    return buffer;
}
void MediaAsset::setBuffer(FrameBuffer* _buffer) {
    buffer = _buffer;
}

string MediaAsset::toString() {
    stringstream ss;
    ss << "----------------" << endl;
    ss << "MEDIA ASSET:" << endl;
    ss << "\tTYPE="     << getAssetTypeString() << endl;
    ss << "\tID="       << getAssetId() << endl;
    ss << "\tURL="      << getAssetURI().toString() << endl;
    ss << "\tAliases="  << ofToString(aliases.toArray()) << endl;
    
    return ss.str();
}

vector<string> MediaAsset::getAliases() {
    return aliases.toArray();
}


