
#pragma once

#include "ofMain.h"
#include "AssetMetaData.h"
#include "ofxOscRouterNode.h"
//#include "ofxVideoBuffer.h"
#include "FrameBuffer.h"
#include "ofxSimpleSet.h"

#include "Poco/URI.h"

class FrameBuffer;

enum MediaAssetType
{
    MEDIA_ASSET_EMPTY,
	MEDIA_ASSET_IMAGE,
	MEDIA_ASSET_VIDEO,
	MEDIA_ASSET_GRABBER,
	MEDIA_ASSET_STREAM,
    MEDIA_ASSET_BUFFER,
    MEDIA_ASSET_SYPHON
};

class MediaAsset : public ofxOscRouterNode {
	
public:
	
	MediaAsset(MediaAssetType assetType, string assetId, string assetURI);		// set image cache
	virtual ~MediaAsset();

    void processOscMessage(string pattern, ofxOscMessage& m);
    
	void            setAssetId(string id);
	string          getAssetId();
	Poco::URI       getAssetURI();
	MediaAssetType  getAssetType();	// this returns an enum type
	string          getAssetTypeString();	// this returns an enum type
	
    bool isEmptyAsset();
    bool isImageAsset();
    bool isVideoAsset();
    bool isGrabberAsset();
    bool isStreamAsset();
    bool isBufferAsset();
    bool isSyphonAsset();

    string toString();
    
    FrameBuffer* getBuffer();
    void setBuffer(FrameBuffer* _buffer);
    
    bool addAlias(string alias);
    bool removeAlias(string alias);
    bool containsAlias(string alias);
    vector<string> getAliases();
    
protected:
    
    ofxSimpleStringSet aliases;
    
    MediaAssetType assetType;
	Poco::URI	assetURI;		// the URI for the source (could be a stream or url, or id, etc)
	
	string assetId; // this is generated
	
    FrameBuffer* buffer;
};







