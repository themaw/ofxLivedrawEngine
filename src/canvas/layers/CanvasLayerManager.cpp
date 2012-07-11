//
//  CanvasLayerManager.cpp
//  livedraw
//
//  Created by Christopher P. Baker on 5/17/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "CanvasLayerManager.h"

//--------------------------------------------------------------
CanvasLayerManager::CanvasLayerManager() : ofxOscRouterNode("/layer") {
    addOscNodeAlias("/lay");
    addOscNodeAlias("/l");
 
    addOscMethod("/new");
    addOscMethod("/delete");
}

//--------------------------------------------------------------
CanvasLayerManager::~CanvasLayerManager() {
    for (int i = 0; i < layers.size(); i++)
        delete layers[ i ];
    layers.clear();
}


//--------------------------------------------------------------
//void CanvasLayerManager::setEffectsManager(EffectsManager* _effectsManager) {
//    effectsManager = _effectsManager;
//}

//--------------------------------------------------------------
void CanvasLayerManager::processOscMessage(const string& pattern, const ofxOscMessage& m) {
    
    cout << "CanvasLayerManager::const string& pattern, const ofxOscMessage& m(const string& pattern, ofxOscMessage& m)" << endl;
    
    
    if(isMatch(pattern,"/new")) {
        // /livedraw/canvas/layer/new      LAYER_NAME [X_POSITION Y_POSITION [Z_POSITION]]
        if(validateOscSignature("s[fi][fi][fi]?", m)) {

            ofPoint p(0.0f,0.0f,0.0f);

            string layerName = m.getArgAsString(0);
            
            if(m.getNumArgs() > 1) {
                p.x = m.getArgAsFloat(1);
                p.y = m.getArgAsFloat(2);
                if(m.getNumArgs() > 3) {
                    p.z = m.getArgAsFloat(3);
                }
            }

            // make a new layer
            newLayer(layerName, p);
            
        }
    } else if(isMatch(pattern, "/delete")) {
        // /livedraw/canvas/layer/new      LAYER_NAME
        if(validateOscSignature("s", m)) {
            string layerName = m.getArgAsString(0);
            
            // delete a layer
            deleteLayer(layerName);
        }
    }
    
}


//--------------------------------------------------------------
CanvasLayer* CanvasLayerManager::newLayer(string layerName, ofPoint point, CanvasLayer* parentLayer) {

    cout << "making new layer |"<< layerName << "| " << point << " parent=" << (parentLayer == NULL ? "X" : parentLayer->getName()) << endl;
    
    // rename if needed
    if(hasLayer(layerName)) {
        layerName = layerName + "_" + ofToString(ofGetElapsedTimeMillis());
    } else {}

    CanvasLayer* cl = new CanvasLayer(this,layerName,point,parentLayer); // MAKE SURE THESE ARE DELETED
    
//
    cl->setPosition(point);
 //   cl->setAssetManager(assetManager);
//    cl->setEffectsManager(effectsManager);

    //CanvasLayerTransform* xform = cl->getTransform();
    //ofPoint p = xform->getPosition();

    layers.push_back(cl);

    addOscChild(cl);

    return cl;
}

//--------------------------------------------------------------
bool CanvasLayerManager::addLayerAsRoot(CanvasLayer* layer) {
    renderTree.push_back(layer);
}


//--------------------------------------------------------------
bool CanvasLayerManager::hasLayer(string name) {
    return getLayerByName(name) != NULL;
}

//--------------------------------------------------------------
bool CanvasLayerManager::deleteLayer(string layerName) {
    bool success = false;
        
    for ( it=layers.begin() ; it < layers.end(); it++ ) {
        if(isMatch(layerName,(*it)->getName())) {
            break;
        }
    }

    // delete first, then erase from the vector
    if(it != layers.end()) {
        removeOscChild(*it); // remove it from the OSC tree!
        delete *it;       // free the memory
        layers.erase(it); // erase it from the vector
        success = true;
    } else {
        success = false; // something went wrong
    }
    
    return success;

}

//--------------------------------------------------------------
CanvasLayer* CanvasLayerManager::getLayerByName(string layerName) {
    CanvasLayer* r = NULL;
    for ( it=layers.begin() ; it < layers.end(); it++ ) {
        if(isMatch(layerName,(*it)->getName())) {
            r = (*it);
            break;
        }
    }
    return r;
}


//--------------------------------------------------------------
void CanvasLayerManager::update() {
    for(int i = 0; i < layers.size(); i++) layers[i]->update();
}

//--------------------------------------------------------------
void CanvasLayerManager::draw() {
    // we are going to draw onto the caller's drawing context (namely, canvas renderer)
    
    // TODO: perhaps best to manage groups within layers manager????
    // /livedraw/canvas/layer/group/(GROUP_NAME)/add/layer
    // everything automatically shows up in a group manager
    
    // reset it to white
//    ofSetColor(255,255,255,80);
    
    for(int i = 0; i < layers.size(); i++) {
		
		CanvasLayer* layer = layers[i];
		
		
		CanvasLayerTransform* xform = layer->getTransform();
		ofPoint a = xform->getAnchorPoint();
		ofPoint p = xform->getPosition();
		ofPoint r = xform->getRotation();
		ofPoint s = xform->getScale();
        int opacity = xform->getOpacity();

		
        int w = xform->getWidth();
        int h = xform->getHeight();
        
        //cout << layer->getName() << ": " << p.x << "/" << p.y << "/" << p.z << endl;
        
		glPushMatrix();
		
        if (opacity < 255) ofEnableAlphaBlending();
        
        ofTranslate(p.x, p.y, p.z);

        ofRotateX(r.x);
		ofRotateY(r.y);
		ofRotateZ(r.z);
        
        ofScale(s.x, s.y, s.z);
        
		// do effects
		
		// get image reference and draw it
		//layer->getSource()->getImage()->draw(0,0);
		
        //        layer->draw();
        
        //layer->getFbo()->begin();

        ofSetColor(255,255,255,opacity);

        
 //       ofFill();
        
        if(layer->getSourcePlayer()->isLoaded()) {
            layer->getSourcePlayer()->draw(-a.x, -a.y);
        } else {
            ofPushStyle();
            ofSetColor(127);
            ofNoFill();
            ofRect(-a.x, -a.y,w,h);
            ofLine(-a.x, -a.y, -a.x + w, -a.y + h );
            ofLine(-a.x, -a.y + h, -a.x + w, -a.y );
            ofPopStyle();
        }
            
        if(layer->getMaskPlayer()->isLoaded()) {
            layer->getMaskPlayer()->draw(-a.x, -a.y);
        } else {
            ofPushStyle();
            ofSetColor(127);
            ofNoFill();
            ofRect(-a.x, -a.y,w,h);
            ofLine(-a.x, -a.y, -a.x + w, -a.y + h );
            ofLine(-a.x, -a.y + h, -a.x + w, -a.y );
            ofPopStyle();
        }


        
        //        ofRect(-a.x, -a.y,0,w,h);
//        ofNoFill();
        //layer->getFbo()->end();
        
        //layer->getFbo()->draw(0,0);

        if (opacity < 255) ofDisableAlphaBlending();

        
		glPopMatrix();
         
        
        
	}
    
    ofSetColor(255);
    
}

//--------------------------------------------------------------
int CanvasLayerManager::getLayerIndex(string layerName) {
    
}

//--------------------------------------------------------------
bool CanvasLayerManager::bringLayerForward(CanvasLayer* layer) {
    cout << "sending layer forward " << layer->getName() << endl;
}

//--------------------------------------------------------------
bool CanvasLayerManager::sendLayerBackward(CanvasLayer* layer) {
    cout << "sending layer backward " << layer->getName() << endl;
}

//--------------------------------------------------------------
bool CanvasLayerManager::sendLayerToBack(CanvasLayer* layer) {
    cout << "sending layer to back " << layer->getName() << endl;
}

//--------------------------------------------------------------
bool CanvasLayerManager::bringLayerToFront(CanvasLayer* layer) {
    cout << "sending layer to front " << layer->getName() << endl;
}

//--------------------------------------------------------------
bool CanvasLayerManager::sendLayerTo(CanvasLayer* layer, int targetLayerIndex) {
    cout << "sending layer " << layer->getName() << " to " << targetLayerIndex << endl;
}

//--------------------------------------------------------------
void CanvasLayerManager::setLayerSolo(CanvasLayer* layer, bool solo) {
    cout << "solo layer " << layer->getName() << " solo = " << solo << endl;
}
//--------------------------------------------------------------
void CanvasLayerManager::setLayerLock(CanvasLayer* layer, bool lock) {
    cout << "lock layer " << layer->getName() << " lock =" << lock <<  endl;
}


void CanvasLayerManager::dump() {

    cout << "layers:" << endl;
    for(it = layers.begin(); it != layers.end(); it++) {
        cout << (*it)->getName() << endl;
    }
    
    cout << "renderTree:" << endl;
    for(it = renderTree.begin(); it != renderTree.end(); it++) {
        cout << (*it)->getName() << endl;
    }

}

