//
//  ofxLivedrawEngine.h
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 5/13/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#pragma once

#include "ofMain.h"
#include "ofxOscRouter.h"
#include "AssetManager.h"
#include "CanvasLayerManager.h"
#include "CanvasRenderer.h"
#include "SessionManager.h"
#include "EffectsManager.h"

#define OSC_PORT 5433

class AssetManager;
class EffectsManager;
class CanvasLayerManager;
class CanvasRenderer;
class SessionManager;

class ofxLivedrawEngine {
public:
    
    ofxLivedrawEngine();
    virtual ~ofxLivedrawEngine();
    
    void setup();
    void update();
    void draw();
    
    void windowResized(int w, int h);
    
    ofxOscRouter*       getOscRouter();
    AssetManager*       getAssetManager();
    EffectsManager*     getEffectsManager();
    CanvasRenderer*     getCanvasRenderer();
    CanvasLayerManager* getCanvasLayerManager();
    SessionManager*     getSessionManager();
    
protected:
    ofxOscRouter*        oscRouter;
    
    AssetManager*    	 assetManager;
    EffectsManager*      effectsManager;
    
    CanvasRenderer*      canvas; // owns the layer manager
    
    SessionManager*      sessionManager;

private:
    
};
