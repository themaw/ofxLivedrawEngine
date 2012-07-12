
#pragma once

#include "ofMain.h"

#include "ofxOscRouterNode.h"
#include "AssetMetaData.h"

//#include "AssetManager.h"

class AssetManager;

enum MediaAssetType
{
    MEDIA_ASSET_UNDEFINED,
	MEDIA_ASSET_IMAGE,
	MEDIA_ASSET_MOVIE,
	MEDIA_ASSET_GRABBER,
	MEDIA_ASSET_STREAM,
    MEDIA_ASSET_BUFFER,
    MEDIA_ASSET_BUFFERPLAYER,
    MEDIA_ASSET_SYPHON
};



class BaseMediaAsset : virtual public ofxOscRouterNode {
public:
	BaseMediaAsset();
	virtual ~BaseMediaAsset();

    virtual bool dispose() = 0;
    virtual void processOscMessage(const string& address, const ofxOscMessage& m) = 0;

	MediaAssetType  getAssetType() const;   
	string          getAssetTypeString() const;

    string  getName() const;
    
    // interface capabilities
    bool isSource() const;
    bool isSink()   const;
    bool isCacheable() const;
    bool isDiskAsset() const;
    
    // utilities
    string toString() const;

//    bool hasAssetManager();
//    AssetManager* getAssetManager();
//    void setAssetManager(AssetManager* manager);
    
protected:
    string name;
    MediaAssetType assetType;

    bool canSource;
    bool canSink;
    bool canCache;
    bool diskAsset;
    
    AssetMetaData meta;
    
//    AssetManager* manager;

};







