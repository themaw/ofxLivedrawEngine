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
#include "ofxLivedrawEngineInterface.h"
#include "ofxVideoSourceInterface.h"

#include "ofxEnablerInterface.h"
#include "ofxOscRouterNode.h"
//#include "ofTexture.h"

#include "LayerManagerInterface.h"
#include "LayerTransform.h"
#include "AssetManager.h"
//#include "EffectsManager.h"
//#include "EffectsChain.h"

#include "LayerRenderSink.h"

//class MediaAsset;
//class BufferPlayerAsset;
//class LayerManager;
//class ofxLivedrawEngine;

//class LayerManager;
//class BufferPlayerAsset;

#include "alphanum.hpp"

enum LayerStretchMode {
    CENTER = 0, // centers in layer at actual size
    FILL, // zooms to no remaining white space, aspect ratio preserved
    FIT, // fits maximum size to screen without losing any image
    STRETCH, // stretches in X / Y to fit layer dimensions
};


class Layer : public ofxOscRouterNode,
              public ofxVideoSourceInterface,
              public ofxEnablerInterface
{
	
public:

	Layer(LayerManagerInterface* clm, string name);
	Layer(LayerManagerInterface* clm, string name, ofPoint pos);
    Layer(LayerManagerInterface* clm, string name, ofPoint pos, Layer* layerParent);

	virtual ~Layer();
	
    void processOscCommand(const string& command, const ofxOscMessage& m);

    void update();
    void init();
    bool dispose();

    bool isFrameNew() { return true;} ;

    ofPixelsRef getPixelsRef() {
        fbo->readToPixels(pix);
        return pix;
    };
    
    bool isLoaded() {return true;}
    
    void render();
    void draw();
    void drawFrame(ofxSharedVideoFrame frame);

    // player assets
    bool hasInputFrame(int index = 0) const {
        return inputs[index].hasFrame();
    }
    
    bool hasMaskFrame(int index = 0) const {
        return masks[index].hasFrame();
    }
    
    LayerRenderSink& getInputSink(int index = 0) {
        return inputs[index];
    }
    
    LayerRenderSink& getMaskSink(int index = 0) {
        return masks[index];
    }

    const LayerRenderSink& getInputSink(int index = 0) const {
        return inputs[index];
    }
    
    const LayerRenderSink& getMaskSink(int index = 0) const {
        return masks[index];
    }

    LayerTransform* getTransform() { return &transform; };
	
    LayerStretchMode getLayerStretchMode() {
        return layerStretchMode;
    }
    
    void setLayerStretchMode(LayerStretchMode mode) {
        layerStretchMode = mode;
    }
    
    
    string getName() const;
    void setName(const string& name);
    
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
	bool isSolo() const {return solo;};
	bool setSolo(bool _solo) {solo = _solo;};

	bool isLocked() const {return locked;};
	bool setLocked(bool _locked) {locked = _locked;};
	
    void onEnabled();
    void onDisabled();
    
    void setPosition(const ofPoint& pos);
    void setSize(int width, int height);
    void setRectangle(const ofRectangle& rect);
	
    //ofFbo* getFbo() {
    //    return &fbo;
   // }
    
    bool bringFoward();
    bool sendBackward();
    bool bringToFront();
    bool sendToBack();
    
    void sinkInput(int index, const string& asset);
    void sinkMask(int index, const string& asset);
    
    void unsinkInput(int index);
    void unsinkMask(int index);

    void clearInput(int index);
    void clearMask(int index);
    
    void unsinkInputs();
    void unsinkMasks();
    
    // node info
    Layer*          getLayerRoot();
    Layer*          getLayerParent();
    vector<Layer*>& getLayerChildrenRef();

    bool hasChild(Layer* layerChild) const;
    unsigned int findChild(Layer* layerChild) const;

    void setLayerParent(Layer* layerParent);
    
//    AssetManager* getAssetManager();
    
//    LayerManager* getLayerManager();
//    ofxLivedrawEngine* getEngine();
    
    string toString() const {
        stringstream ss;
        ss << "[Layer: name: " << getName();
        ss << " hasInput: " << hasInputFrame();
        ss << " isInputSinking: " << getInputSink().isSinking();
        ss << " hasMask: " << hasMaskFrame();
        ss << " isMaskSinking: " << getMaskSink().isSinking() << endl;
        ss << " [xform: " << endl;
        ss << "   [size: " << transform.getSize() << "]"<< endl;;
        ss << "   [pos: " << transform.getPosition() << "]"<< endl;;
        ss << "   [anch: " << transform.getAnchorPoint() << "]"<< endl;;
        ss << "   [scale: " << transform.getScale() << "]"<< endl;;
        ss << "   [rot: " << transform.getRotation() << "]"<< endl;;
        ss << "   [orient: " << transform.getOrientation() << "]"<< endl;;
        ss << "   [opacity: " << transform.getOpacity() << "]"<< endl;;
        ss << "]]";
        return ss.str();
    }
    
    
    void setDrawDebugInfo(bool b) { bDrawDebugInfo = b; }
    bool getDrawDebugInfo() { return bDrawDebugInfo; }
    void setDrawWireframe(bool b) { bDrawWireframe = b; }
    bool getDrawWireframe() { return bDrawWireframe; }
    void setDrawAxis(bool b) { bDrawAxis = b; }
    bool getDrawAxis() { return bDrawAxis; }
    void setDrawOverflow(bool b) { bDrawOverFlow = b; }
    bool getDrawOverflow() { return bDrawOverFlow; }
    
private:
	
    bool bDrawDebugInfo;
    bool bDrawWireframe;
    bool bDrawAxis;
    bool bDrawOverFlow;
    
    ofPixels pix; // TODO:
    ofPtr<ofFbo> fbo;
    
    string layerName;
    
//    EffectsManager* effectsManager;
    
//    EffectsChain effectsChain;

    // why not more?

    
    vector<LayerRenderSink>::iterator sinkIter;
    vector<LayerRenderSink> inputs;
    vector<LayerRenderSink> masks;
    
//    LayerRenderSink sourceSinkA;
//    LayerRenderSink sourceSinkB;
//    LayerRenderSink maskSinkA;
//    LayerRenderSink maskSinkB;

	// Masker compositer;
	// width / height are all taken from the source
	LayerTransform transform;
	//vector<BaseCanvasEffect*> effects;
	
	bool solo;
	bool locked;
    
    ofColor label;
    
    // fbo
    bool useMSAA;

    LayerManagerInterface* layerManager;
    
    
    // node 
    Layer*         layerParent;
    vector<Layer*> layerChildren;
    
    // private
//    vector<Layer*>::iterator findChild(Layer* layerChild);
//    bool addLayerChild(Layer* layerChild);
//    bool removeLayerChild(Layer* layerChild);

//    set<Layer*>& getChildLayersRef();
//    bool containsChildLayer(Layer* _keyword) const;
//    bool addChildLayer(Layer* _keyword);
//    bool removeChildLayer(Layer* _keyword);
//    int  getNumChildLayers() const;

    
    LayerStretchMode layerStretchMode;
    
	// -> should this be in the gui?
	//ofColor labelColor;
		
};