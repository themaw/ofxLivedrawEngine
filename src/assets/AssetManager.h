/*
 *  SourceManager.h
 *  livedraw
 *
 *  Created by Christopher P. Baker on 1/15/11.
 *  Copyright 2011 Murmur Labs LLC. All rights reserved.
 *
 */

#pragma once

#include "ofMain.h"
#include "Poco/RegularExpression.h"
#include "ofxXmlSettings.h"
#include "ofxLivedrawEngine.h"

#include "MediaAsset.h"
#include "FrameBuffer.h"
#include "ofxOscRouterNode.h"
 
class ofxLivedrawEngine;

class AssetManager : public ofxOscRouterNode {
	
public:
	AssetManager();
	virtual ~AssetManager();
    void update();
    void processOscMessage(string pattern, ofxOscMessage& m);
    
    MediaAsset* addAsset(MediaAssetType _assetType, string _assetName, string _assetURI);
    MediaAsset* removeAsset(string alias);

    MediaAsset* addImage(string alias, string filename);
    MediaAsset* addVideo(string alias, string filename);
    MediaAsset* addStream(string alias, string url, string username, string password);
    
    
    
    bool addAssetAlias(MediaAsset* asset, string alias);
    
    bool removeAsset(MediaAsset* asset);

	void loadAssets();
    
    void loadFilesAssets();
    void loadGrabberAssets(); 
    void loadStreamAssets();
	void loadSyphonAssets();
    
	int getNumAssets();

    int getNumFileAssets();
	int getNumImageAssets();
	int getNumVideoAssets();
	int getNumGrabberAssets();
	int getNumStreamAssets();
	int getNumBufferAssets();
    int getNumSyphonAssets();

	//  TODO: for file watchers	
	//	void onNewAsset(MediaAsset* asset);

    MediaAsset* getAsset(string id);
    
    bool hasId(string id);

    FrameBuffer* getAssetBackedBuffer(MediaAsset* asset, bool wantDiskBackedAsset) {
        
        if(wantDiskBackedAsset) {
            // first we check and see if there is a buffer backed asset to tap
            
        } else {
            
        }
        
    }

    void setEngine(ofxLivedrawEngine* _engine) {engine = _engine;};
    ofxLivedrawEngine* getEngine() {return engine;}    
    
    void dump() {

        vector<MediaAsset*> vec = assets.toArray();
        for(int i = 0; i < vec.size(); i++) {
            cout << vec[i] << endl;
        }
    }
    
    
protected:
    
    ofxLivedrawEngine* engine;
    
private:
	
	ofxSimpleSet<MediaAsset*>     assets;         // this is the actual collection of assets that have been allocated
    map<string,MediaAsset*> assetAliases;   // this is a mapping of names / aliases back to the asset itself
    

    //set<MediaAsset*,FrameBuffer*>  buffBackedAssets;
    //set<MediaAsset*,FrameBuffer*>  diskBackedAssets;
    
    
    /*
    mymap['a']=50;
    mymap['b']=100;
    mymap['c']=150;
    mymap['d']=200;
    
    it=mymap.find('b');
    mymap.erase (it);
    mymap.erase (mymap.find('d'));
    
    // print content:
    cout << "elements in mymap:" << endl;
    cout << "a => " << mymap.find('a')->second << endl;
    cout << "c => " << mymap.find('c')->second << endl;
     */

    
    bool generateAssetId(MediaAssetType _assetType, string _assetURI, string& assetId);

    ofDirectory dir;
    
};
