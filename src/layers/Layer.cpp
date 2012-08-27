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
Layer::Layer(LayerManagerInterface* _layerManager, const string& name, const ofPoint& pos, Layer* _layerParent) : ofxOscRouterNode(name) {
    layerManager = _layerManager;
    layerName = name;
    layerParent = _layerParent;
    setPosition(pos);
    init();
}

//--------------------------------------------------------------
Layer::Layer(LayerManagerInterface* _layerManager, const string& name, const ofPoint& pos) : ofxOscRouterNode(name) {
    layerManager = _layerManager;
    layerName = name;
    layerParent = NULL;
    setPosition(pos);
    init();
}

//--------------------------------------------------------------
Layer::Layer(LayerManagerInterface* _layerManager, const string& name) : ofxOscRouterNode(name) {
    layerManager = _layerManager;
    layerName = name;
    layerParent = NULL;
    init();
}

//--------------------------------------------------------------
Layer::~Layer() {
    delete inputA;
    delete inputB;
}

//--------------------------------------------------------------
void Layer::init() {
    
    bDrawDebugInfo = true;
    bDrawWireframe = true;
    bDrawAxis = true;
    bDrawOverFlow = false;
    
    currentInputIsA = true;
    
    isFboLayerDirty = true; // TODO: implement dirty layer
    isFboInputDirty = true; // TODO: implement dirty input
    isFboMaskDirty  = true; // TODO: implement dirty mask

    inputA = new MaskedInput(layerManager,"A");
    inputB = new MaskedInput(layerManager,"B");
    
    addOscChild(inputA);
    addOscChild(inputB);

    layerStretchMode = FIT;
    
    //    effectsChain.setup();
    solo = false;
    locked = false;
    
    // fbo
    useMSAA = true;
    
    getTransformRef().setWidth(640);
    getTransformRef().setHeight(480); // standard canvas layer size
    
    addOscChild(&transform); // add the transform as an OSC child
    //    addOscChild(&effectsChain); // add the associated effects chain as a child
        
    addOscMethod("order");
    addOscMethod("lock");
    addOscMethod("solo");
    addOscMethod("label");
        
    addOscMethod("stretchmode");
    addOscMethod("clipping");
    
    fboInput = ofPtr<ofFbo>(new ofFbo());
    fboInput->allocate(transform.getWidth(), transform.getHeight());
    
    fboInput->begin();
    ofClear(0,0,0,0);
    fboInput->end();
    
    fboMask = ofPtr<ofFbo>(new ofFbo());
    fboMask->allocate(transform.getWidth(), transform.getHeight());

    fboMask->begin();
    ofClear(0,0,0,0);
    fboMask->end();
    
    fboLayer = ofPtr<ofFbo>(new ofFbo());
    fboLayer->allocate(transform.getWidth(), transform.getHeight());

    fboLayer->begin();
    ofClear(0,0,0,0);
    fboLayer->end();
    
    // TODO: fbos need callbacks from the transform to make sure they resize correctly

}

//--------------------------------------------------------------
bool Layer::dispose() {
    inputA->dispose();
    inputB->dispose();
    return true;
}

////--------------------------------------------------------------
//bool Layer::isFrameNew() { return true;} ;
//
////--------------------------------------------------------------
//ofPixelsRef Layer::getPixelsRef() {
//    fbo->readToPixels(pix);
//    return pix;
//};

//--------------------------------------------------------------
//bool Layer::isLoaded() {return true;}


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
    transform.setPosition(pos);
}

//--------------------------------------------------------------
void Layer::setRectangle(const ofRectangle& rect) {
    transform.setPosition(ofPoint(rect.x,rect.y));
    transform.setSize(rect.width,rect.height);
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
    inputA->update();
    inputB->update();
}

void Layer::draw() {
    
//    LayerTransform* xform = getTransformRef();
    
    int w = transform.getWidth();
    int h = transform.getHeight();
    
    ofPoint a = transform.getAnchorPoint();
    if(transform.isAnchorPointNormalized()) {
        a.x *= w;
        a.y *= h;
    }
    
    ofPoint p = transform.getPosition();
    if(transform.isPositionNormalized()) ofLogWarning("Layer") << "Normalized position is not yet supported.";

    ofPoint r = transform.getRotation();
    if(transform.isRotationNormalized()) r *= 360.0f;
    
    ofPoint s = transform.getScale();
    float opacity = transform.getOpacity();
    
    ofPushMatrix();
    
    /*if (opacity < 255)*/ ofEnableAlphaBlending();
    
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

//    if(bDrawDebugInfo) {
//        ofPushStyle();
//        ofSetColor(255,255,0);
//        ofDrawBitmapString("Source/Mask: " + ofToString(i), ofPoint(0,(i+1)*12,0));
//        ofPopStyle();
//    }
    
    
    // BEGIN EFFECTS COMPOSITION
    
    // TODO: mixing shader here


    // clear the layer fbo

    MaskedInput* currentInput = getCurrentInput();
    
    // TODO, we don't need to write image tex into FBOs if the shared images are not new
    
    if(currentInput->getInput().hasFrame()) {
        if(isFboInputDirty || currentInput->getInput().isFrameNew()) {
            drawFrameIntoFbo(currentInput->getInput().getFrame(),fboInput);
            isFboLayerDirty = true;
        } else {
            // fbo does not need to be updated
        }
        
        if(currentInput->getMask().hasFrame()) {
            if(isFboMaskDirty || currentInput->getMask().isFrameNew()) {
                drawFrameIntoFbo(currentInput->getMask().getFrame(),fboMask);
                isFboLayerDirty = true;
            } else {
                // fbo does not need to be updated
            }
            
            AlphaMask& alphaMask = layerManager->getEngineInterface()->getEffectsManager()->getAlphaMaskRef();
            AlphaMaskSettings& settings = currentInput->getAlphaMaskSettings();

            fboLayer->begin();
            ofClear(0,0,0,0);
            ///// shade!
            alphaMask.begin();
            alphaMask.apply(fboInput->getTextureReference(),
                            fboMask->getTextureReference(),
                            settings);
            fboLayer->draw(0,0); // use this image to map the pix
            alphaMask.end();
            ///// end shade
            fboLayer->end();
            
            isFboLayerDirty = true;

        } else {
            // there was no mask texture, thus, no masking
            fboLayer->begin();
            ofClear(0,0,0,0);
            fboInput->draw(0,0);
            fboLayer->end();
            
            isFboLayerDirty = true;

        }
    } else {
        // nothing to draw
    }
    
    // render the image
    fboLayer->draw(0,0);
    
    // END COMPOSITION

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

    /*if (opacity < 255)*/ ofDisableAlphaBlending();
    
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
void Layer::drawFrameIntoFbo(ofxSharedVideoFrame frame, ofPtr<ofFbo> fbo) {
//    cout << "drawing frame!" << frame->getWidth() << "/" << frame->getHeight() << endl;
    
    fbo->begin();
    ofClear(0,0,0,0);
    
    float w = transform.getWidth();
    float h = transform.getHeight();
    
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
        ofLogWarning("Layer") << "update(): Unknown layer stretch mode." << endl;
    }
    
    
    fbo->end(); // end the fbo
}

////--------------------------------------------------------------
//bool Layer::hasInputFrame(int index) const {
//    return inputs[index].hasFrame();
//}
//
////--------------------------------------------------------------
//bool Layer::hasMaskFrame(int index) const {
//    return masks[index].hasFrame();
//}
//
////--------------------------------------------------------------
//LayerSink& Layer::getInputSink(int index) {
//    return inputs[index];
//}
//
////--------------------------------------------------------------
//LayerSink& Layer::getMaskSink(int index) {
//    return masks[index];
//}
//
////--------------------------------------------------------------
//const LayerSink& Layer::getInputSink(int index) const {
//    return inputs[index];
//}
//
////--------------------------------------------------------------
//const LayerSink& Layer::getMaskSink(int index) const {
//    return masks[index];
//}

//--------------------------------------------------------------
LayerTransform& Layer::getTransformRef() { return transform; };

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
MaskedInput* Layer::getCurrentInput() {
    return currentInputIsA ? inputA : inputB;
}

//--------------------------------------------------------------
string Layer::toString() const {
    stringstream ss;
    ss << "[Layer: name: " << getName();
//    ss << " hasInput: " << hasInputFrame();
//    ss << " isInputSinking: " << getInputSink().isSinking();
//    ss << " hasMask: " << hasMaskFrame();
//    ss << " isMaskSinking: " << getMaskSink().isSinking() << endl;
    ss << " [xform: " << endl;
    ss << "   [size: " << transform.getSize() << "]"<< endl;
    ss << "   [pos: " << transform.getPosition() << "]"<< endl;
    ss << "   [anch: " << transform.getAnchorPoint() << "]"<< endl;;
    ss << "   [scale: " << transform.getScale() << "]"<< endl;
    ss << "   [rot: " << transform.getRotation() << "]"<< endl;
//    ss << "   [orient: " << transform.getOrientation() << "]"<< endl;
    ss << "   [opacity: " << transform.getOpacity() << "]"<< endl;
    ss << "]]";
    return ss.str();
}

