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

#include "Layer.h"


//--------------------------------------------------------------
Layer::Layer(LayerManagerInterface* _layerManager, string name, ofPoint pos, Layer* _layerParent) : ofxOscRouterNode(name) {
    layerManager = _layerManager;
    layerName = name;
    layerParent = _layerParent;
    setPosition(pos);
    init();
}

//--------------------------------------------------------------
Layer::Layer(LayerManagerInterface* _layerManager, string name, ofPoint pos) : ofxOscRouterNode(name) {
    layerManager = _layerManager;
    layerName = name;
    layerParent = NULL;
    setPosition(pos);
    init();
}

//--------------------------------------------------------------
Layer::Layer(LayerManagerInterface* _layerManager, string name) : ofxOscRouterNode(name) {
    layerManager = _layerManager;
    layerName = name;
    layerParent = NULL;
    init();
}

//--------------------------------------------------------------
Layer::~Layer() {
}

//--------------------------------------------------------------
void Layer::init() {
    
    bDrawDebugInfo = true;
    bDrawWireframe = true;
    bDrawAxis = true;
    bDrawOverFlow = false;
    
    // A
    inputs.push_back(LayerRenderSink());
    masks.push_back(LayerRenderSink());

    // B
    inputs.push_back(LayerRenderSink());
    masks.push_back(LayerRenderSink());

    layerStretchMode = FIT;
    
    //    effectsChain.setup();
    solo = false;
    locked = false;
    
    // fbo
    useMSAA = true;
    
    getTransform()->setWidth(640);
    getTransform()->setHeight(480); // standard canvas layer size
    
    addOscChild(&transform); // add the transform as an OSC child
    //    addOscChild(&effectsChain); // add the associated effects chain as a child
    
    addOscMethod("input");
    addOscMethod("mask");
    
    addOscMethod("order");
    addOscMethod("lock");
    addOscMethod("solo");
    addOscMethod("label");
        
    addOscMethod("stretchmode");
    addOscMethod("clipping");
    
    fbo = ofPtr<ofFbo>(new ofFbo());
    fbo->allocate(getTransform()->getWidth(), getTransform()->getHeight());
}

//--------------------------------------------------------------
bool Layer::dispose() {
    unsinkInputs();
    unsinkMasks();
    return true;
}

//--------------------------------------------------------------
bool Layer::isFrameNew() { return true;} ;

//--------------------------------------------------------------
ofPixelsRef Layer::getPixelsRef() {
    fbo->readToPixels(pix);
    return pix;
};

//--------------------------------------------------------------
bool Layer::isLoaded() {return true;}


//--------------------------------------------------------------
bool Layer::bringFoward() {
    return layerManager->bringLayerForward(this);
}
//--------------------------------------------------------------
bool Layer::sendBackward() {
    return layerManager->sendLayerBackward(this);
}
//--------------------------------------------------------------
bool Layer::bringToFront() {
    return layerManager->bringLayerToFront(this);
}
//--------------------------------------------------------------
bool Layer::sendToBack() {
    return layerManager->sendLayerToBack(this);
}

//--------------------------------------------------------------
void Layer::sinkInput(int index, const string& asset) {
    if(index >= inputs.size()) {
        ofLogError() << "Layer::sinkSource: invalid source index.  Must be less than " << inputs.size() << ".";
        return;
    }
    
    if(layerManager != NULL) {
        ofxLivedrawEngineInterface* engine = layerManager->getEngineInterface();
        if(engine != NULL) {
            AssetManager* assetManager = engine->getAssetManager();
            if(assetManager != NULL) {
                ofxVideoSourceInterface* src = assetManager->getSourceAsset(asset);
                if(src != NULL) {
                    unsinkInput(index); // release any current ones
                    src->attachToSink(&inputs[index]);
                } else {
                    ofLogError() << "Layer::sinkSource: " << asset << " was not a valid source.";
                }
            } else {
                ofLogError() << "Layer::sinkSource: AssetManager was NULL.";
            }
        } else {
            ofLogError() << "Layer::sinkSource: ofxLivedrawEngineInterface was NULL.";
        }
    } else {
        ofLogError() << "Layer::sinkSource: LayerManagerInterface was NULL.";
    }
}

//--------------------------------------------------------------
void Layer::sinkMask(int index, const string& asset) {
    if(index >= masks.size()) {
        ofLogError() << "Layer::sinkMask: invalid source index.  Must be less than " << masks.size() << ".";
        return;
    }
    
    if(layerManager != NULL) {
        ofxLivedrawEngineInterface* engine = layerManager->getEngineInterface();
        if(engine != NULL) {
            AssetManager* assetManager = engine->getAssetManager();
            if(assetManager != NULL) {
                ofxVideoSourceInterface* src = assetManager->getSourceAsset(asset);
                if(src != NULL) {
                    unsinkMask(index); // release any current ones
                    src->attachToSink(&masks[index]);
                } else {
                    ofLogError() << "Layer::sinkMask: " << asset << " was not a valid source.";
                }
            } else {
                ofLogError() << "Layer::sinkMask: AssetManager was NULL.";
            }
        } else {
            ofLogError() << "Layer::sinkMask: ofxLivedrawEngineInterface was NULL.";
        }
    } else {
        ofLogError() << "Layer::sinkMask: LayerManagerInterface was NULL.";
    }

}

//--------------------------------------------------------------
void Layer::unsinkInput(int index) {
    if(index < inputs.size()) {
        inputs[index].detachFromSources();
    } else {
        ofLogError() << "Layer::unsinkSource: invalid source index.  Must be less than " << inputs.size() << ".";
    }
}

//--------------------------------------------------------------
void Layer::unsinkMask(int index) {
    if(index < masks.size()) {
        masks[index].detachFromSources();
    } else {
        ofLogError() << "Layer::unsinkMask: invalid source index.  Must be less than " << masks.size() << ".";
        return;
    }
}

//--------------------------------------------------------------
void Layer::clearInput(int index) {
    if(index < inputs.size()) {
        inputs[index].clear();
    } else {
        ofLogError() << "Layer::unsinkSource: invalid source index.  Must be less than " << inputs.size() << ".";
    }
}

//--------------------------------------------------------------
void Layer::clearMask(int index) {
    if(index < masks.size()) {
        masks[index].clear();
    } else {
        ofLogError() << "Layer::unsinkMask: invalid source index.  Must be less than " << masks.size() << ".";
        return;
    }
}

//--------------------------------------------------------------
void Layer::unsinkInputs() {
    for(sinkIter = inputs.begin();
        sinkIter != inputs.end();
        sinkIter++) {
        (*sinkIter).detachFromSources();
    }
}

//--------------------------------------------------------------
void Layer::unsinkMasks() {
    for(sinkIter = masks.begin();
        sinkIter != masks.end();
        sinkIter++) {
        (*sinkIter).detachFromSources();
    }
}


// node info
//--------------------------------------------------------------
Layer* Layer::getLayerRoot() {
    // recursively locate root
    return layerParent != NULL ? layerParent->getLayerRoot() : NULL;
}

//--------------------------------------------------------------
Layer* Layer::getLayerParent() {
    return layerParent;
}

//--------------------------------------------------------------
vector<Layer*>& Layer::getLayerChildrenRef() {
    return layerChildren;
}

//--------------------------------------------------------------
bool Layer::hasChild(Layer* _layerChild) const {
    return ofContains(layerChildren,_layerChild);
}

//--------------------------------------------------------------
unsigned int Layer::findChild(Layer* _layerChild) const {
    return ofFind(layerChildren,_layerChild);
}

//--------------------------------------------------------------
void Layer::setPosition(const ofPoint& pos) {
    getTransform()->setPosition(pos);
}

//--------------------------------------------------------------
void Layer::setRectangle(const ofRectangle& rect) {
    getTransform()->setPosition(ofPoint(rect.x,rect.y));
    getTransform()->setSize(rect.width,rect.height);
}

//--------------------------------------------------------------
void Layer::processOscCommand(const string& command, const ofxOscMessage& m) {
    
    if(isMatch(command, "clipping")) {
        if(validateOscSignature("[sfi]", m)) {
            setDrawOverflow(getArgAsBoolean(m,0));
        }
    }
    if(isMatch(command, "stretchmode") ) {
        if(validateOscSignature("[s]", m)) {
            string mode = getArgAsStringUnchecked(m,0);
            if(isMatch(mode,"center")) {
                setLayerStretchMode(CENTER);
            } else if(isMatch(mode,"fill")) {
                setLayerStretchMode(FILL);
            } else if(isMatch(mode,"fit")) {
                setLayerStretchMode(FIT);
            } else if(isMatch(mode,"stretch")) {
                setLayerStretchMode(STRETCH);
            }
        }
    } else if(isMatch(command, "input") || isMatch(command, "mask")) {
        // layers/LAYER_NAME/source sink ASSET_NAME
        // layers/LAYER_NAME/source unsink
        
        // layers/LAYER_NAME/source 0 sink ASSET_NAME
        // layers/LAYER_NAME/source 0 unsink

        // layers/LAYER_NAME/source 1 sink ASSET_NAME
        // layers/LAYER_NAME/source 1 unsink

        // layers/LAYER_NAME/mask sink ASSET_NAME
        // layers/LAYER_NAME/mask unsink
        
        // layers/LAYER_NAME/mask 0 sink ASSET_NAME
        // layers/LAYER_NAME/mask 0 unsink
        
        // layers/LAYER_NAME/mask 1 sink ASSET_NAME
        // layers/LAYER_NAME/mask 1 unsink

        if(validateOscSignature("[fis]?[s][s]?", m)) {
            bool success = false;
            int targetLayer = 0;
            string action = "";
            string assetName = "";
            
            if(m.getNumArgs() < 2) {
                if(m.getArgType(0) == OFXOSC_TYPE_STRING) {
                    string s = getArgAsStringUnchecked(m,0);
                    if(isMatch(s,"unsink")) {
                        targetLayer = 0;
                        action = "unsink";
                        success = true;
                    } else if(isMatch(s,"clear")) {
                        targetLayer = 0;
                        action = "clear";
                        success = true;
                    } else {
                        ofLogNotice() << "Source Command, string value expected.";
                    }
                    
                } else {
                    ofLogNotice() << "Source Command, string value expected.";
                }
            } else if(m.getNumArgs() < 3) {
                if(m.getArgType(0) == OFXOSC_TYPE_STRING &&
                   m.getArgType(1) == OFXOSC_TYPE_STRING) {
                    targetLayer = 0;
                    action = getArgAsStringUnchecked(m,0);
                    assetName = getArgAsStringUnchecked(m,1);
                    success = true;
                } else if((m.getArgType(0) == OFXOSC_TYPE_INT32 ||
                           m.getArgType(0) == OFXOSC_TYPE_FLOAT) &&
                           m.getArgType(1) == OFXOSC_TYPE_STRING) {
                    targetLayer = getArgAsIntUnchecked(m,0);
                    action      = getArgAsStringUnchecked(m,1);
                    success     = true;
                } else {
                    ofLogNotice() << "Source Command, invalid string.";
                }
            } else if(m.getNumArgs() < 4) {
                if((m.getArgType(0) == OFXOSC_TYPE_INT32 ||
                    m.getArgType(0) == OFXOSC_TYPE_FLOAT) &&
                    m.getArgType(1) == OFXOSC_TYPE_STRING &&
                    m.getArgType(1) == OFXOSC_TYPE_STRING) {
                    targetLayer = getArgAsIntUnchecked(m,0);
                    action      = getArgAsStringUnchecked(m,1);
                    assetName   = getArgAsStringUnchecked(m,2);
                    success     = true;
                } else {
                    ofLogNotice() << "Source Command, invalid number of args.";
                }
            }
            
            if(success) {
                if(targetLayer < inputs.size()) {
                    if(isMatch(action, "clear")) {
                        if(isMatch(command, "input") ) {
                            clearInput(targetLayer);
                        } else {
                            clearMask(targetLayer);
                        }
                    } else if(isMatch(action, "unsink")) {
                        if(isMatch(command, "input") ) {
                            unsinkInput(targetLayer);
                        } else {
                            unsinkMask(targetLayer);
                        }
                    } else if(isMatch(action, "sink")) {
                        if(isMatch(command, "input") ) {
                            sinkInput(targetLayer,assetName);
                        } else {
                            sinkMask(targetLayer,assetName);
                        }
                    } else {
                        ofLogNotice() << "Source Command, invalid command : " << action;
                    }
                }
            }
            
        }

    } if(isMatch(command,"order")) {
        if(validateOscSignature("[sfi]", m)) {
            if(m.getArgType(0) == OFXOSC_TYPE_STRING) {
                string command = toLower(getArgAsStringUnchecked(m,0));
                if(isMatch(command, "forward")) {
                    bringFoward();
                } else if(isMatch(command,"backward")) {
                    sendBackward();
                } else if(isMatch(command,"front")) {
                    bringToFront();
                } else if(isMatch(command,"back")) {
                    sendToBack();
                }
            } else {
                int targetLayer = getArgAsIntUnchecked(m,0);
                // TODO::
            }
        }
    } else if(isMatch(command,"lock")) {
        if(validateOscSignature("[fi]", m)) {
            layerManager->setLayerLock(this, getArgAsBoolean(m,0));
        }
    } else if(isMatch(command,"solo")) {
        if(validateOscSignature("[fi]", m)) {
            layerManager->setLayerSolo(this, getArgAsBoolean(m,0));
        }
    } else if(isMatch(command,"label")) {
        if(validateOscSignature("[fi][fi][fi][fi]?", m)) {
            label = getArgsAsColor(m, 0);
        }
    } else if(isMatch(command,"debug")) {
        if(validateOscSignature("[s][fi]", m)) {
            string e = getArgAsStringUnchecked(m,0);
            if(isMatch(e,"all")) {
                bool val = getArgAsBoolean(m, 1);
                setDrawWireframe(val);
                setDrawAxis(val);
                setDrawDebugInfo(val);
            } else if(isMatch(e,"wireframe")) {
                setDrawWireframe(getArgAsBoolean(m,1));
            } else if(isMatch(e,"axis")) {
                setDrawAxis(getArgAsBoolean(m, 1));
            } else if(isMatch(e,"info")) {
                setDrawDebugInfo(getArgAsBoolean(m, 1));
            }
        }
    }
}

//--------------------------------------------------------------
string Layer::getName() const {
    return layerName;
}

//--------------------------------------------------------------
void Layer::setName(const string& _name) {
    layerName = _name;
    addOscNodeAlias(layerName);
}

//--------------------------------------------------------------
void Layer::update() {

}

void Layer::draw() {
    
    LayerTransform* xform = getTransform();
    
    int w = xform->getWidth();
    int h = xform->getHeight();
    
    ofPoint a = xform->getAnchorPoint();
    if(xform->isAnchorPointNormalized()) {
        a.x *= w;
        a.y *= h;
    }
    
    ofPoint p = xform->getPosition();
    if(xform->isPositionNormalized()) ofLogWarning() << "Normalized position is not yet supported.";

    ofPoint r = xform->getRotation();
    if(xform->isRotationNormalized()) r *= 360.0f;
    
    ofPoint s = xform->getScale();
    float opacity = xform->getOpacity();
    if(xform->isOpacityNormalized()) opacity *= 255;
    
    ofPushMatrix();
    
    if (opacity < 255) ofEnableAlphaBlending();
    
    ofTranslate(p.x, p.y, p.z);
    
    ofRotateX(r.x);
    ofRotateY(r.y);
    ofRotateZ(r.z);
    
    ofScale(s.x,
            s.y,
            s.z);

// TODO: for this to work, we need to give it screen coords
//    if(!bDrawOverFlow) {
//        glEnable(GL_SCISSOR_TEST);
//        glScissor(0,0,w,h);
//    }

    
    ofSetColor(255,opacity);
    
    ofPushMatrix();
    
    ofTranslate(-a.x, -a.y); // anchor point offset

    
    if(bDrawWireframe) {
        ofPushStyle();
        ofSetColor(127);
        ofNoFill();
        ofRect(0,0,w,h);
        ofLine(0,0,w,h);
        ofLine(0,h,w,0);
        ofPopStyle();
        
    }

    for(int i = 0; i < inputs.size(); i++) {
        
        if(bDrawDebugInfo) {
            ofPushStyle();
            ofSetColor(255,255,0);
            ofDrawBitmapString("Source/Mask: " + ofToString(i), ofPoint(0,(i+1)*12,0));
            ofPopStyle();
        }
        
        // BEGIN EFFECTS COMPOSITION
        
        if(hasInputFrame(i)) {
            drawFrame(getInputSink(i).getFrame());
        }
        
        if(hasMaskFrame(i)) {
            drawFrame(getMaskSink(i).getFrame());
        }
        
        // END COMPOSITION
        
    }


    ofPopMatrix();

    if(bDrawAxis) {
        ofDrawAxis(20);
    }

    
    if(bDrawDebugInfo) {
        ofPushStyle();
        ofSetColor(255);
        string s = "Layer: " + getName();
        ofPoint p(0,0,0);
        ofDrawBitmapString(s,p);
        ofDrawBitmapStringHighlight(s,p);
        ofPopStyle();
    }

    if (opacity < 255) ofDisableAlphaBlending();
    
    // draw those children
    vector<Layer*>& children = getLayerChildrenRef();
    for(int i = 0; i < children.size(); i++) {
        children[i]->draw();
        cout << "drawing child." << endl;
    }
    
    
    // TODO: See above
    //if(!bDrawOverFlow) glDisable(GL_SCISSOR_TEST);
    

    ofPopMatrix();
    
}

//--------------------------------------------------------------
void Layer::drawFrame(ofxSharedVideoFrame frame) {
    
    LayerTransform* xform = getTransform();
    
    float w = xform->getWidth();
    float h = xform->getHeight();
    
    float fw = frame->getWidth();
    float fh = frame->getHeight();
    
    if(layerStretchMode == CENTER) {
        frame->draw((w - fw) * 0.5f,
                    (h - fh) * 0.5f,
                    fw,
                    fh);
    } else if(layerStretchMode == FILL) {
        float resultScale = MAX(fabs(w) / fabs(fw),
                                fabs(h) / fabs(fh));
        
        frame->draw(( w - fw * resultScale ) * 0.5f,
                    ( h - fh * resultScale ) * 0.5f,
                    ( fw * resultScale ),
                    ( fh * resultScale ));
    } else if(layerStretchMode == FIT) {
        
        // find the scaling factor, fabs for -w and/or -h
        float resultScale = MIN(fabs(w) / fabs(fw),
                                fabs(h) / fabs(fh));
        
        frame->draw(( w - fw * resultScale ) * 0.5f,
                    ( h - fh * resultScale ) * 0.5f,
                    ( fw * resultScale ),
                    ( fh * resultScale ));
        
    } else if(layerStretchMode == STRETCH) {
        frame->draw(0,0,w,h);
    } else {
        frame->draw(0,0,w,h);
        ofLogWarning() << "Layer::update(): Unknown layer stretch mode." << endl;
    }

}

//--------------------------------------------------------------
bool Layer::hasInputFrame(int index) const {
    return inputs[index].hasFrame();
}

//--------------------------------------------------------------
bool Layer::hasMaskFrame(int index) const {
    return masks[index].hasFrame();
}

//--------------------------------------------------------------
LayerRenderSink& Layer::getInputSink(int index) {
    return inputs[index];
}

//--------------------------------------------------------------
LayerRenderSink& Layer::getMaskSink(int index) {
    return masks[index];
}

//--------------------------------------------------------------
const LayerRenderSink& Layer::getInputSink(int index) const {
    return inputs[index];
}

//--------------------------------------------------------------
const LayerRenderSink& Layer::getMaskSink(int index) const {
    return masks[index];
}

//--------------------------------------------------------------
LayerTransform* Layer::getTransform() { return &transform; };

//--------------------------------------------------------------
LayerStretchMode Layer::getLayerStretchMode() {
    return layerStretchMode;
}

//--------------------------------------------------------------
void Layer::setLayerStretchMode(LayerStretchMode mode) {
    layerStretchMode = mode;
}

//--------------------------------------------------------------
bool Layer::isSolo() const {return solo;};
//--------------------------------------------------------------
bool Layer::setSolo(bool _solo) {solo = _solo;};

//--------------------------------------------------------------
bool Layer::isLocked() const {return locked;};
//--------------------------------------------------------------
bool Layer::setLocked(bool _locked) {locked = _locked;};


//--------------------------------------------------------------
void Layer::onEnabled() {}

//--------------------------------------------------------------
void Layer::onDisabled() {}

//--------------------------------------------------------------
void Layer::setDrawDebugInfo(bool b) { bDrawDebugInfo = b; }
//--------------------------------------------------------------
bool Layer::getDrawDebugInfo() { return bDrawDebugInfo; }
//--------------------------------------------------------------
void Layer::setDrawWireframe(bool b) { bDrawWireframe = b; }
//--------------------------------------------------------------
bool Layer::getDrawWireframe() { return bDrawWireframe; }
//--------------------------------------------------------------
void Layer::setDrawAxis(bool b) { bDrawAxis = b; }
//--------------------------------------------------------------
bool Layer::getDrawAxis() { return bDrawAxis; }
//--------------------------------------------------------------
void Layer::setDrawOverflow(bool b) { bDrawOverFlow = b; }
//--------------------------------------------------------------
bool Layer::getDrawOverflow() { return bDrawOverFlow; }

//--------------------------------------------------------------
string Layer::toString() const {
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

