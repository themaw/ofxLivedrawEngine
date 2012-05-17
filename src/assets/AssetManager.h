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
    void setup();
    void update();
    void processOscMessage(string pattern, ofxOscMessage& m);
    
    MediaAsset* addAsset(MediaAssetType _assetType, string _assetURI);
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
    
protected:
    
    ofxLivedrawEngine* engine;

    
private:
	
    
	map<string,MediaAsset*> assets;

    map<MediaAsset*,FrameBuffer*>  buffBackedAssets;
    set<MediaAsset*,FrameBuffer*>  diskBackedAssets;
    
    
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
