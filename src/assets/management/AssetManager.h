
#pragma once

#include "ofMain.h"
#include "Poco/RegularExpression.h"
#include "ofxXmlSettings.h"
#include "ofxLivedrawEngine.h"


#include "BaseMediaAsset.h"
#include "AssetMetaData.h"

#include "ImageAsset.h"
#include "MovieAsset.h"
#include "BufferAsset.h"
#include "BufferPlayerAsset.h"
#include "GrabberAsset.h"
#include "StreamAsset.h"
#include "SyphonAsset.h"


#include "ofxOscRouterNode.h"

class BaseMediaAsset;
class BufferManager;
class ofxLivedrawEngine;

class AssetManager : public ofxOscRouterNode {
	
public:
    //--------------------------------------------------------------
	AssetManager();
	virtual ~AssetManager();

    //--------------------------------------------------------------
    void update();

    //--------------------------------------------------------------
    void processOscMessage(const string& pattern, const ofxOscMessage& m);

    //--------------------------------------------------------------
    bool hasAlias(string alias);
    bool addAlias(BaseMediaAsset* asset, string alias);
    bool removeAlias(string alias);
    bool changeAlias(string fromAlias, string toAlias);
    vector<string> getAliases(BaseMediaAsset* asset);
    
    //--------------------------------------------------------------
    ImageAsset*         addImage(string name, string filename);
    MovieAsset*         addMovie(string name, string filename);
    StreamAsset*        addStream(string name, StreamType type, string url, string username, string password);
    BufferAsset*        addBuffer(string name, int size, ofxVideoBufferType t);
    BufferPlayerAsset*  addBufferPlayer(string name);
    GrabberAsset*       addGrabber(string name, int devId, int width, int height);
    SyphonAsset*        addSyphon(string name);
    
    //--------------------------------------------------------------
    BaseMediaAsset* getAsset(string string);

    //--------------------------------------------------------------
    bool registerAsset(BaseMediaAsset* asset);
    
    bool unregisterAsset(string alias);
    bool unregisterAsset(BaseMediaAsset* asset);
    
    //--------------------------------------------------------------
    bool attachSourceToSink(string sourceAlias, string sinkAlias);
    bool attachSourceToSink(BaseMediaAsset* sourceAsset, BaseMediaAsset* sinkAlias);

    //--------------------------------------------------------------
    bool cacheAsset(string alias);
    bool uncacheAsset(string alias);
    bool startAsset(string alias);
    bool stopAsset(string alias);
    
    //--------------------------------------------------------------
	void loadAssets();
    
    void loadFilesAssets();
    void loadGrabberAssets(); 
    void loadStreamAssets();
	void loadSyphonAssets();
    
	int getNumAssets();
	int getNumAssets(MediaAssetType assetType);
    
	//  TODO: for file watchers	
	//	void onNewAsset(MediaAsset* asset);

    void setEngine(ofxLivedrawEngine* _engine) {engine = _engine;};
    ofxLivedrawEngine* getEngine() {return engine;}    
    
    void dump();    
    
protected:
    
    ofxLivedrawEngine* engine;
    
private:
    //BufferManager* bufferManager;

    string generateAssetId(BaseMediaAsset* asset);

	ofxSimpleSet<BaseMediaAsset*>     assets;   // this is the actual collection of assets that have been allocated
    map<string,BaseMediaAsset*> assetAliases;   // this is a mapping of names / aliases back to the asset itself
    
    ofDirectory dir;
    
};
