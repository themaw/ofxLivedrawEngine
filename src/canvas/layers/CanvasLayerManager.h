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
    
    void update();
    void draw();
    
//    void setEffectsManager(EffectsManager* _effectsManager);
    
    void processOscMessage(const string& pattern, const ofxOscMessage& m);

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

    void dump();

    
    
protected:
    
    ofxLivedrawEngine* engine;
    
private:
    
    vector<CanvasLayer*>::iterator it;

    vector<CanvasLayer*> layers;  // a collection of all layers
    vector<CanvasLayer*> renderTree; // root layers in here 
    

};