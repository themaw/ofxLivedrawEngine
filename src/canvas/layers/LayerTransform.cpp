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
LayerTransform::LayerTransform() : 
ofxEnablerInterface(true), 
ofxOscRouterNode("transform") {
    
    addOscNodeAlias("t");
    addOscNodeAlias("xform");
    
    addOscMethod("position");
    addOscMethod("p");

    addOscMethod("anchorpoint");
    addOscMethod("a");

    addOscMethod("rotate");
    addOscMethod("r");

    addOscMethod("scale");
    addOscMethod("s");

    addOscMethod("opacity");
    addOscMethod("o");

    addOscMethod("size");
    addOscMethod("sz");
    
    addOscMethod("width");
    addOscMethod("w");
    
    addOscMethod("height");
    addOscMethod("h");
    
    
    
    size = ofPoint(640,480);
    
    position = ofxClampedPoint(ofPoint(0.0f,0.0f,0.0f));
    bIsPositionNormalized = false;

    anchorPoint = ofxClampedPoint(ofPoint(0.5f,0.5f,0.5f));
    bIsAnchorPointNormalized = true;

    rotation = ofxClampedPoint(ofPoint(0.0f,0.0f,0.0f));
    bIsRotationNormalized = false;

    scale = ofxClampedPoint(ofPoint(1.0f, 1.0f, 1.0f));

    orientation = ofxClampedPoint(ofPoint(1.0f, 1.0f, 1.0f));
    
    opacity = 255;
    bIsOpacityNormalized = false;

}


//--------------------------------------------------------------
LayerTransform::~LayerTransform() {};

//--------------------------------------------------------------
void LayerTransform::processOscCommand(const string& command, const ofxOscMessage& m) {
    
    if(isMatch(command,"position") || isMatch(command,"p")) {
        if(validateOscSignature("([if][if]?[if]?)|([s][if])", m)) {
            if(m.getArgType(0) == OFXOSC_TYPE_STRING) {
                char c = tolower(getArgAsStringUnchecked(m,0)[0]);
                
                if(c == 'x') {
                    setPositionX(getArgAsFloatUnchecked(m,1));
                } else if(c == 'y') {
                    setPositionY(getArgAsFloatUnchecked(m,1));
                } else if(c == 'z') {
                    setPositionZ(getArgAsFloatUnchecked(m,1));
                } else if(c == 'n') {
                    setPositionNormalized(getArgAsBoolean(m,1));
                } else {
                    ofLog(OF_LOG_ERROR, "LayerTransform: invalid arg type: " + ofToString(c) + " " + command);
                }
                
            } else {
                setPositionX(getArgAsFloatUnchecked(m,0));
                if(m.getNumArgs() > 1) {
                    setPositionY(getArgAsFloatUnchecked(m,1));
                    if(m.getNumArgs() > 2) {
                        setPositionZ(getArgAsFloatUnchecked(m,2));
                    }
                }
            }
        }
        
    } else if(isMatch(command,"anchorpoint") || isMatch(command,"a")) {

        if(validateOscSignature("([if][if]?[if]?)|([s][if])", m)) {
            if(m.getArgType(0) == OFXOSC_TYPE_STRING) {
                
                char c = tolower(getArgAsStringUnchecked(m,0)[0]);
                
                if(c == 'x') {
                    setAnchorPointX(getArgAsFloatUnchecked(m,1));
                } else if(c == 'y') {
                    setAnchorPointY(getArgAsFloatUnchecked(m,1));
                } else if(c == 'z') {
                    setAnchorPointZ(getArgAsFloatUnchecked(m,1));
                } else if(c == 'n') {
                    setAnchorPointNormalized(getArgAsBoolean(m,1));
                } else {
                    ofLog(OF_LOG_ERROR, "LayerTransform: invalid arg type: " + ofToString(c) + " " + command);
                }
                
                
            } else {
                setAnchorPointX(getArgAsFloatUnchecked(m,0));
                if(m.getNumArgs() > 1) {
                    setAnchorPointY(getArgAsFloatUnchecked(m,1));
                    if(m.getNumArgs() > 2) {
                        setAnchorPointZ(getArgAsFloatUnchecked(m,2));
                    }
                }
            }
        }
        
    } else if(isMatch(command,"rotate") || isMatch(command,"r")) {
        if(validateOscSignature("([if][if]?[if]?)|([s][if][if]?[if]?)", m)) {
            
            if(m.getArgType(0) == OFXOSC_TYPE_STRING) {
                
                char c = tolower(getArgAsStringUnchecked(m,0)[0]);

                if(c == 'x') {
                    setRotationX(getArgAsFloatUnchecked(m,1));
                } else if(c == 'y') {
                    setRotationY(getArgAsFloatUnchecked(m,1));
                } else if(c == 'z') {
                    setRotationZ(getArgAsFloatUnchecked(m,1));
                } else if(c == 'd') {
                    setRotation(getArgsAsPoint(m, 1));
                } else if(c == 'n') {
                    setRotationNormalized(getArgAsBoolean(m,1));
                } else {
                    ofLog(OF_LOG_ERROR, "LayerTransform: invalid arg type: " + ofToString(c) + " " + command);
                }
                
                
            } else {
                setRotationX(getArgAsFloatUnchecked(m,0));
                if(m.getNumArgs() > 1) {
                    setRotationY(getArgAsFloatUnchecked(m,1));
                    if(m.getNumArgs() > 2) {
                        setRotationZ(getArgAsFloatUnchecked(m,2));
                    }
                }
            }
            
            
            
        }
    } else if(isMatch(command,"scale") || isMatch(command,"s")) {
        if(validateOscSignature("([f][f]?[f]?)|([s][f])", m)) {
            if(m.getArgType(0) == OFXOSC_TYPE_STRING) {
                
                char  c = tolower(getArgAsStringUnchecked(m,0)[0]);
                float val = getArgAsFloatUnchecked(m,1);
                
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
                setScaleX(getArgAsFloatUnchecked(m,0));
                if(m.getNumArgs() > 1) {
                    setScaleY(getArgAsFloatUnchecked(m,1));
                    if(m.getNumArgs() > 2) {
                        setScaleZ(getArgAsFloatUnchecked(m,2));
                    }
                }
            }
        }
        
    } else if(isMatch(command,"opacity") || isMatch(command,"o")) {
        if(validateOscSignature("[if]|[s][if]", m)) {
            if(m.getArgType(0) == OFXOSC_TYPE_STRING) {
                char  c = tolower(getArgAsStringUnchecked(m,0)[0]);
                if(c == 'n') {
                    setOpacityNormalized(getArgAsBoolean(m,1));
                }
            } else {
                setOpacity(getArgAsFloatUnchecked(m,0));
            }
        }
    } else if(isMatch(command,"size") || isMatch(command, "sz")) {
        if(validateOscSignature("[if][if]", m)) {
            setSize(getArgAsFloatUnchecked(m,0),getArgAsFloatUnchecked(m,1));
        }
    } else if(isMatch(command,"width") || isMatch(command, "w")) {
        if(validateOscSignature("[if]", m)) {
            setWidth(getArgAsFloatUnchecked(m,0));
        }
    } else if(isMatch(command,"height") || isMatch(command, "h")) {
        if(validateOscSignature("[if]", m)) {
            setHeight(getArgAsFloatUnchecked(m,0));
        }
    }
    
}



//--------------------------------------------------------------
int LayerTransform::getWidth() const {return size.getClampedX(); };
//--------------------------------------------------------------
int LayerTransform::getHeight() const {return size.getClampedY(); };
//--------------------------------------------------------------
ofPoint LayerTransform::getSize() const {return size.getClamped(); };
//--------------------------------------------------------------
void LayerTransform::setSize(float w, float h) {this->size.set(w, h, 0); onSetSize();}
//--------------------------------------------------------------
void LayerTransform::setWidth(float w) {this->size.x = w; onSetSize();}
//--------------------------------------------------------------
void LayerTransform::setHeight(float h) {this->size.y = h; onSetSize();}


//--------------------------------------------------------------
int LayerTransform::getX() const { return position.getClampedX(); };
//--------------------------------------------------------------
int LayerTransform::getY() const { return position.getClampedY(); };
//--------------------------------------------------------------
int LayerTransform::getZ() const { return position.getClampedZ(); };
//--------------------------------------------------------------
ofPoint LayerTransform::getPosition() const { return position.getClamped(); };
//--------------------------------------------------------------
void LayerTransform::setPosition(const ofPoint& p) { position.set(p.x, p.y, p.z); onSetPosition();}
//--------------------------------------------------------------
void LayerTransform::setPositionX(float x) {position.x = x; onSetPosition();}
//--------------------------------------------------------------
void LayerTransform::setPositionY(float y) {position.y = y; onSetPosition();}
//--------------------------------------------------------------
void LayerTransform::setPositionZ(float z) {position.z = z; onSetPosition();}

//--------------------------------------------------------------
bool LayerTransform::isPositionNormalized() const { return bIsPositionNormalized; }
//--------------------------------------------------------------
void LayerTransform::setPositionNormalized(bool norm) { bIsPositionNormalized = norm;}


//--------------------------------------------------------------
ofPoint LayerTransform::getAnchorPoint() const { return anchorPoint.getClamped(); };
//--------------------------------------------------------------
void LayerTransform::setAnchorPoint(const ofPoint& p) {anchorPoint.set(p.x, p.y, p.z); onSetAnchorPoint();}
//--------------------------------------------------------------
void LayerTransform::setAnchorPointX(float x) {anchorPoint.x = x; onSetAnchorPoint();}
//--------------------------------------------------------------
void LayerTransform::setAnchorPointY(float y) {anchorPoint.y = y; onSetAnchorPoint();}
//--------------------------------------------------------------
void LayerTransform::setAnchorPointZ(float z) {anchorPoint.z = z; onSetAnchorPoint();}

//--------------------------------------------------------------
bool LayerTransform::isAnchorPointNormalized() const { return bIsAnchorPointNormalized; }
//--------------------------------------------------------------
void LayerTransform::setAnchorPointNormalized(bool norm) { bIsAnchorPointNormalized = norm;}

//--------------------------------------------------------------
ofPoint LayerTransform::getRotation() const { return rotation.getClamped(); };
//--------------------------------------------------------------
void LayerTransform::setRotation(const ofPoint& p) {rotation.set(p.x, p.y, p.z);onSetRotation();}
//--------------------------------------------------------------
void LayerTransform::setRotationX(float x) {rotation.x = x; onSetRotation();}
//--------------------------------------------------------------
void LayerTransform::setRotationY(float y) {rotation.y = y; onSetRotation();}
//--------------------------------------------------------------
void LayerTransform::setRotationZ(float z) {rotation.z = z; onSetRotation();}

//--------------------------------------------------------------
bool LayerTransform::isRotationNormalized() const { return bIsRotationNormalized; }
//--------------------------------------------------------------
void LayerTransform::setRotationNormalized(bool norm) { bIsRotationNormalized = norm;}

//--------------------------------------------------------------
ofPoint LayerTransform::getOrientation() const { return orientation.getClamped(); };
//--------------------------------------------------------------
void LayerTransform::setOrientation(const ofPoint& p) {orientation.set(p.x, p.y, p.z);onSetOrientation();}
//--------------------------------------------------------------
void LayerTransform::setOrientationX(float x) {orientation.x = x; onSetOrientation();}
//--------------------------------------------------------------
void LayerTransform::setOrientationY(float y) {orientation.y = y; onSetOrientation();}
//--------------------------------------------------------------
void LayerTransform::setOrientationZ(float z) {orientation.z = z; onSetOrientation();}

//--------------------------------------------------------------
ofPoint LayerTransform::getScale() const { return scale.getClamped(); };
//--------------------------------------------------------------
void LayerTransform::setScale(const ofPoint& p) {scale.set(p.x, p.y, p.z);onSetScale();}
//--------------------------------------------------------------
void LayerTransform::setScaleX(float x) {scale.x = x; onSetScale();}
//--------------------------------------------------------------
void LayerTransform::setScaleY(float y) {scale.y = y; onSetScale();}
//--------------------------------------------------------------
void LayerTransform::setScaleZ(float z) {scale.z = z; onSetScale();}

//--------------------------------------------------------------
int LayerTransform::getOpacity() const { return opacity;}
//--------------------------------------------------------------
void LayerTransform::setOpacity(int o) { opacity = o; onSetOpacity();};

//--------------------------------------------------------------
bool LayerTransform::isOpacityNormalized() const { return bIsOpacityNormalized; }
//--------------------------------------------------------------
void LayerTransform::setOpacityNormalized(bool norm) { bIsOpacityNormalized = norm;}

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
