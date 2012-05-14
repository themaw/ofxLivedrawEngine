/*
 *  CanvasLayer.cpp
 *  livedraw
 *
 *  Created by Christopher P. Baker on 12/3/10.
 *  Copyright 2010 Murmur Labs LLC. All rights reserved.
 *
 */

#include "CanvasLayer.h"

//--------------------------------------------------------------
CanvasLayer::CanvasLayer(CanvasLayerManager* _layerManager, string name, ofPoint pos, CanvasLayer* _layerParent) : OscNodeListener("/"+name) {
    layerManager = _layerManager;
    layerName = name;
    layerParent = _layerParent;
    setPosition(pos);
}

//--------------------------------------------------------------
CanvasLayer::CanvasLayer(CanvasLayerManager* _layerManager, string name, ofPoint pos) : OscNodeListener("/"+name) {
    layerManager = _layerManager;
    layerName = name;
    layerParent = NULL;
    setPosition(pos);
}

//--------------------------------------------------------------
CanvasLayer::CanvasLayer(CanvasLayerManager* _layerManager, string name) : OscNodeListener("/"+name) {
    layerManager = _layerManager;
    layerName = name;
    layerParent = NULL;
}

//--------------------------------------------------------------
CanvasLayer::~CanvasLayer() {
    if(source != NULL) delete source;
    if(mask != NULL) delete mask;
    if(fbo != NULL) delete fbo;
    
    // TODO : what do do about kids? delete the kids or set them to root?
}

//--------------------------------------------------------------
void CanvasLayer::setAssetManager(AssetManager* _assetManager) {
    assetManager = _assetManager;
}

//--------------------------------------------------------------
//void CanvasLayer::setEffectsManager(EffectsManager* _effectsManager) {
//    effectsManager = _effectsManager;
//    effectsChain.setEffectsManager(effectsManager);
//}

//--------------------------------------------------------------

void CanvasLayer::setup() {
//    effectsChain.setup();
    solo = false;
    locked = false;
    
    // fbo
    useMSAA = true;
    
    getTransform()->setWidth(640);
    getTransform()->setHeight(480); // standard canvas layer size
    
    addOscChild(&transform); // add the transform as an OSC child
//    addOscChild(&effectsChain); // add the associated effects chain as a child

    addOscCommand("/input");
    addOscCommand("/mask");
        
    addOscCommand("/order");
    
    addOscCommand("/lock");
    addOscCommand("/solo");
    addOscCommand("/label");

    fbo = new ofFbo();

    fbo->allocate(getTransform()->getWidth(), getTransform()->getHeight());

    source = new ofVideoPlayer();
    mask = new ofImage();
}

//--------------------------------------------------------------
bool CanvasLayer::bringFoward() {
    return layerManager->bringLayerForward(this);
}
//--------------------------------------------------------------
bool CanvasLayer::sendBackward() {
    return layerManager->sendLayerBackward(this);
}
//--------------------------------------------------------------
bool CanvasLayer::bringToFront() {
    return layerManager->bringLayerToFront(this);    
}
//--------------------------------------------------------------
bool CanvasLayer::sendToBack() {
    return layerManager->sendLayerToBack(this);
}

// node info
//--------------------------------------------------------------
CanvasLayer* CanvasLayer::getLayerRoot() {
    // recursively locate root
    return layerParent != NULL ? layerParent->getLayerRoot() : NULL;
}

//--------------------------------------------------------------
CanvasLayer* CanvasLayer::getLayerParent() {
    return layerParent;
}

//--------------------------------------------------------------
vector<CanvasLayer*> CanvasLayer::getLayerChildren() {
    return layerChildren;
}

//--------------------------------------------------------------
bool CanvasLayer::hasChild(CanvasLayer* _layerChild) {
    return find (layerChildren.begin(), 
                 layerChildren.end(), 
                 _layerChild) != layerChildren.end();
}

//--------------------------------------------------------------
vector<CanvasLayer*>::iterator CanvasLayer::findChild(CanvasLayer* _layerChild) {
    return find (layerChildren.begin(), 
                 layerChildren.end(), 
                 _layerChild);
}


//--------------------------------------------------------------
void CanvasLayer::setLayerParent(CanvasLayer* _layerParent) {
    
    // setting the layer parent does:
    // 0. checks to see if the parent is different.
    // 1. removes the layer from an existing parent.
    // 2. sets a new parent reference.
    // 3. adds the item to the parent.
    

    if(_layerParent == layerParent) {
        // already set
        return;
    }

    
    if(layerParent != NULL) { // if it has a parent, remove it
        // remove from the current parent
        if(!layerParent->removeLayerChild(this)) {
            ofLog(OF_LOG_ERROR, "CanvasLayer::setLayerParent(): Error removing child from previous parent.");  
        } 
    }

    layerParent = _layerParent; // set a new parent reference
    
    if(layerParent != NULL) {
        layerParent->addLayerChild(this); // add item to the new parent
    } else {
        layerManager->addLayerAsRoot(this);
    }
    
}
//--------------------------------------------------------------
bool CanvasLayer::addLayerChild(CanvasLayer* _layerChild) {
    vector<CanvasLayer*>::iterator layerParentIter = findChild(this);

    if(layerParentIter == layerChildren.end()) {
        layerChildren.push_back(_layerChild);
        return true;
    } else {
        return false;
    }    
}

//--------------------------------------------------------------
bool CanvasLayer::removeLayerChild(CanvasLayer* _layerChild) {
    vector<CanvasLayer*>::iterator it = findChild(_layerChild);
    if(it != layerChildren.end()) {
        _layerChild->setLayerParent(NULL);
        layerChildren.erase(it);
        return true;
    } else {
        // did not have it
        return false;
    }
}

//--------------------------------------------------------------
void CanvasLayer::setPosition(ofPoint pos) {
    getTransform()->setPosition(pos);
}

//--------------------------------------------------------------
void CanvasLayer::setRectangle(ofRectangle rect) {
    getTransform()->setPosition(ofPoint(rect.x,rect.y));
    getTransform()->setSize(rect.width,rect.height);
}

//--------------------------------------------------------------
void CanvasLayer::processOscMessage(string address, ofxOscMessage& m) {
    
    if(isMatch(address, "/input")) {
        if(validateOscSignature("s",m)) {
            VideoMediaAsset* src = NULL;
            string assetId = m.getArgAsString(0);
            src = assetManager->getVideoAsset(assetId);
            
            if(src != NULL) {
                setSource(src);
            } else {
                ofLog(OF_LOG_ERROR, "CanvasLayer: [" + assetId + "] does not exist."); 
            }
        }
        
    } else if(isMatch(address, "/mask")) {
        if(validateOscSignature("s",m)) {
//            ImageMediaAsset* src = NULL;
//            string assetId = m.getArgAsString(0);
//            src = assetManager->getImageAsset(assetId);
//            
//            if(src != NULL) {
//                setMask(src);
//            } else {
//                ofLog(OF_LOG_ERROR, "CanvasLayer: [" + assetId + "] does not exist."); 
//            }
        }
    } else if(isMatch(address, "/order")) {
        
        cout << "IN HERE " << endl;
        
        if(validateOscSignature("[sfi]", m)) {
            if(m.getArgType(0) == OFXOSC_TYPE_STRING) {
                string command = toLower(m.getArgAsString(0));
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
                
                int targetLayer = m.getArgAsInt32(0);
                
                cout << "moving to " << targetLayer << endl;
                
            }

            
        }
    } else if(isMatch(address, "/lock")) {
        if(validateOscSignature("[fi]", m)) {
            int val = m.getArgAsInt32(0);
            locked = (val == 1);
            layerManager->setLayerLock(this, locked);
        }
    } else if(isMatch(address, "/solo")) {
        if(validateOscSignature("[fi]", m)) {
            int val = m.getArgAsInt32(0);
            solo = (val == 1);
            layerManager->setLayerSolo(this, solo);
        }
    } else if(isMatch(address, "/label")) {
        if(validateOscSignature("[fi][fi][fi][fi]?", m)) {
            label.r = m.getArgAsFloat(0);
            label.g = m.getArgAsFloat(1);
            label.b = m.getArgAsFloat(2);
            if(m.getNumArgs() < 4) {
                label.a = m.getArgAsFloat(3);
            }
        }
    }
    
}

//--------------------------------------------------------------
void CanvasLayer::setSource(VideoMediaAsset* src) {
    if(source->isLoaded()) {
        delete source;
        source = new ofVideoPlayer();
    }
    
    source->loadMovie(src->getAssetURI().toString());
    source->play();
}

//--------------------------------------------------------------
void CanvasLayer::setMask(ImageMediaAsset* src) {
    mask->loadImage(src->getAssetURI().toString());
}

//--------------------------------------------------------------
string CanvasLayer::getName() {
    return layerName;
}

//--------------------------------------------------------------
void CanvasLayer::setName(string _name) {
    layerName = _name;
    setOscNodeName("/"+layerName);
}

//--------------------------------------------------------------
void CanvasLayer::update()
{
    source->update();
}

//--------------------------------------------------------------
void CanvasLayer::onEnabled() {}

//--------------------------------------------------------------
void CanvasLayer::onDisabled() {}