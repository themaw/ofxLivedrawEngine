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

#include "ofxLivedrawEngineInterface.h"
#include "ofxOscRouterNode.h"
#include "LayerManagerInterface.h"
#include "Layer.h"

// TODO
//#include "alphanum.hpp"

//struct layerSetOrder {
//    bool operator()(const Layer* l0, const Layer* l1) const {
//        return doj::alphanum_comp(l0->getName(), l1->getName()) < 0;
//    }
//};

class LayerManager : public ofxOscRouterNode,
                     public LayerManagerInterface
{
public:
    
    LayerManager();
    virtual ~LayerManager();
    
    void update();
    void draw();
    
    void processOscCommand(const string& command, const ofxOscMessage& m);

    // adding layer schedules the addition of a layer
	Layer* addLayer(const string& alias, const ofPoint& point, int width, int height, Layer* parentLayer = NULL);
	Layer* addLayer(const string& alias, const ofPoint& point, Layer* parentLayer = NULL);

    //--------------------------------------------------------------
    bool queueAddLayer(Layer* asset);
    bool queueDestroyLayer(const string& alias);
    bool queueDestroyLayer(Layer* asset);
    
    //--------------------------------------------------------------
    bool hasLayer(const string& alias) const;
    
    Layer* getLayer(const string& alias);
    
    //--------------------------------------------------------------
    // layer ordering
    bool bringLayerForward(Layer* layer);
    bool sendLayerBackward(Layer* layer);
    bool sendLayerToBack(Layer* layer);
    bool bringLayerToFront(Layer* layer);
    bool sendLayerTo(Layer* layer, int targetLayerIndex);
   
    int  getLayerIndex(const string& alias);
    int  getLayerIndex(Layer* layer);

    void setLayerSolo(Layer* layer, bool solo);
    void setLayerLock(Layer* layer, bool lock);

    void dump();

    ofxLivedrawEngineInterface* getEngineInterface() { return engine;}
    void setEngineInterface(ofxLivedrawEngineInterface* _engine) {engine = _engine;}
    
protected:
    
    ofxLivedrawEngineInterface* engine;
    
private:
    
    void processQueues();
    void updateLayers();
    
    // these are private.
    bool registerLayer(Layer* layer);
    bool unregisterLayer(Layer* layer);
    
    string validateAlias(const string& name);
    
    set<Layer*/*,layerSetOrder*/> registerQueue; // items are scheduled for registration here.
    set<Layer*/*,layerSetOrder*/> unregisterQueue; // items are scheduled for removal here.

    map<string, Layer*/*, doj::alphanum_less<std::string> */>::iterator it;
    map<string, Layer*/*, doj::alphanum_less<std::string> */> layers;
    
    vector<Layer*>::iterator renderTreeIter;
    vector<Layer*> renderTree; // root layers in here
    
};