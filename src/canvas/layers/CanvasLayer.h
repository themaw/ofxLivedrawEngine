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
#include "EnablerInterface.h"
#include "AssetManager.h"
#include "FrameBufferPlayer.h"
//#include "EffectsManager.h"
//#include "EffectsChain.h"

class FrameBufferPlayer;
class CanvasLayerManager;

class CanvasLayer : public ofxOscRouterNode, public Enabler {
	
public:

    CanvasLayer(CanvasLayerManager* clm, string name, ofPoint pos, CanvasLayer* layerParent);
	CanvasLayer(CanvasLayerManager* clm, string name, ofPoint pos);
	CanvasLayer(CanvasLayerManager* clm, string name);
    
	virtual ~CanvasLayer();
	
    void processOscMessage(string address, ofxOscMessage& m);

    void init();
    
	void setup();
	void update();
    
    void render();
    void draw();
    
	// void draw(); // they can't draw themselves.  the view has to draw them ...
	
//    void setEffectsManager(EffectsManager* effectsManager);

    
	//void setSource(MediaSampler* source);
	//void setMask(MediaSampler* mask);

	//MediaSampler* getSource();
	//MediaSampler* getMask();
	
    void setSource(MediaAsset* src);
    void setMask(MediaAsset* src);
    
    FrameBufferPlayer* getSourcePlayer() {return sourcePlayer;};
    FrameBufferPlayer* getMaskPlayer()   {return maskPlayer;};

    
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
    
    AssetManager* getAssetManager();
    bool hasAssetManager();
    
    
private:
	
    ofFbo* fbo;
    
    string layerName;
    
//    EffectsManager* effectsManager;
    
//    EffectsChain effectsChain;
    
    FrameBufferPlayer* sourcePlayer;
    FrameBufferPlayer* maskPlayer;

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