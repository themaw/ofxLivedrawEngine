//
//  CanvasLayerManager.h
//  livedraw
//
//  Created by Christopher P. Baker on 5/17/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#pragma once

#include "ofMain.h"
#include "ofxLivedrawEngine.h"
#include "ofxOscRouterNode.h"
#include "CanvasLayer.h"
#include "AssetManager.h"

//#include "EffectsManager.h"

class ofxLivedrawEngine;
class CanvasLayer;

class CanvasLayerManager : public ofxOscRouterNode {
public:
    
    CanvasLayerManager();
    virtual ~CanvasLayerManager();
    
    void setup();
    void update();
    void draw();
    
//    void setEffectsManager(EffectsManager* _effectsManager);
    
    void processOscMessage(string pattern, ofxOscMessage& m);

	CanvasLayer* newLayer(string layerName, ofPoint point = ofPoint(0.0,0.0,0.0), CanvasLayer* parentLayer = NULL);
	bool deleteLayer(string layerName);

    bool hasLayer(string name);

    CanvasLayer* getLayerByName(string name);
    
    int  getLayerIndex(string layerName);
    
    
    bool addLayerAsRoot(CanvasLayer* layer);
    
    
    
    bool bringLayerForward(CanvasLayer* layer);
    bool sendLayerBackward(CanvasLayer* layer);
    bool sendLayerToBack(CanvasLayer* layer);
    bool bringLayerToFront(CanvasLayer* layer);
    bool sendLayerTo(CanvasLayer* layer, int targetLayerIndex);
    
    void setLayerSolo(CanvasLayer* layer, bool solo);
    void setLayerLock(CanvasLayer* layer, bool lock);
    
    void setEngine(ofxLivedrawEngine* _engine) {engine = _engine;};
    ofxLivedrawEngine* getEngine() {return engine;}    
    
protected:
    
    ofxLivedrawEngine* engine;
    
private:
    
    vector<CanvasLayer*>::iterator it;

    vector<CanvasLayer*> layers;  // a collection of all layers
    vector<CanvasLayer*> renderTree; // root layers in here 
    

};