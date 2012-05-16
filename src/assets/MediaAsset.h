
#pragma once

#include "ofMain.h"
#include "AssetMetaData.h"
#include "ofxOscRouterNode.h"
#include "ofxVideoBuffer.h"

#include "Poco/URI.h"

enum MediaAssetType
{
    MEDIA_ASSET_UNKNOWN,
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
	
    bool isUnknownAsset();
    bool isImageAsset();
    bool isVideoAsset();
    bool isGrabberAsset();
    bool isStreamAsset();
    bool isBufferAsset();
    bool isSyphonAsset();

    // buffer attachments
    //void attachBuffer(ofxVideoBuffer* buffer);
    //void detatchBuffer(ofxVideoBuffer* buffer);
    //bool hasBuffers();
    //int  getNumBuffers();

    /*
    AssetMetaData&  getAssetMetaData();
    void            setAssetMetaData(AssetMetaData data);

	virtual void    createCache() = 0;         // caches are created differently depending on the source
	void            clearCache();			    // removes all of the cached images
     
	void     setCacheImageSize(int width, int height);	// set the size of the images to cache
	ofImage* getCacheImage();					// get the default preview image
     */
	

    
protected:

    //set<ofxVideoBuffer*> buffers;
    
    MediaAssetType assetType;
	Poco::URI	assetURI;		// the URI for the source (could be a stream or url, or id, etc)
	
	string assetId; // this is generated
	
	// cache
	//int cacheWidth, cacheHeight; // should always be small
	//vector<ofImage*> imageCache;
	
	// meta data keywords
	//AssetMetaData meta;
	
	//ofxVideoBuffer* buffer;
    
};







