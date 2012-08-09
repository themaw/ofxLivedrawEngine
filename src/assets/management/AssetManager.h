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

#pragma once

#include "ofMain.h"
#include "ofxXmlSettings.h"

#include "ofxLivedrawEngineInterface.h"

#include "ofxOscRouterNode.h"
#include "CacheProvider.h"
#include "DiskBasedAsset.h"
#include "CacheableAsset.h"

#include "BaseMediaAsset.h"
#include "ImageAsset.h"
#include "MovieAsset.h"
#include "BufferAsset.h"
#include "BufferPlayerAsset.h"
#include "GrabberAsset.h"
#include "StreamAsset.h"
#include "SyphonAsset.h"

//class BaseMediaAsset;
//class ImageAsset;
//class MovieAsset;
//class BufferAsset;
//class BufferPlayerAsset;
//class GrabberAsset;
//class StreamAsset;
//class SyphonAsset;

//class ofxLivedrawEngine;  // we only use the pointer below, so no need to include

class AssetManager : public ofxOscRouterNode, 
                     public CacheProvider

{
public:
    //--------------------------------------------------------------
	AssetManager();
	virtual ~AssetManager();

    //--------------------------------------------------------------
    void update();

    //--------------------------------------------------------------
    void processOscCommand(const string& command, const ofxOscMessage& m);

    ofxLivedrawEngineInterface* getEngineInterface() { return engine;}
    void setEngineInterface(ofxLivedrawEngineInterface* _engine) {engine = _engine;}
    
protected:
    
    ofxLivedrawEngineInterface* engine;

    //--------------------------------------------------------------
    bool hasAlias(const string& alias);
    //bool addAlias(BaseMediaAsset* asset, string alias);
    //bool removeAlias(string alias);
    //bool removeAliasesForAsset(BaseMediaAsset* asset);
    //bool changeAlias(string fromAlias, string toAlias);
    //vector<string> getAliases(BaseMediaAsset* asset);
    
    //--------------------------------------------------------------
    
    ImageAsset*         addImage(const string& name, const string& filename);
    MovieAsset*         addMovie(const string& name, const string& filename);
    StreamAsset*        addStream(const string& name,
                                  StreamType type,
                                  const string& url,
                                  const string& username,
                                  const string& password);
    BufferAsset*        addBuffer(const string& name, int size, ofxVideoBufferType t);
    BufferPlayerAsset*  addBufferPlayer(const string& name);
    GrabberAsset*       addGrabber(const string& name, int devId, int width, int height);
    SyphonAsset*        addSyphon(const string& name);
    
    //--------------------------------------------------------------
    BaseMediaAsset* getAsset(string alias);

    //--------------------------------------------------------------
    bool queueRegisterAsset(BaseMediaAsset* asset);
    bool queueUnregisterAsset(const string& alias);
    bool queueUnregisterAsset(BaseMediaAsset* asset);
    
    //--------------------------------------------------------------
    bool attachSourceToSink(const string& sourceAlias, const string& sinkAlias);
    bool attachSourceToSink(BaseMediaAsset* sourceAsset, BaseMediaAsset* sinkAsset);

    //--------------------------------------------------------------
    bool cacheAsset(CacheableAsset* asset);
    bool uncacheAsset(CacheableAsset* asset);

    bool startAsset(const string& alias);
    bool stopAsset(const string& alias);
    
    //--------------------------------------------------------------
	void loadAssets();
    
    void loadFilesAssets();
    void loadGrabberAssets(); 
    void loadStreamAssets();
	void loadSyphonAssets();
    
    int getTotalNumAssets();
    int getTotalNumAssets(MediaAssetType assetType);
    int getNumAssetsInRegisterQueue(MediaAssetType assetType);
    int getNumAssetsInUnregisterQueue(MediaAssetType assetType);
    int getNumAssetsInSet(MediaAssetType assetType, set<BaseMediaAsset*> _assets);

    
    
	//  TODO: for file watchers	
	//	void onNewAsset(MediaAsset* asset);

    
    void dump();    

private:

    void processQueues();
    void updateAssets();
    
    // these are private.
    bool registerAsset(BaseMediaAsset* asset);
    bool unregisterAsset(BaseMediaAsset* asset);

    string validateAssetId(const string& name);

    set<BaseMediaAsset*> registerQueue; // items are scheduled for registration here.
    set<BaseMediaAsset*> unregisterQueue; // items are scheduled for removal here.
    
	set<BaseMediaAsset*> assets;   // this is the actual collection of assets that have been allocated
	set<BaseMediaAsset*>::iterator assetsIter;   // this is the actual collection of assets that have been allocated
    
    map<string,BaseMediaAsset*> assetAliases;   // this is a mapping of names / aliases back to the asset itself
    
    ofDirectory dir;
    
};
