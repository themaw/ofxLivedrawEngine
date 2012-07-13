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

#include "CanvasLayerTransform.h"

//--------------------------------------------------------------
CanvasLayerTransform::CanvasLayerTransform(ofPoint _position, 
                     ofPoint _anchorPoint, 
                     ofPoint _rotation, 
                     ofPoint _scale, 
                     int _opacity) : 
ofxEnablerInterface(true),  
ofxOscRouterNode("/transform") {
    
    position = ofxClampedPoint(_position);
    anchorPoint = ofxClampedPoint(_anchorPoint);
    rotation = ofxClampedPoint(_rotation);
    scale = ofxClampedPoint(_scale);
    opacity = _opacity;
    size = ofPoint(640,480);
    
    init();
}

//--------------------------------------------------------------
CanvasLayerTransform::CanvasLayerTransform(ofPoint _position, 
                     ofPoint _anchorPoint, 
                     ofPoint _rotation, 
                     ofPoint _scale) : 
ofxEnablerInterface(true),  
ofxOscRouterNode("/transform") {
    
    position = ofxClampedPoint(_position);
    anchorPoint = ofxClampedPoint(_anchorPoint);
    rotation = ofxClampedPoint(_rotation);
    scale = ofxClampedPoint(_scale);
    opacity = 255;
    size = ofPoint(640,480);
    
    init();
}

//--------------------------------------------------------------
CanvasLayerTransform::CanvasLayerTransform(ofPoint _position, 
                     ofPoint _anchorPoint, 
                     ofPoint _rotation) : 
ofxEnablerInterface(true),  
ofxOscRouterNode("/transform") {
    
    position = ofxClampedPoint(_position);
    anchorPoint = ofxClampedPoint(_anchorPoint);
    rotation = ofxClampedPoint(_rotation);
    scale = ofxClampedPoint(ofPoint(1.0f, 1.0f, 1.0f));
    opacity = 255;
    size = ofPoint(640,480);
    
    init();
}

//--------------------------------------------------------------
CanvasLayerTransform::CanvasLayerTransform(ofPoint _position, 
                     ofPoint _anchorPoint) : 
ofxEnablerInterface(true),  
ofxOscRouterNode("/transform") {
    
    position = ofxClampedPoint(_position);
    anchorPoint = ofxClampedPoint(_anchorPoint);
    scale = ofxClampedPoint(ofPoint(1.0f, 1.0f, 1.0f));
    opacity = 255;
    size = ofPoint(640,480);
    
    init();
}

//--------------------------------------------------------------
CanvasLayerTransform::CanvasLayerTransform(ofPoint _position) : 
ofxEnablerInterface(true),  
ofxOscRouterNode("/transform") {
    
    position = ofxClampedPoint(_position);
    scale = ofxClampedPoint(ofPoint(1.0f, 1.0f, 1.0f));
    opacity = 255;
    size = ofPoint(640,480);
    
    init();
}

//--------------------------------------------------------------
CanvasLayerTransform::CanvasLayerTransform() : 
ofxEnablerInterface(true), 
ofxOscRouterNode("/transform") {
    
    scale = ofxClampedPoint(ofPoint(1.0f, 1.0f, 1.0f));
    opacity = 255;
    size = ofPoint(640,480);
    
    init();
}



//--------------------------------------------------------------
void CanvasLayerTransform::init() {
    addOscMethod("/position");
    addOscMethod("/anchorpoint");
    addOscMethod("/rotate");
    addOscMethod("/scale");
    addOscMethod("/opacity");
    addOscMethod("/size");
    
}

//--------------------------------------------------------------
CanvasLayerTransform::~CanvasLayerTransform() {};

//--------------------------------------------------------------
void CanvasLayerTransform::processOscMessage(const string& address, const ofxOscMessage& m) {
    
    if(isMatch(address,"/position")) {
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
                    ofLog(OF_LOG_ERROR, "CanvasLayerTransform: invalid arg type: " + ofToString(c) + " " + address);
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
        
    } else if(isMatch(address,"/anchorpoint")) {
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
                    ofLog(OF_LOG_ERROR, "CanvasLayerTransform: invalid arg type: " + ofToString(c) + " " + address);
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
        
    } else if(isMatch(address,"/rotate")) {
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
                    ofLog(OF_LOG_ERROR, "CanvasLayerTransform: invalid arg type: " + ofToString(c) + " " + address);
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
    } else if(isMatch(address,"/scale")) {            
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
                    ofLog(OF_LOG_ERROR, "CanvasLayerTransform: invalid arg type: " + ofToString(c) + " " + address);
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
        
    } else if(isMatch(address,"/opacity")) {
        if(validateOscSignature("[if]", m)) {
            float  val = m.getArgAsFloat(0);
            setOpacity(val);
        }
    } else if(isMatch(address,"/size")) {
        if(validateOscSignature("[if][if]", m)) {
            int w = m.getArgAsFloat(0);
            int h = m.getArgAsFloat(1);
            setSize(w,h);
        }
    }
    
}



//--------------------------------------------------------------
int CanvasLayerTransform::getWidth() {return size.getClampedX(); };
//--------------------------------------------------------------
int CanvasLayerTransform::getHeight() {return size.getClampedY(); };
//--------------------------------------------------------------
void CanvasLayerTransform::setSize(float w, float h) {this->size.set(w, h, 0); onSetSize();}
//--------------------------------------------------------------
void CanvasLayerTransform::setWidth(float w) {this->size.x = w; onSetSize();}
//--------------------------------------------------------------
void CanvasLayerTransform::setHeight(float h) {this->size.y = h; onSetSize();}


//--------------------------------------------------------------
int CanvasLayerTransform::getX() { return position.getClampedX(); };
//--------------------------------------------------------------
int CanvasLayerTransform::getY() { return position.getClampedY(); };
//--------------------------------------------------------------
int CanvasLayerTransform::getZ() { return position.getClampedZ(); };
//--------------------------------------------------------------
ofPoint CanvasLayerTransform::getPosition() { return position.getClamped(); };
//--------------------------------------------------------------
void CanvasLayerTransform::setPosition(ofPoint const p) { position.set(p.x, p.y, p.z); onSetPosition();}
//--------------------------------------------------------------
void CanvasLayerTransform::setPositionX(float x) {position.x = x; onSetPosition();}
//--------------------------------------------------------------
void CanvasLayerTransform::setPositionY(float y) {position.y = y; onSetPosition();}
//--------------------------------------------------------------
void CanvasLayerTransform::setPositionZ(float z) {position.z = z; onSetPosition();}

//--------------------------------------------------------------
ofPoint CanvasLayerTransform::getAnchorPoint() { return anchorPoint.getClamped(); };
//--------------------------------------------------------------
void CanvasLayerTransform::setAnchorPoint(ofPoint const p) {anchorPoint.set(p.x, p.y, p.z); onSetAnchorPoint();}
//--------------------------------------------------------------
void CanvasLayerTransform::setAnchorPointX(float x) {anchorPoint.x = x; onSetAnchorPoint();}
//--------------------------------------------------------------
void CanvasLayerTransform::setAnchorPointY(float y) {anchorPoint.y = y; onSetAnchorPoint();}
//--------------------------------------------------------------
void CanvasLayerTransform::setAnchorPointZ(float z) {anchorPoint.z = z; onSetAnchorPoint();}

//--------------------------------------------------------------
ofPoint CanvasLayerTransform::getRotation()	 { return rotation.getClamped(); };
//--------------------------------------------------------------
void CanvasLayerTransform::setRotation(ofPoint const p) {rotation.set(p.x, p.y, p.z);onSetRotation();}
//--------------------------------------------------------------
void CanvasLayerTransform::setRotationX(float x) {rotation.x = x; onSetRotation();}
//--------------------------------------------------------------
void CanvasLayerTransform::setRotationY(float y) {rotation.y = y; onSetRotation();}
//--------------------------------------------------------------
void CanvasLayerTransform::setRotationZ(float z) {rotation.z = z; onSetRotation();}

//--------------------------------------------------------------
ofPoint CanvasLayerTransform::getOrientation()	 { return orientation.getClamped(); };
//--------------------------------------------------------------
void CanvasLayerTransform::setOrientation(ofPoint const p) {orientation.set(p.x, p.y, p.z);onSetOrientation();}
//--------------------------------------------------------------
void CanvasLayerTransform::setOrientationX(float x) {orientation.x = x; onSetOrientation();}
//--------------------------------------------------------------
void CanvasLayerTransform::setOrientationY(float y) {orientation.y = y; onSetOrientation();}
//--------------------------------------------------------------
void CanvasLayerTransform::setOrientationZ(float z) {orientation.z = z; onSetOrientation();}

//--------------------------------------------------------------
ofPoint CanvasLayerTransform::getScale()	 { return scale.getClamped(); };
//--------------------------------------------------------------
void CanvasLayerTransform::setScale(ofPoint const p) {scale.set(p.x, p.y, p.z);onSetScale();}
//--------------------------------------------------------------
void CanvasLayerTransform::setScaleX(float x) {scale.x = x; onSetScale();}
//--------------------------------------------------------------
void CanvasLayerTransform::setScaleY(float y) {scale.y = y; onSetScale();}
//--------------------------------------------------------------
void CanvasLayerTransform::setScaleZ(float z) {scale.z = z; onSetScale();}

//--------------------------------------------------------------
int CanvasLayerTransform::getOpacity()	{ return opacity;}
//--------------------------------------------------------------
void CanvasLayerTransform::setOpacity(int o) { opacity = o; onSetOpacity();};

//--------------------------------------------------------------
void CanvasLayerTransform::onSetSize() {
    
}

//--------------------------------------------------------------
void CanvasLayerTransform::onSetPosition() {
    //cout << "OSP. x/y/z=" << getPosition().x << "/" << getPosition().y << "/" << getPosition().z << endl;
    //ofNotifyEvent(newPositionEvent,&position,this);
}

//--------------------------------------------------------------
void CanvasLayerTransform::onSetAnchorPoint() {
    //ofNotifyEvent(newAnchorPointEvent,&anchorPoint,this);
}

//--------------------------------------------------------------
void CanvasLayerTransform::onSetRotation() {
    //ofNotifyEvent(newRotationEvent, &rotation, this);
}

//--------------------------------------------------------------
void CanvasLayerTransform::onSetOrientation() {
    //ofNotifyEvent(newRotationEvent, &rotation, this);
}

//--------------------------------------------------------------
void CanvasLayerTransform::onSetScale() {
    //ofNotifyEvent(newRotationEvent, &rotation, this);
}

//--------------------------------------------------------------
void CanvasLayerTransform::onSetOpacity() {
    //ofNotifyEvent(newOpacityEvent, &opacity, this);
}

//--------------------------------------------------------------
void CanvasLayerTransform::onSetPositionLimit() {
    //ofNotifyEvent(newOpacityEvent, &position, this);
}

//--------------------------------------------------------------
void CanvasLayerTransform::onSetAnchorPointLimit() {
    //ofNotifyEvent(newOpacityEvent, &anchorPoint, this);
}

//--------------------------------------------------------------
void CanvasLayerTransform::onSetRotationLimit() {
    //ofNotifyEvent(newOpacityEvent, &rotation, this);
}

//--------------------------------------------------------------
void CanvasLayerTransform::onEnabled() {
    ofLog(OF_LOG_NOTICE, "Transform enabled");
}

//--------------------------------------------------------------
void CanvasLayerTransform::onDisabled() {
    ofLog(OF_LOG_NOTICE, "Transform diabled");
}
