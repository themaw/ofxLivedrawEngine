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

#include "LayerManagerInterface.h"
#include "LayerTransform.h"
//#include "AssetManager.h"

#include "EffectsManager.h"

#include "MaskedInput.h"

#include "alphanum.hpp"

enum LayerStretchMode {
    CENTER = 0, // centers in layer at actual size
    FILL, // zooms to no remaining white space, aspect ratio preserved
    FIT, // fits maximum size to screen without losing any image
    STRETCH, // stretches in X / Y to fit layer dimensions
};


class Layer : public ofxOscRouterNode,
              //public ofxVideoSourceInterface,
              public ofxEnablerInterface
{
	
public:

	Layer(LayerManagerInterface* clm, const string& name);
	Layer(LayerManagerInterface* clm, const string& name, const ofPoint& pos);
    Layer(LayerManagerInterface* clm, const string& name, const ofPoint& pos, Layer* layerParent);

	virtual ~Layer();
	
    void processOscCommand(const string& command, const ofxOscMessage& m);

    void update();
    void init();
    bool dispose();

//    bool isFrameNew();

//    ofPixelsRef getPixelsRef();
    
//    bool isLoaded();
    
    void render();
    void draw();
    void drawFrameIntoFbo(ofxSharedVideoFrame frame, ofPtr<ofFbo> fbo);

//    // player assets
//    bool hasInputFrame(int index = 0) const;
//    bool hasMaskFrame(int index = 0) const;
//    LayerSink& getInputSink(int index = 0);
//    LayerSink& getMaskSink(int index = 0);
//    const LayerSink& getInputSink(int index = 0) const;
//    const LayerSink& getMaskSink(int index = 0) const;

    LayerTransform& getTransformRef();
	
    LayerStretchMode getLayerStretchMode();
    void setLayerStretchMode(LayerStretchMode mode);
    
    
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
	bool isSolo() const;
	bool setSolo(bool _solo);

	bool isLocked() const;
	bool setLocked(bool _locked);
	
    void onEnabled();
    void onDisabled();
    
    void setPosition(const ofPoint& pos);
    void setSize(int width, int height);
    void setRectangle(const ofRectangle& rect);
	
    // layer position
    bool bringFoward();
    bool sendBackward();
    bool bringToFront();
    bool sendToBack();
    
//    void sinkInput(int index, const string& asset);
//    void sinkMask(int index, const string& asset);
//    
//    void unsinkInput(int index);
//    void unsinkMask(int index);
//
//    void clearInput(int index);
//    void clearMask(int index);
//    
//    void unsinkInputs();
//    void unsinkMasks();
    
    // node info
    Layer*          getLayerRoot();
    Layer*          getLayerParent();
    vector<Layer*>& getLayerChildrenRef();

    bool hasChild(Layer* layerChild) const;
    unsigned int findChild(Layer* layerChild) const;

    void setLayerParent(Layer* layerParent);
    
    void setDrawDebugInfo(bool b);
    bool getDrawDebugInfo();
    void setDrawWireframe(bool b);
    bool getDrawWireframe();
    void setDrawAxis(bool b);
    bool getDrawAxis();
    void setDrawOverflow(bool b);
    bool getDrawOverflow();
    
    string toString() const;
    
private:
	
    bool bDrawDebugInfo;
    bool bDrawWireframe;
    bool bDrawAxis;
    bool bDrawOverFlow;
    
    ofPixels pix; // TODO:
    ofPtr<ofFbo> fboLayer;
    ofPtr<ofFbo> fboInput;
    ofPtr<ofFbo> fboMask;
    
    bool isFboLayerDirty;
    bool isFboInputDirty;
    bool isFboMaskDirty;

    
    string layerName;
    
    MaskedInput* inputA;
    MaskedInput* inputB;
    
    
    MaskedInput* getCurrentInput();
    bool currentInputIsA;
    
	LayerTransform transform; // todo: make this shared
	
	bool solo;
	bool locked;
    
    ofColor label;
    
    // fbo
    bool useMSAA;

    LayerManagerInterface* layerManager;
    
    // node
    Layer*         layerParent;
    vector<Layer*> layerChildren;
    
    LayerStretchMode layerStretchMode;
    
};