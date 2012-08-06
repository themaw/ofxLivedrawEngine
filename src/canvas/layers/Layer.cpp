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
    if(fbo != NULL) {
        delete fbo;
        fbo = NULL;
    }
    if(sourcePlayer != NULL) {
        delete sourcePlayer;
        sourcePlayer = NULL;
    }
    
    if(maskPlayer != NULL) {
        delete maskPlayer;
        maskPlayer = NULL;
    } // TODO : what do do about kids? delete the kids or set them to root?
}

//--------------------------------------------------------------
void Layer::init() {
    sourcePlayer = NULL;
    maskPlayer = NULL;
    
//    sourcePlayer = new FrameBufferPlayer(this);
//    sourcePlayer->addOscNodeAlias("source");
//    maskPlayer = new FrameBufferPlayer(this);
//    maskPlayer->addOscNodeAlias("mask");
//
//    addOscChild(sourcePlayer);
//    addOscChild(maskPlayer);
    
    //    effectsChain.setup();
    solo = false;
    locked = false;
    
    // fbo
    useMSAA = true;
    
    getTransform()->setWidth(640);
    getTransform()->setHeight(480); // standard canvas layer size
    
    addOscChild(&transform); // add the transform as an OSC child
    //    addOscChild(&effectsChain); // add the associated effects chain as a child
    
    addOscMethod("order");
    addOscMethod("lock");
    addOscMethod("solo");
    addOscMethod("label");
    
    
    addOscMethod("swap");
    
    
    
    fbo = new ofFbo();
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
set<Layer*> Layer::getLayerChildren() {
    return layerChildren;
}

////--------------------------------------------------------------
//bool Layer::hasChild(Layer* _layerChild) {
//    return find (layerChildren.begin(), 
//                 layerChildren.end(), 
//                 _layerChild) != layerChildren.end();
//}

////--------------------------------------------------------------
//set<Layer*>::iterator Layer::findChild(Layer* _layerChild) {
//    return find (layerChildren.begin(), 
//                 layerChildren.end(), 
//                 _layerChild);
//}

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
void Layer::setPosition(ofPoint pos) {
    getTransform()->setPosition(pos);
}

//--------------------------------------------------------------
void Layer::setRectangle(ofRectangle rect) {
    getTransform()->setPosition(ofPoint(rect.x,rect.y));
    getTransform()->setSize(rect.width,rect.height);
}

//--------------------------------------------------------------
void Layer::processOscCommand(const string& command, const ofxOscMessage& m) {
    
    cout << "Layer::const string& command, const ofxOscMessage& m(const string& pattern, ofxOscMessage& m)" << command << "/" << endl;
    
    if(isMatch(command,"order")) {
        
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
string Layer::getName() {
    return layerName;
}

//--------------------------------------------------------------
void Layer::setName(string _name) {
    layerName = _name;
    addOscNodeAlias(layerName);
}

//--------------------------------------------------------------
void Layer::update() {
//    sourcePlayer->update();
//    maskPlayer->update();
}

//--------------------------------------------------------------
void Layer::onEnabled() {}

//--------------------------------------------------------------
void Layer::onDisabled() {}