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
    
    debugInfo = true;
    
//    sourcePlayer = new FrameBufferPlayer(this);
//    sourcePlayer->addOscNodeAlias("source");
//    maskPlayer = new FrameBufferPlayer(this);
//    maskPlayer->addOscNodeAlias("mask");
//
//    addOscChild(sourcePlayer);
//    addOscChild(maskPlayer);
    
    
    // A
    sources.push_back(LayerRenderSink());
    masks.push_back(LayerRenderSink());

    // B
    sources.push_back(LayerRenderSink());
    masks.push_back(LayerRenderSink());

    
    //    effectsChain.setup();
    solo = false;
    locked = false;
    
    // fbo
    useMSAA = true;
    
    getTransform()->setWidth(640);
    getTransform()->setHeight(480); // standard canvas layer size
    
    addOscChild(&transform); // add the transform as an OSC child
    //    addOscChild(&effectsChain); // add the associated effects chain as a child
    
    addOscMethod("sink");
    
    
    addOscMethod("order");
    addOscMethod("lock");
    addOscMethod("solo");
    addOscMethod("label");
    
    
    addOscMethod("swap");
    
    cout << "LAYER--" << toString() << endl;
    
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
    
    if(isMatch(command,"order")) {
        
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
        if(validateOscSignature("[sfi]", m)) {
            debugInfo = getArgAsBoolean(m, 0);
        }
    }/* else if(isMatch(address, "/swap")) {
        swapSourceMaskPlayers();
    }*/
    
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
    
    ofSetColor(255,opacity);
    
    
    // 
    for(int i = 0; i < sources.size(); i++) {
        
        ofPushStyle();
        ofSetColor(255,255,0);
        ofDrawBitmapString("Source/Mask: " + ofToString(i), ofPoint(0,(i+1)*12,0));
        ofPopStyle();
        
        ofPushMatrix();
        ofTranslate(-a.x, -a.y); // anchor point offset
        
        if(hasSource(i)) {
            getSourceSink(i).getFrame()->draw(0,0);
        } else {
            ofPushStyle();
            ofSetColor(127);
            ofNoFill();
            ofRect(0,0,w,h);
            ofLine(0,0,w,h);
            ofLine(0,h,w,0);
            ofPopStyle();
            
        }
        
        if(hasMask(i)) {
            getMaskSink(i).getFrame()->draw(0,0);
        } else {
            ofPushStyle();
            ofSetColor(127);
            ofNoFill();
            ofRect(0,0,w,h);
            ofLine(0,0,w,h);
            ofLine(0,h,w,0);
            ofPopStyle();
        }
        
        ofPopMatrix();
    }
    
    if(debugInfo) {
        ofPushStyle();
        ofSetColor(255);
        ofDrawBitmapString("Layer: " + getName(), ofPoint(0,0,0));
        ofPopStyle();
    }

    if (opacity < 255) ofDisableAlphaBlending();
    
    // draw those children
    vector<Layer*>& children = getLayerChildrenRef();
    for(int i = 0; i < children.size(); i++) {
        children[i]->draw();
        cout << "drawing child." << endl;
    }
    
    ofPopMatrix();

}

//--------------------------------------------------------------
void Layer::onEnabled() {}

//--------------------------------------------------------------
void Layer::onDisabled() {}