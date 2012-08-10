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
    //cout << "_layerManager=" << _layerManager << " " << name << " " << pos << " cl=" << endl;
    
    
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
    
//    sourcePlayer = new FrameBufferPlayer(this);
//    sourcePlayer->addOscNodeAlias("source");
//    maskPlayer = new FrameBufferPlayer(this);
//    maskPlayer->addOscNodeAlias("mask");
//
//    addOscChild(sourcePlayer);
//    addOscChild(maskPlayer);
    
    
    // A
    inputs.push_back(LayerRenderSink());
    masks.push_back(LayerRenderSink());

    // B
    inputs.push_back(LayerRenderSink());
    masks.push_back(LayerRenderSink());

    layerStretchMode = CENTER;
    
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
    
//    addOscMethod("swap");
    
    cout << toString() << endl;
    
    fbo = ofPtr<ofFbo>(new ofFbo());
    fbo->allocate(getTransform()->getWidth(), getTransform()->getHeight());
    

}

//--------------------------------------------------------------
bool Layer::dispose() {
    // disposing
    return true;
}

////--------------------------------------------------------------
//AssetManager* Layer::getAssetManager() {
//    ofxLivedrawEngine* eng = layerManager->getEngine();
//    if(eng != NULL) {
//        return eng->getAssetManager();
//    } else {
//        return NULL;
//    }
//}

//--------------------------------------------------------------
//void Layer::setEffectsManager(EffectsManager* _effectsManager) {
//    effectsManager = _effectsManager;
//    effectsChain.setEffectsManager(effectsManager);
//}

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

                    if(!src->attachToSink(&inputs[index])) {
                        ofLogError() << "Layer::sinkSource: error attaching source to layer sink.";
                    }
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
                    
                    if(!src->attachToSink(&masks[index])) {
                        ofLogError() << "Layer::sinkMask: error attaching source to layer sink.";
                    }
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
        inputs[index].detachFromAllSources();
    } else {
        ofLogError() << "Layer::unsinkSource: invalid source index.  Must be less than " << inputs.size() << ".";
        return;
    }
}

//--------------------------------------------------------------
void Layer::unsinkMask(int index) {
    if(index < masks.size()) {
        masks[index].detachFromAllSources();
    } else {
        ofLogError() << "Layer::unsinkMask: invalid source index.  Must be less than " << masks.size() << ".";
        return;
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

////--------------------------------------------------------------
//ofxLivedrawEngine* Layer::getEngine() {
////    cout << "CLM=" << layerManager << endl;
////    cout << "CLM=" << layerManager->getEngine() << endl;
//    
//    return layerManager->getEngine();
//}

////--------------------------------------------------------------
//void Layer::setLayerParent(Layer* _layerParent) {
//    
//    // setting the layer parent does:
//    // 0. checks to see if the parent is different.
//    // 1. removes the layer from an existing parent.
//    // 2. sets a new parent reference.
//    // 3. adds the item to the parent.
//    
//
//    if(_layerParent == layerParent) {
//        // already set
//        return;
//    }
//
//    
//    if(layerParent != NULL) { // if it has a parent, remove it
//        // remove from the current parent
//        if(!layerParent->removeLayerChild(this)) {
//            ofLog(OF_LOG_ERROR, "Layer::setLayerParent(): Error removing child from previous parent.");  
//        } 
//    }
//
//    layerParent = _layerParent; // set a new parent reference
//    
//    if(layerParent != NULL) {
//        layerParent->addLayerChild(this); // add item to the new parent
//    } else {
//        //layerManager->addLayerAsRoot(this);
//    }
//    
//}
////--------------------------------------------------------------
//bool Layer::addLayerChild(Layer* _layerChild) {
//    vector<Layer*>::iterator layerParentIter = findChild(this);
//
//    if(layerParentIter == layerChildren.end()) {
//        layerChildren.push_back(_layerChild);
//        return true;
//    } else {
//        return false;
//    }    
//}
//
////--------------------------------------------------------------
//bool Layer::removeLayerChild(Layer* _layerChild) {
//    vector<Layer*>::iterator it = findChild(_layerChild);
//    if(it != layerChildren.end()) {
//        _layerChild->setLayerParent(NULL);
//        layerChildren.erase(it);
//        return true;
//    } else {
//        // did not have it
//        return false;
//    }
//}
//
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
    
//    cout << "Layer::const string& command, const ofxOscMessage& m(const string& pattern, ofxOscMessage& m)" << command << "/" << endl;
    
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
                    if(isMatch(action, "unsink")) {
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
        
//        cout << "IN HERE " << endl;
        
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
                
//              cout << "moving to " << targetLayer << endl;
                
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

////--------------------------------------------------------------
//void Layer::setSource(MediaAsset* src) {
//    /*
//    if(source->isLoaded()) {
//        delete source;
//        source = NULL;
//        source = new ofVideoPlayer();
//    }
//    
//    source->loadMovie(src->getAssetURI().toString());
//    source->play();
//     */
//}
//
////--------------------------------------------------------------
//void Layer::setMask(MediaAsset* src) {
//    //mask->loadImage(src->getAssetURI().toString());
//}


//--------------------------------------------------------------
// This must also swap node names, etc.  Better to swap the playe rdata, 
// rather than the whole frame buffer pointer.
//void Layer::swapSourceMaskPlayers() {
//    FrameBufferPlayer* tmp;
//    tmp = getSourcePlayer();
//    sourcePlayer = getMaskPlayer();
//    maskPlayer = tmp;
//}



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
    
    ofRectangle s
    
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
        
//        if(bDrawDebugInfo) {
//            ofPushStyle();
//            ofSetColor(255,255,0);
//            ofDrawBitmapString("Source/Mask: " + ofToString(i), ofPoint(0,(i+1)*12,0));
//            ofPopStyle();
//        }
        
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
    
    
    //if(!bDrawOverFlow) glDisable(GL_SCISSOR_TEST);
    

    ofPopMatrix();
    
    
    

}


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
void Layer::onEnabled() {}

//--------------------------------------------------------------
void Layer::onDisabled() {}