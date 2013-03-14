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

#include "ofxOscRouterNode.h"
#include "ofxLivedrawEngineInterface.h"
#include "LayerManagerInterface.h"
#include "ofxVideoSinkInterface.h"
#include "ofxVideoSourceInterface.h"
#include "AssetManager.h"

enum LayerStretchMode {
    CENTER = 0, // centers in layer at actual size
    FILL, // zooms to no remaining white space, aspect ratio preserved
    FIT, // fits maximum size to screen without losing any image
    STRETCH, // stretches in X / Y to fit layer dimensions
};


class LayerSink : public ofxVideoSinkInterface, public ofxOscRouterNode {
public:
    LayerSink(LayerManagerInterface* lmi, const string& name);
    virtual ~LayerSink();
    virtual void update();
    void processOscCommand(const string& command, const ofxOscMessage& m);
    bool frameReceived(ofxSharedVideoFrame _frame);
    void clear();
    bool hasFrame() const;
    ofxSharedVideoFrame getFrame();
    
    void sinkAsset(const string& asset);
    void unsinkAsset();

//    void setScaleMode(LayerStretchMode scaleMode);
//    LayerStretchMode getScaleMode() const;

    void setScaleMode(ofScaleMode scaleMode);
    ofScaleMode getScaleMode() const;
    
protected:
  
//    LayerStretchMode scaleMode;
    ofScaleMode scaleMode;
    
    LayerManagerInterface* lmi;
    ofxSharedVideoFrame frame;
    
};