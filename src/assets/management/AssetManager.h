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

#include "ofxOscRouterNode.h"
#include "CacheProvider.h"

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

class ofxLivedrawEngine;  // we only use the pointer below, so no need to include

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
    void processOscMessage(const string& pattern, const ofxOscMessage& m);

    //--------------------------------------------------------------
    bool hasAlias(string alias);
    bool addAlias(BaseMediaAsset* asset, string alias);
    bool removeAlias(string alias);
//    bool changeAlias(string fromAlias, string toAlias);
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
    bool cacheAsset(CacheableAsset* asset);
    bool uncacheAsset(CacheableAsset* asset);

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

    string generateAssetId(BaseMediaAsset* asset);

	ofxSimpleSet<BaseMediaAsset*>     assets;   // this is the actual collection of assets that have been allocated
    map<string,BaseMediaAsset*> assetAliases;   // this is a mapping of names / aliases back to the asset itself
    
    ofDirectory dir;
    
};
