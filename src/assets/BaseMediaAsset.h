
#pragma once

#include "ofMain.h"

#include "ofxOscRouterBaseNode.h"
#include "AssetMetaData.h"

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

class BaseMediaAsset : virtual public ofxOscRouterBaseNode, public ofBaseUpdates {
public:
	BaseMediaAsset();
	virtual ~BaseMediaAsset();

    virtual void update() = 0;
    
    virtual bool dispose() = 0;
    virtual void processOscCommand(const string& command, const ofxOscMessage& m) = 0;

    set<string>& getOscNodeAliasesRef();
    const set<string>& getOscNodeAliasesRef() const;
    
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

    set<string>& getAliasesRef();
    
    string getFirstAlias() const;
    bool hasAlias(const string& alias) const;
    bool addAlias(const string& alias);
    bool removeAlias(const string& alias);
    
protected:
    set<string> aliases; // normal ascending order, reverse iterate later
    
    MediaAssetType assetType;

    bool canSource;
    bool canSink;
    bool canCache;
    bool diskAsset;
    
    AssetMetaData meta;
        
};







