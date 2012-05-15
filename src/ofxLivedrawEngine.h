//
//  ofxLivedrawEngine.h
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 5/13/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#pragma once

#include "ofMain.h"
#include "OscManager.h"
#include "ControllerManager.h"
#include "GuiManager.h"
#include "AssetManager.h"
#include "CanvasRenderer.h"
#include "SessionManager.h"
#include "EffectsManager.h"
#include "BufferManager.h"

#define OSC_PORT 5433


class ofxLivedrawEngine {
public:
    
    ofxLivedrawEngine();
    virtual ~ofxLivedrawEngine();
    
    void setup();
    void update();
    void draw();
    
    void windowResized(int w, int h);
    
protected:
    
    BufferManager   bufferManager;
    OscManager      oscManager;
    AssetManager    assetManager;
    EffectsManager  effectsManager;
    
    CanvasRenderer  canvas;
    
    SessionManager  sessionManager;
    GuiManager      guiManager;

private:

    
};
