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

#include "LayerTransform.h"

//--------------------------------------------------------------
LayerTransform::LayerTransform(ofPoint _position, 
                     ofPoint _anchorPoint, 
                     ofPoint _rotation, 
                     ofPoint _scale, 
                     int _opacity) : 
ofxEnablerInterface(true),  
ofxOscRouterNode("transform") {
    
    position = ofxClampedPoint(_position);
    anchorPoint = ofxClampedPoint(_anchorPoint);
    rotation = ofxClampedPoint(_rotation);
    scale = ofxClampedPoint(_scale);
    opacity = _opacity;
    size = ofPoint(640,480);
    
    init();
}

//--------------------------------------------------------------
LayerTransform::LayerTransform(ofPoint _position, 
                     ofPoint _anchorPoint, 
                     ofPoint _rotation, 
                     ofPoint _scale) : 
ofxEnablerInterface(true),  
ofxOscRouterNode("transform") {
    
    position = ofxClampedPoint(_position);
    anchorPoint = ofxClampedPoint(_anchorPoint);
    rotation = ofxClampedPoint(_rotation);
    scale = ofxClampedPoint(_scale);
    opacity = 255;
    size = ofPoint(640,480);
    
    init();
}

//--------------------------------------------------------------
LayerTransform::LayerTransform(ofPoint _position, 
                     ofPoint _anchorPoint, 
                     ofPoint _rotation) : 
ofxEnablerInterface(true),  
ofxOscRouterNode("transform") {
    
    position = ofxClampedPoint(_position);
    anchorPoint = ofxClampedPoint(_anchorPoint);
    rotation = ofxClampedPoint(_rotation);
    scale = ofxClampedPoint(ofPoint(1.0f, 1.0f, 1.0f));
    opacity = 255;
    size = ofPoint(640,480);
    
    init();
}

//--------------------------------------------------------------
LayerTransform::LayerTransform(ofPoint _position, 
                     ofPoint _anchorPoint) : 
ofxEnablerInterface(true),  
ofxOscRouterNode("transform") {
    
    position = ofxClampedPoint(_position);
    anchorPoint = ofxClampedPoint(_anchorPoint);
    scale = ofxClampedPoint(ofPoint(1.0f, 1.0f, 1.0f));
    opacity = 255;
    size = ofPoint(640,480);
    
    init();
}

//--------------------------------------------------------------
LayerTransform::LayerTransform(ofPoint _position) : 
ofxEnablerInterface(true),  
ofxOscRouterNode("transform") {
    
    position = ofxClampedPoint(_position);
    scale = ofxClampedPoint(ofPoint(1.0f, 1.0f, 1.0f));
    opacity = 255;
    size = ofPoint(640,480);
    
    init();
}

//--------------------------------------------------------------
LayerTransform::LayerTransform() : 
ofxEnablerInterface(true), 
ofxOscRouterNode("transform") {
    
    scale = ofxClampedPoint(ofPoint(1.0f, 1.0f, 1.0f));
    opacity = 255;
    size = ofPoint(640,480);
    
    init();
}



//--------------------------------------------------------------
void LayerTransform::init() {
    addOscMethod("position");
    addOscMethod("anchorpoint");
    addOscMethod("rotate");
    addOscMethod("scale");
    addOscMethod("opacity");
    addOscMethod("size");
    
}

//--------------------------------------------------------------
LayerTransform::~LayerTransform() {};

//--------------------------------------------------------------
void LayerTransform::processOscCommand(const string& command, const ofxOscMessage& m) {
    
    if(isMatch(command,"position")) {
        if(validateOscSignature("([if][if]?[if]?)|([s][if])", m)) {
            if(m.getArgType(0) == OFXOSC_TYPE_STRING) {
                char c = tolower(m.getArgAsString(0)[0]);
                float  val = m.getArgAsFloat(1);
                
                if(c == 'x') {
                    setPositionX(val);
                } else if(c == 'y') {
                    setPositionY(val);
                } else if(c == 'z') {
                    setPositionZ(val);
                } else {
                    ofLog(OF_LOG_ERROR, "LayerTransform: invalid arg type: " + ofToString(c) + " " + command);
                }
                
            } else {
                setPositionX(m.getArgAsFloat(0));
                if(m.getNumArgs() > 1) {
                    setPositionY(m.getArgAsFloat(1));
                    if(m.getNumArgs() > 2) {
                        setPositionZ(m.getArgAsFloat(2));
                    }
                }
            }
        }
        
    } else if(isMatch(command,"anchorpoint")) {
        if(validateOscSignature("([if][if]?[if]?)|([s][if])", m)) {
            if(m.getArgType(0) == OFXOSC_TYPE_STRING) {
                
                char c = tolower(m.getArgAsString(0)[0]);
                float  val = m.getArgAsFloat(1);
                
                if(c == 'x') {
                    setAnchorPointX(val);
                } else if(c == 'y') {
                    setAnchorPointY(val);
                } else if(c == 'z') {
                    setAnchorPointZ(val);
                } else {
                    ofLog(OF_LOG_ERROR, "LayerTransform: invalid arg type: " + ofToString(c) + " " + command);
                }
                
                
            } else {
                setAnchorPointX(m.getArgAsFloat(0));
                if(m.getNumArgs() > 1) {
                    setAnchorPointY(m.getArgAsFloat(1));
                    if(m.getNumArgs() > 2) {
                        setAnchorPointZ(m.getArgAsFloat(2));
                    }
                }
            }
        }
        
    } else if(isMatch(command,"rotate")) {
        if(validateOscSignature("([if][if]?[if]?)|([s][if][if]?[if]?)", m)) {
            
            if(m.getArgType(0) == OFXOSC_TYPE_STRING) {
                
                char c = tolower(m.getArgAsString(0)[0]);
                
                if(c == 'x') {
                    setRotationX(m.getArgAsFloat(1));
                } else if(c == 'y') {
                    setRotationY(m.getArgAsFloat(1));
                } else if(c == 'z') {
                    setRotationZ(m.getArgAsFloat(1));
                } else if(c == 'd') {
                    setRotationX(m.getArgAsFloat(1));
                    setRotationY(m.getArgAsFloat(2));
                    setRotationZ(m.getArgAsFloat(3));
                } else {
                    ofLog(OF_LOG_ERROR, "LayerTransform: invalid arg type: " + ofToString(c) + " " + command);
                }
                
                
            } else {
                setRotationX(m.getArgAsFloat(0));
                if(m.getNumArgs() > 1) {
                    setRotationY(m.getArgAsFloat(1));
                    if(m.getNumArgs() > 2) {
                        setRotationZ(m.getArgAsFloat(2));
                    }
                }
            }
            
            
            
        }
    } else if(isMatch(command,"scale")) {            
        if(validateOscSignature("([f][f]?[f]?)|([s][f])", m)) {
            if(m.getArgType(0) == OFXOSC_TYPE_STRING) {
                
                char c = tolower(m.getArgAsString(0)[0]);
                float val = m.getArgAsFloat(1);
                
                if(c == 'x') {
                    setScaleX(val);
                } else if(c == 'y') {
                    setScaleY(val);
                } else if(c == 'z') {
                    setScaleZ(val);
                } else {
                    ofLog(OF_LOG_ERROR, "LayerTransform: invalid arg type: " + ofToString(c) + " " + command);
                }
                
            } else {
                setScaleX(m.getArgAsFloat(0));
                if(m.getNumArgs() > 1) {
                    setScaleY(m.getArgAsFloat(1));
                    if(m.getNumArgs() > 2) {
                        setScaleZ(m.getArgAsFloat(2));
                    }
                }
            }
        }
        
    } else if(isMatch(command,"opacity")) {
        if(validateOscSignature("[if]", m)) {
            float  val = m.getArgAsFloat(0);
            setOpacity(val);
        }
    } else if(isMatch(command,"size")) {
        if(validateOscSignature("[if][if]", m)) {
            int w = m.getArgAsFloat(0);
            int h = m.getArgAsFloat(1);
            setSize(w,h);
        }
    }
    
}



//--------------------------------------------------------------
int LayerTransform::getWidth() {return size.getClampedX(); };
//--------------------------------------------------------------
int LayerTransform::getHeight() {return size.getClampedY(); };
//--------------------------------------------------------------
void LayerTransform::setSize(float w, float h) {this->size.set(w, h, 0); onSetSize();}
//--------------------------------------------------------------
void LayerTransform::setWidth(float w) {this->size.x = w; onSetSize();}
//--------------------------------------------------------------
void LayerTransform::setHeight(float h) {this->size.y = h; onSetSize();}


//--------------------------------------------------------------
int LayerTransform::getX() { return position.getClampedX(); };
//--------------------------------------------------------------
int LayerTransform::getY() { return position.getClampedY(); };
//--------------------------------------------------------------
int LayerTransform::getZ() { return position.getClampedZ(); };
//--------------------------------------------------------------
ofPoint LayerTransform::getPosition() { return position.getClamped(); };
//--------------------------------------------------------------
void LayerTransform::setPosition(ofPoint const p) { position.set(p.x, p.y, p.z); onSetPosition();}
//--------------------------------------------------------------
void LayerTransform::setPositionX(float x) {position.x = x; onSetPosition();}
//--------------------------------------------------------------
void LayerTransform::setPositionY(float y) {position.y = y; onSetPosition();}
//--------------------------------------------------------------
void LayerTransform::setPositionZ(float z) {position.z = z; onSetPosition();}

//--------------------------------------------------------------
ofPoint LayerTransform::getAnchorPoint() { return anchorPoint.getClamped(); };
//--------------------------------------------------------------
void LayerTransform::setAnchorPoint(ofPoint const p) {anchorPoint.set(p.x, p.y, p.z); onSetAnchorPoint();}
//--------------------------------------------------------------
void LayerTransform::setAnchorPointX(float x) {anchorPoint.x = x; onSetAnchorPoint();}
//--------------------------------------------------------------
void LayerTransform::setAnchorPointY(float y) {anchorPoint.y = y; onSetAnchorPoint();}
//--------------------------------------------------------------
void LayerTransform::setAnchorPointZ(float z) {anchorPoint.z = z; onSetAnchorPoint();}

//--------------------------------------------------------------
ofPoint LayerTransform::getRotation()	 { return rotation.getClamped(); };
//--------------------------------------------------------------
void LayerTransform::setRotation(ofPoint const p) {rotation.set(p.x, p.y, p.z);onSetRotation();}
//--------------------------------------------------------------
void LayerTransform::setRotationX(float x) {rotation.x = x; onSetRotation();}
//--------------------------------------------------------------
void LayerTransform::setRotationY(float y) {rotation.y = y; onSetRotation();}
//--------------------------------------------------------------
void LayerTransform::setRotationZ(float z) {rotation.z = z; onSetRotation();}

//--------------------------------------------------------------
ofPoint LayerTransform::getOrientation()	 { return orientation.getClamped(); };
//--------------------------------------------------------------
void LayerTransform::setOrientation(ofPoint const p) {orientation.set(p.x, p.y, p.z);onSetOrientation();}
//--------------------------------------------------------------
void LayerTransform::setOrientationX(float x) {orientation.x = x; onSetOrientation();}
//--------------------------------------------------------------
void LayerTransform::setOrientationY(float y) {orientation.y = y; onSetOrientation();}
//--------------------------------------------------------------
void LayerTransform::setOrientationZ(float z) {orientation.z = z; onSetOrientation();}

//--------------------------------------------------------------
ofPoint LayerTransform::getScale()	 { return scale.getClamped(); };
//--------------------------------------------------------------
void LayerTransform::setScale(ofPoint const p) {scale.set(p.x, p.y, p.z);onSetScale();}
//--------------------------------------------------------------
void LayerTransform::setScaleX(float x) {scale.x = x; onSetScale();}
//--------------------------------------------------------------
void LayerTransform::setScaleY(float y) {scale.y = y; onSetScale();}
//--------------------------------------------------------------
void LayerTransform::setScaleZ(float z) {scale.z = z; onSetScale();}

//--------------------------------------------------------------
int LayerTransform::getOpacity()	{ return opacity;}
//--------------------------------------------------------------
void LayerTransform::setOpacity(int o) { opacity = o; onSetOpacity();};

//--------------------------------------------------------------
void LayerTransform::onSetSize() {
    
}

//--------------------------------------------------------------
void LayerTransform::onSetPosition() {
    //cout << "OSP. x/y/z=" << getPosition().x << "/" << getPosition().y << "/" << getPosition().z << endl;
    //ofNotifyEvent(newPositionEvent,&position,this);
}

//--------------------------------------------------------------
void LayerTransform::onSetAnchorPoint() {
    //ofNotifyEvent(newAnchorPointEvent,&anchorPoint,this);
}

//--------------------------------------------------------------
void LayerTransform::onSetRotation() {
    //ofNotifyEvent(newRotationEvent, &rotation, this);
}

//--------------------------------------------------------------
void LayerTransform::onSetOrientation() {
    //ofNotifyEvent(newRotationEvent, &rotation, this);
}

//--------------------------------------------------------------
void LayerTransform::onSetScale() {
    //ofNotifyEvent(newRotationEvent, &rotation, this);
}

//--------------------------------------------------------------
void LayerTransform::onSetOpacity() {
    //ofNotifyEvent(newOpacityEvent, &opacity, this);
}

//--------------------------------------------------------------
void LayerTransform::onSetPositionLimit() {
    //ofNotifyEvent(newOpacityEvent, &position, this);
}

//--------------------------------------------------------------
void LayerTransform::onSetAnchorPointLimit() {
    //ofNotifyEvent(newOpacityEvent, &anchorPoint, this);
}

//--------------------------------------------------------------
void LayerTransform::onSetRotationLimit() {
    //ofNotifyEvent(newOpacityEvent, &rotation, this);
}

//--------------------------------------------------------------
void LayerTransform::onEnabled() {
    ofLog(OF_LOG_NOTICE, "Transform enabled");
}

//--------------------------------------------------------------
void LayerTransform::onDisabled() {
    ofLog(OF_LOG_NOTICE, "Transform diabled");
}
