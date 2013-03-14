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

#define OSC_PORT 5433

#include "ofMain.h"
#include "ofxLivedrawEngineInterface.h"

#include "ofxOscRouter.h"

#include "LayerManager.h"
#include "AssetManager.h"
#include "CanvasRenderer.h"

#include "EffectsManager.h"
#include "SessionManager.h"

class ofxLivedrawEngine : public ofxLivedrawEngineInterface,
                          public ofxOscRouterNode {
public:
    
    ofxLivedrawEngine();
    virtual ~ofxLivedrawEngine();
    
    void setup();
    void update();
    void draw();
    
    void processOscCommand(const string& command, const ofxOscMessage& m);
    
    void windowResized(int w, int h);
    
    ofxOscRouter*         getOscRouter();
    const ofxOscRouter*   getOscRouter() const;

    AssetManager*         getAssetManager();
    const AssetManager*   getAssetManager() const;
    
    LayerManager*         getLayerManager();
    const LayerManager*   getLayerManager() const;
    
    CanvasRenderer*       getCanvasRenderer();
    const CanvasRenderer* getCanvasRenderer() const;

    EffectsManager*       getEffectsManager();
    const EffectsManager* getEffectsManager() const;

    SessionManager*       getSessionManager();
    const SessionManager* getSessionManager() const;
    
protected:
    ofxOscRouter    oscRouter;
    AssetManager    assetManager;
    LayerManager    layerManager;
    CanvasRenderer  canvas;
    EffectsManager  effectsManager;
    SessionManager  sessionManager;
    
};
