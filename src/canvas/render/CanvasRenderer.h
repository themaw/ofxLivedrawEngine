/*
 *  CanvasRenderer.h
 *  livedraw
 *
 *  Created by Christopher P. Baker on 12/3/10.
 *  Copyright 2010 Murmur Labs LLC. All rights reserved.
 *
 */

// a collection of convas layers
// communication between layers

#pragma once
#include "ofxOscRouterNode.h"
#include "CanvasLayer.h"
#include "CanvasLayerTransform.h"
#include "CanvasLayerManager.h"
#include "AssetManager.h"
//#include "EffectsManager.h"
#include "ofxLivedrawEngine.h"

class ofxLivedrawEngine;
class CanvasLayerManager;

class CanvasRenderer : public ofxOscRouterNode {
	
public:
	
	CanvasRenderer();
    
	virtual ~CanvasRenderer();

    void init();
    
	void update();
    void render();
	void draw();
	
	// /livedraw/canvas/fullscreen
	void setFullscreen(bool _fullscreen);
	
	// /livedraw/canvas/background
	void setBackground(ofColor _color);

	// /livedraw/canvas/size
	void setSize(int width, int height);

	// /livedraw/canvas/position
	void setPosition(int x, int y);
	
	// /livedraw/canvas/fps
	void setFPS(int fps);
	
    void setMsaa(bool _msaa);
    
	
    void processOscMessage(const string& address, const ofxOscMessage& m);


	// /livedraw/canvas/layer/delete   LAYER_NAME
    
    ofFbo* getFbo() {
        return &fbo;
    }
    
    void resize(int w, int h);

    CanvasLayerManager* getCanvasLayerManager();
    
    void setEngine(ofxLivedrawEngine* _engine);
    ofxLivedrawEngine* getEngine();    
    
protected:
    
    ofxLivedrawEngine* engine;
    
    
private:
	
	CanvasLayerManager* layerManager;
    
    ofFbo fbo;
    int x, y;
    int width, height;
    bool useMSAA;
    
    ofColor bgColor;
    //EffectsManager* effectsManager;
};

