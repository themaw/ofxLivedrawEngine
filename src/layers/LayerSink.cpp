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

#include "LayerSink.h"

//--------------------------------------------------------------
LayerSink::LayerSink(LayerManagerInterface* _lmi, const string& name) : ofxOscRouterNode(name) {
    lmi = _lmi;
    
    addOscMethod("sink");
    addOscMethod("s");
    addOscMethod("unsink");
    addOscMethod("u");
    addOscMethod("clear");
    addOscMethod("c");
    
}

//--------------------------------------------------------------
LayerSink::~LayerSink() {}

//--------------------------------------------------------------
void LayerSink::update() {
    ofxVideoSinkInterface::update(); // update the sink (newness checks)
}

//--------------------------------------------------------------
void LayerSink::processOscCommand(const string& command, const ofxOscMessage& m) {

    if(isMatch(command, "sink") || isMatch(command, "s")) {
        if(validateOscSignature("[s]", m)) {
            sinkAsset(getArgAsStringUnchecked(m,0));
        }
    } else if(isMatch(command,"unsink") || isMatch(command,"u")) {
        unsinkAsset();
    } else if(isMatch(command,"clear") || isMatch(command,"c")) {
        clear();
    } else {
        ofLogWarning("LayerSink") << "Unknown osc command : " << command << ".";
    }
}

//--------------------------------------------------------------
bool LayerSink::frameReceived(ofxSharedVideoFrame _frame) {
    frame = _frame;
}

//--------------------------------------------------------------
void LayerSink::clear() {
    frame.reset();
}

//--------------------------------------------------------------
bool LayerSink::hasFrame() const {
    return frame != NULL;
}

//--------------------------------------------------------------
ofxSharedVideoFrame LayerSink::getFrame() {
    return frame;
}

//--------------------------------------------------------------
void LayerSink::sinkAsset(const string& asset) {

    if(lmi != NULL) {
        ofxLivedrawEngineInterface* engine = lmi->getEngineInterface();
        if(engine != NULL) {
            AssetManager* assetManager = engine->getAssetManager();
            if(assetManager != NULL) {
                ofxVideoSourceInterface* src = assetManager->getSourceAsset(asset);
                if(src != NULL) {
                    unsinkAsset(); // release any current ones
                    src->attachToSink(this);
                } else {
                    ofLogError("LayerSink") << "sinkAsset: " << asset << " was not a valid source.";
                }
            } else {
                ofLogError("LayerSink") << "sinkAsset: AssetManager was NULL.";
            }
        } else {
            ofLogError("LayerSink") << "sinkAsset: ofxLivedrawEngineInterface was NULL.";
        }
    } else {
        ofLogError("LayerSink") << "sinkAsset: LayerManagerInterface was NULL.";
    }

}

//--------------------------------------------------------------
void LayerSink::unsinkAsset() {
    detachFromSources();
}