/*==============================================================================
 
 Copyright (c) 2010, 2011, 2012 Christopher Baker <http://christopherbaker.net>
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 
 ==============================================================================*/

#include "BaseMediaAsset.h"

//--------------------------------------------------------------
BaseMediaAsset::BaseMediaAsset() {
//    manager = NULL;
    
    name      = "UNDEFINED";
	assetType = MEDIA_ASSET_UNDEFINED;
    
    canSource = false;
    canSink   = false;
    canCache  = false;
    diskAsset = false;
    
    addOscChild(&meta);
}

//--------------------------------------------------------------
BaseMediaAsset::~BaseMediaAsset() {}

string BaseMediaAsset::getName() const {
    return name;
}

//--------------------------------------------------------------
MediaAssetType BaseMediaAsset::getAssetType() const {
	return assetType;
}

//--------------------------------------------------------------
string BaseMediaAsset::getAssetTypeString() const {
    switch (assetType) {
        case MEDIA_ASSET_UNDEFINED:
            return "UNDEFINED";
        case MEDIA_ASSET_IMAGE:
            return "IMAGE";
        case MEDIA_ASSET_MOVIE:
            return "MOVIE";
        case MEDIA_ASSET_GRABBER:
            return "GRABBER";
        case MEDIA_ASSET_STREAM:
            return "STREAM";
        case MEDIA_ASSET_BUFFER:
            return "BUFFER";
        case MEDIA_ASSET_BUFFERPLAYER:
            return "BUFFERPLAYER";
        case MEDIA_ASSET_SYPHON:
            return "SYPHON";
        default:
            ofLog(OF_LOG_ERROR, "BaseMediaAsset::getAssetTypeString() - unknwon asset type " + ofToString(assetType));
            return "UNKNOWN";
    }
}


//--------------------------------------------------------------
bool BaseMediaAsset::isSource() const {
    return canSource;
}

//--------------------------------------------------------------
bool BaseMediaAsset::isSink() const {
    return canSink;
}

//--------------------------------------------------------------
bool BaseMediaAsset::isCacheable() const {
    return canCache;
}

//--------------------------------------------------------------
bool BaseMediaAsset::isDiskAsset() const {
    return diskAsset;
}


////--------------------------------------------------------------
//bool MediaAsset::isCached() {
//    return cacheBuffer != NULL;
//}
//
//void MediaAsset::setBuffer(FrameBuffer* _buffer) {
//    bufferAsset = _buffer;
//}
//
//FrameBuffer* MediaAsset::getBuffer() {
//    return bufferAsset;
//}
//
//FrameBuffer* MediaAsset::getCache() {
//    if(!isLiveAsset()) {
//        return cacheBuffer;
//    } else {
//        cout << "you can't cache a live data type." << endl;   
//        return NULL;
//    }
//}

////--------------------------------------------------------------
//bool MediaAsset::setCache(FrameBuffer* buffer) {
//    if(!isLiveAsset()) {
//        cacheBuffer = buffer;
//        return true;
//    } else {
//        cout << "you can't cache a live data type." << endl;   
//        return false;
//    }
//}
//
////--------------------------------------------------------------
//bool MediaAsset::removeCache() {
//    if(!isLiveAsset()) {
//        if(isCached()) {
//            cacheBuffer = NULL;
//            return true;
//        } else {
//            cout << "not cached" << endl;
//            return false;
//        }
//    } else {
//        cout << "you can't cache a live data type." << endl;   
//        return false;
//    }
//}

//--------------------------------------------------------------
string BaseMediaAsset::toString() const {
    stringstream ss;
    ss << "MEDIA ASSET:" << endl;
    ss << "\tgetType()     = " << getAssetTypeString() << endl;
    ss << "\tgetName()     = " << getName() << endl;
    ss << "\tisCacheable() = " << (isCacheable() ? "TRUE" : "FALSE") << endl;
    ss << "\tisSource()    = " << (isSource()    ? "TRUE" : "FALSE") << endl;
    ss << "\tisSink()      = " << (isSink()      ? "TRUE" : "FALSE") << endl;
    return ss.str();
}

////--------------------------------------------------------------
//bool BaseMediaAsset::hasAssetManager() {
//    return manager != NULL;
//}
//
////--------------------------------------------------------------
//AssetManager* BaseMediaAsset::getAssetManager() {
//    return manager;
//}
//
////--------------------------------------------------------------
//void BaseMediaAsset::setAssetManager(AssetManager* _manager) {
//    manager = _manager;
//}
//

