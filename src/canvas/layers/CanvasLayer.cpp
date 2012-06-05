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
CanvasLayer::CanvasLayer(CanvasLayerManager* _layerManager, string name, ofPoint pos, CanvasLayer* _layerParent) : ofxOscRouterNode("/"+name) {
    cout << "_layerManager=" << _layerManager << " " << name << " " << pos << " cl=" << endl;
    
    
    layerManager = _layerManager;
    layerName = name;
    layerParent = _layerParent;
    setPosition(pos);
    init();
}

//--------------------------------------------------------------
CanvasLayer::CanvasLayer(CanvasLayerManager* _layerManager, string name, ofPoint pos) : ofxOscRouterNode("/"+name) {
    layerManager = _layerManager;
    layerName = name;
    layerParent = NULL;
    setPosition(pos);
    init();
}

//--------------------------------------------------------------
CanvasLayer::CanvasLayer(CanvasLayerManager* _layerManager, string name) : ofxOscRouterNode("/"+name) {
    layerManager = _layerManager;
    layerName = name;
    layerParent = NULL;
    init();
}

//--------------------------------------------------------------
CanvasLayer::~CanvasLayer() {
    if(fbo != NULL) delete fbo;
    if(sourcePlayer != NULL) delete sourcePlayer;
    if(maskPlayer != NULL)   delete maskPlayer;
    // TODO : what do do about kids? delete the kids or set them to root?
}

//--------------------------------------------------------------
void CanvasLayer::init() {
    sourcePlayer = new FrameBufferPlayer();
    sourcePlayer->setParentLayer(this);
    maskPlayer = new FrameBufferPlayer();
    maskPlayer->setParentLayer(this);    

    sourcePlayer->setOscNodeName("/source");
    maskPlayer->setOscNodeName("/mask");
    addOscChild(sourcePlayer);
    addOscChild(maskPlayer);
    
    //    effectsChain.setup();
    solo = false;
    locked = false;
    
    // fbo
    useMSAA = true;
    
    getTransform()->setWidth(640);
    getTransform()->setHeight(480); // standard canvas layer size
    
    addOscChild(&transform); // add the transform as an OSC child
    //    addOscChild(&effectsChain); // add the associated effects chain as a child
    
    addOscMethod("/order");
    addOscMethod("/lock");
    addOscMethod("/solo");
    addOscMethod("/label");
    
    
    addOscMethod("/swap");
    
    
    
    fbo = new ofFbo();
    fbo->allocate(getTransform()->getWidth(), getTransform()->getHeight());
    

}

//--------------------------------------------------------------
//AssetManager* CanvasLayer::getAssetManager() {
//    return layerManager->getAssetManager();
//}
//
////--------------------------------------------------------------
//bool CanvasLayer::hasAssetManager() {
//    return layerManager->hasAssetManager();
//}


//--------------------------------------------------------------
//void CanvasLayer::setEffectsManager(EffectsManager* _effectsManager) {
//    effectsManager = _effectsManager;
//    effectsChain.setEffectsManager(effectsManager);
//}



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
    
    cout << "CanvasLayer::processOscMessage" << address << "/" << endl;
    
    if(isMatch(address, "/order")) {
        
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
            layerManager->setLayerLock(this, getArgAsBoolean(m,0));
        }
    } else if(isMatch(address, "/solo")) {
        if(validateOscSignature("[fi]", m)) {
            layerManager->setLayerSolo(this, getArgAsBoolean(m,0));
        }
    } else if(isMatch(address, "/label")) {
        if(validateOscSignature("[fi][fi][fi][fi]?", m)) {
            label = getArgsAsColor(m, 0);
        }
    } else if(isMatch(address, "/swap")) {
        swapSourceMaskPlayers();
    }
    
}

////--------------------------------------------------------------
//void CanvasLayer::setSource(MediaAsset* src) {
//    /*
//    if(source->isLoaded()) {
//        delete source;
//        source = new ofVideoPlayer();
//    }
//    
//    source->loadMovie(src->getAssetURI().toString());
//    source->play();
//     */
//}
//
////--------------------------------------------------------------
//void CanvasLayer::setMask(MediaAsset* src) {
//    //mask->loadImage(src->getAssetURI().toString());
//}


//--------------------------------------------------------------
void CanvasLayer::swapSourceMaskPlayers() {
    FrameBufferPlayer* tmp;
    tmp = getSourcePlayer();
    sourcePlayer = getMaskPlayer();
    maskPlayer = tmp;
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
void CanvasLayer::update() {
    sourcePlayer->update();
    maskPlayer->update();
}

//--------------------------------------------------------------
void CanvasLayer::onEnabled() {}

//--------------------------------------------------------------
void CanvasLayer::onDisabled() {}