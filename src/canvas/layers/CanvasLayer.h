/*
 *  CanvasLayer.h
 *  livedraw
 *
 *  Created by Christopher P. Baker on 12/3/10.
 *  Copyright 2010 Murmur Labs LLC. All rights reserved.
 *
 */

#pragma once

#include "ofMain.h"
#include "ofxOscRouterNode.h"
#include "ofTexture.h"
#include "CanvasLayerTransform.h"
#include "CanvasLayerManager.h"
#include "ofxEnablerInterface.h"
#include "AssetManager.h"
#include "BufferPlayerAsset.h"
//#include "EffectsManager.h"
//#include "EffectsChain.h"

//class MediaAsset;
class BufferPlayerAsset;
class CanvasLayerManager;
class ofxLivedrawEngine;

class CanvasLayer : public ofxOscRouterNode, public ofxEnablerInterface {
	
public:

    CanvasLayer(CanvasLayerManager* clm, string name, ofPoint pos, CanvasLayer* layerParent);
	CanvasLayer(CanvasLayerManager* clm, string name, ofPoint pos);
	CanvasLayer(CanvasLayerManager* clm, string name);
    
	virtual ~CanvasLayer();
	
    void processOscMessage(const string& address, const ofxOscMessage& m);

    void init();
    
//	void setup();
	void update();
    
    void render();
    void draw();

    //void setSource(MediaAsset* src);
    //void setMask(MediaAsset* src);
    
    //void swapSourceMaskPlayers();
    
    BufferPlayerAsset* getSourcePlayer() {return sourcePlayer;};
    BufferPlayerAsset* getMaskPlayer()   {return maskPlayer;};

    
	CanvasLayerTransform* getTransform() { return &transform; };
	
    string getName();
    void setName(string name);
    
	/*
	bool addEffect(BaseCanvasEffect* effect);
	bool removeEffect(BaseCanvasEffect* effect);
	
	bool enableEffect(BaseCanvasEffect* effect);
	bool disableEffect(BaseCanvasEffect* effect);
	
	void pullEffectForward(BaseCanvasEffect* effect);
	void pushEffectBack(BaseCanvasEffect* effect);
	
	void sendEffectToFront(BaseCanvasEffect* effect);
	void sendEffectToBack(BaseCanvasEffect* effect);
     
	vector<BaseCanvasEffect*> getEffectsChain() { return effects;};
     */

	// settings	
	bool isSolo() {return solo;};
	bool setSolo(bool _solo) {solo = _solo;};

	bool isLocked() {return locked;};
	bool setLocked(bool _locked) {locked = _locked;};
	
    void onEnabled();
    void onDisabled();
    
    void setPosition(ofPoint pos);
    void setSize(int width, int height);
    void setRectangle(ofRectangle rect);
	
    //ofFbo* getFbo() {
    //    return &fbo;
   // }
    
    bool bringFoward();
    bool sendBackward();
    bool bringToFront();
    bool sendToBack();
    
    
    // node info
    CanvasLayer*         getLayerRoot();
    CanvasLayer*         getLayerParent();
    vector<CanvasLayer*> getLayerChildren();

    bool hasChild(CanvasLayer* layerChild);
    
    void setLayerParent(CanvasLayer* layerParent);
    
//    AssetManager* getAssetManager();
//    bool hasAssetManager();
    
    CanvasLayerManager* getCanvasLayerManager();
    ofxLivedrawEngine* getEngine();
    
private:
	
    
    ofFbo* fbo;
    
    string layerName;
    
//    EffectsManager* effectsManager;
    
//    EffectsChain effectsChain;
    
    BufferPlayerAsset* sourcePlayer;
    BufferPlayerAsset* maskPlayer;

	// Masker compositer;
	// width / height are all taken from the source
	CanvasLayerTransform transform;
	//vector<BaseCanvasEffect*> effects;
	
	bool solo;
	bool locked;
    
    ofColor label;
    
    // fbo
    bool useMSAA;

    CanvasLayerManager* layerManager;
    
    
    // node 
    CanvasLayer*         layerParent;
    vector<CanvasLayer*> layerChildren;
    
    // private
    vector<CanvasLayer*>::iterator findChild(CanvasLayer* layerChild);
    bool addLayerChild(CanvasLayer* layerChild);
    bool removeLayerChild(CanvasLayer* layerChild);

    
	// -> should this be in the gui?
	//ofColor labelColor;
		
};