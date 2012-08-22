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

#include "LayerManager.h"

//--------------------------------------------------------------
LayerManager::LayerManager() : ofxOscRouterNode("layers") {
    
    engine = NULL;
    
    addOscNodeAlias("lay");
    addOscNodeAlias("l");
 
    addOscMethod("new");
    addOscMethod("delete");
    addOscMethod("dump");
}

//--------------------------------------------------------------
LayerManager::~LayerManager() {
    for (it = layers.begin(); it != layers.end(); it++) {
        delete *it; // free it
    }
    layers.clear(); // clear it;
}

//--------------------------------------------------------------
void LayerManager::processOscCommand(const string& command, const ofxOscMessage& m) {
    
    if(isMatch(command,"new")) {
        // /livedraw/canvas/layer/new      LAYER_NAME [X_POSITION Y_POSITION [Z_POSITION]]
        if(validateOscSignature("s[fi][fi][fi]?", m)) {
            string layerName = getArgAsStringUnchecked(m,0);
            ofPoint p = getArgsAsPoint(m, 1);
            // make a new layer
            addLayer(layerName, p);
        }
    } else if(isMatch(command, "delete")) {
        // /livedraw/canvas/layer/new      LAYER_NAME
        if(validateOscSignature("s", m)) {
            string layerName = getArgAsStringUnchecked(m,0);
            // delete a layer
            queueUnregisterLayer(layerName);
        }
    } else if(isMatch(command, "dump")) {
        dump();
    }
    
}

//--------------------------------------------------------------
Layer* LayerManager::addLayer(const string& layerName, ofPoint point, Layer* parentLayer) {
    // rename if needed
    string validLayerName = validateAlias(layerName);
    Layer* layer = new Layer(this,validLayerName,point,parentLayer); // MAKE SURE THESE ARE DELETED
    //queueRegisterLayer(layer);
    registerLayer(layer);
    return layer;
}

//--------------------------------------------------------------
bool LayerManager::queueRegisterLayer(Layer* layer) {
    layer->setNodeActive(false);
    return registerQueue.insert(layer).second;
}

//--------------------------------------------------------------
bool LayerManager::queueUnregisterLayer(const string& alias) {
    Layer* toDelete = getLayer(alias);
    if(toDelete != NULL) {
        return queueUnregisterLayer(toDelete);
    } else {
        return false;
    }
}

//--------------------------------------------------------------
bool LayerManager::queueUnregisterLayer(Layer* layer) {
    layer->setNodeActive(false);
    return unregisterQueue.insert(layer).second;
}

////--------------------------------------------------------------
//bool LayerManager::addLayerAsRoot(Layer* layer) {
//    renderTree.push_back(layer);
//}


//--------------------------------------------------------------
bool LayerManager::hasAlias(const string& alias) {
    return aliases.find(alias) != aliases.end();
}

//--------------------------------------------------------------
Layer* LayerManager::getLayer(const string& alias) {
    aliasesIt = aliases.find(alias);
    
    if(aliasesIt != aliases.end()) {
        return aliasesIt->second;
    } else {
        return NULL;
    }
}

//--------------------------------------------------------------
void LayerManager::update() {
    // process all de/registration queues
    processQueues();
    
    // update assets
    updateLayers();

}

//--------------------------------------------------------------
void LayerManager::draw() {
    // we are going to draw onto the caller's drawing context (namely, canvas renderer)
        
    for (renderTreeIter  = renderTree.begin();
         renderTreeIter != renderTree.end();
         renderTreeIter++ ) {
		(*renderTreeIter)->draw();
	}
}


//--------------------------------------------------------------
int LayerManager::getLayerIndex(const string& alias) {
    return getLayerIndex(getLayer(alias));
}

//--------------------------------------------------------------
int  LayerManager::getLayerIndex(Layer* layer) {
    if(layer == NULL) {
        return -1;
    } else {
        // TODO : work on thi
        return 0;
    }
}

//--------------------------------------------------------------
bool LayerManager::bringLayerForward(Layer* layer) {
    ofLogNotice() << "LayerManager::bringLayerForward() " << layer->getName() << endl;
}

//--------------------------------------------------------------
bool LayerManager::sendLayerBackward(Layer* layer) {
    ofLogNotice() << "LayerManager::sendLayerBackward() " << layer->getName() << endl;
}

//--------------------------------------------------------------
bool LayerManager::sendLayerToBack(Layer* layer) {
    ofLogNotice() << "LayerManager::sendLayerToBack() " << layer->getName() << endl;
}

//--------------------------------------------------------------
bool LayerManager::bringLayerToFront(Layer* layer) {
    ofLogNotice() << "LayerManager::bringLayerToFront() " << layer->getName() << endl;
}

//--------------------------------------------------------------
bool LayerManager::sendLayerTo(Layer* layer, int targetLayerIndex) {
    ofLogNotice() << "LayerManager::sendLayerTo() " << layer->getName() << " to " << targetLayerIndex << endl;
}

//--------------------------------------------------------------
void LayerManager::setLayerSolo(Layer* layer, bool solo) {
    ofLogNotice() << "LayerManager::setLayerSolo() " << layer->getName() << " solo = " << solo << endl;
}
//--------------------------------------------------------------
void LayerManager::setLayerLock(Layer* layer, bool lock) {
    ofLogNotice() << "LayerManager::setLayerLock() " << layer->getName() << " lock =" << lock <<  endl;
}

//--------------------------------------------------------------
bool LayerManager::registerLayer(Layer* layer) {
    if(!hasAlias(layer->getName())) {
        aliases[layer->getName()] = layer;
    } else {
        ofLogError() << "LayerManager::registerLayer - alias already exists";
        return false;
    }
    
    if(!addOscChild(layer)) {
        ofLogError() << "LayerManager::registerLayer - failed to add as an osc child node";
        return false;
    }
    
    // turn it on
    layer->setNodeActive(true);

    // add it to the collection
    layers.insert(layer);
    
    // if it is a null parent, then it belongs in the render tree
    if(layer->getLayerParent() == NULL) {
        renderTree.push_back(layer);
    }
    
    return true;
    
}

//--------------------------------------------------------------
bool LayerManager::unregisterLayer(Layer* layer) {
    
    // is there a there there?
    if(layer == NULL) {
        ofLogWarning() << "LayerManager::unregisterLayer - asset is NULL";
        return false;
    }
    
    // tell the object to dispose of itself (free connections, kill other things, etc)
    if(!layer->dispose()) {
        ofLogWarning() << "LayerManager::unregisterLayer - unable to dispose " << layer->getName();
        return false;
    }
    
    // get rid of the alias
    if(hasAlias(layer->getName())) { // double check
        aliases.erase(layer->getName());
    }
    
    
    if(hasOscChild(layer) && !removeOscChild(layer)) {
        ofLogError() << "LayerManager::unregisterLayer - failed to remove as an osc child node";
        return false;
    }
    
    // remove the asset pointer from the assets set
    layers.erase(layer);
    
    // erase it from the render tree
    bool foundIt = false;
    int i = ofFind(renderTree, layer);
    if(i < renderTree.size()) {
        foundIt = true;
        renderTree.erase(renderTree.begin() + i);
    }
    
    if(layer->getLayerParent() == NULL && !foundIt) {
        ofLogError() << "A layer had a null parent, but wasn't found in the render tree root.";
    }
    
    // free the memory
    delete layer; // free the memory
    layer = NULL;
    // success
    return true;
}

//--------------------------------------------------------------
void LayerManager::processQueues() {
    // clear register queues
    if(!registerQueue.empty()) {
        for(it = registerQueue.begin();
            it != registerQueue.end();
            it++) {
            registerLayer(*it);
        }
        registerQueue.clear(); // done!
    }
    
    // clear unregister queue
    if(!unregisterQueue.empty()) {
        for(it = unregisterQueue.begin();
            it != unregisterQueue.end();
            it++) {
            unregisterLayer(*it);
        }
        unregisterQueue.clear(); // done!
    }
}

//--------------------------------------------------------------
void LayerManager::updateLayers() {
    for ( it=layers.begin(); it != layers.end(); it++ ) {
        (*it)->update();
    }
}

//--------------------------------------------------------------
string LayerManager::validateAlias(const string& name) {
    // get the original asset name
    string assetName = name;
    
    // get the normalized name for OSC purposes
    string assetId = normalizeOscNodeName(assetName);
    
    // if the alias exists, add an incremental
    bool     foundIt = false;
    int      maxSuffix = -1;
    
    // with the new natural ordering we probably don't need to
    // go through all of the items, but rather reverse_iterator from the end
    for ( it=layers.begin() ; it != layers.end(); it++ ) {
        string thisName = (*it)->getName();
        if(isMatch(assetId,thisName.substr(0,assetId.length()))) {
            if(thisName.length() > assetId.length()) {
                if(thisName[assetId.length()] == '_') {
                    string number = thisName.substr(assetId.length() + 1);
                    if(number.length() > 0) {
                        maxSuffix = MAX(maxSuffix,ofToInt(number));
                    }
                }
            }
            foundIt = true;
        }
    }
    
    if(foundIt) {
        assetId +=  ('_' + ofToString(maxSuffix + 1));
    }
    
    // toss a warning if the asset id differs from the asset's original name
    if(!isMatch(assetName, assetId)) {
        ofLogWarning() << "LayerManager::generateAssetId() - " << assetName << " produced variant : " << assetId + ".";
    }
    
    // return the generated asset id
    return assetId;
}


//--------------------------------------------------------------
void LayerManager::dump() {

    ofLogNotice() << "-------------------";
    ofLogNotice() << "Layer Manager Dump:";
    ofLogNotice() << "layers:";
    for(it = layers.begin(); it != layers.end(); it++) {
        ofLogNotice() << setw(4) << (*it)->toString();
    }
    
    ofLogNotice() << "renderTree:";
    for(renderTreeIter = renderTree.begin();
        renderTreeIter != renderTree.end();
        renderTreeIter++) {
        ofLogNotice() << setw(4) << (*renderTreeIter)->toString();
    }

}

