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

// a collection of convas layers
// communication between layers

#pragma once
#include "ofxOscRouterNode.h"

#include "CanvasLayerManager.h"
//#include "AssetManager.h"
//#include "EffectsManager.h"
//#include "ofxLivedrawEngine.h"

//class ofxLivedrawEngine;
//class CanvasLayerManager;

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
    
	
    void processOscCommand(const string& command, const ofxOscMessage& m);


	// /livedraw/canvas/layer/delete   LAYER_NAME
    
    ofFbo* getFbo() {
        return &fbo;
    }
    
    void resize(int w, int h);

//    CanvasLayerManager* getCanvasLayerManager();
//    
//    void setEngine(ofxLivedrawEngine* _engine);
//    ofxLivedrawEngine* getEngine();    
    
protected:
    
//    ofxLivedrawEngine* engine;
    
    
private:
	
	CanvasLayerManager layerManager;
    
    ofFbo fbo;
    int x, y;
    int width, height;
    bool useMSAA;
    
    ofColor bgColor;
    //EffectsManager* effectsManager;
};

