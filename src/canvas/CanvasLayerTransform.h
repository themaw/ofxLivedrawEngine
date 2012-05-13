/*
 *  CanvasLayerTransform.h
 *  livedraw
 *
 *  Created by Christopher P. Baker on 1/1/11.
 *  Copyright 2011 Murmur Labs LLC. All rights reserved.
 *
 */

#pragma once 

#include "ofMain.h"
#include "ofEvents.h"
#include "EnablerInterface.h"
#include "ofxLimitedPoint.h"
#include "OscNodeListener.h"



class CanvasLayerTransform : public OscNodeListener, public Enabler {
	
public:
	
    
    CanvasLayerTransform(ofPoint _position, 
                         ofPoint _anchorPoint, 
                         ofPoint _rotation, 
                         ofPoint _scale, 
                         int _opacity) : 
                                            Enabler(true),  
                                            OscNodeListener("/transform") {
        
        position = ofxLimitedPoint(_position);
		anchorPoint = ofxLimitedPoint(_anchorPoint);
		rotation = ofxLimitedPoint(_rotation);
		scale = ofxLimitedPoint(_scale);
        opacity = _opacity;
        size = ofPoint(640,480);

        init();
    }

    CanvasLayerTransform(ofPoint _position, 
                         ofPoint _anchorPoint, 
                         ofPoint _rotation, 
                         ofPoint _scale) : 
    Enabler(true),  
    OscNodeListener("/transform") {
        
        position = ofxLimitedPoint(_position);
		anchorPoint = ofxLimitedPoint(_anchorPoint);
		rotation = ofxLimitedPoint(_rotation);
		scale = ofxLimitedPoint(_scale);
        opacity = 255;
        size = ofPoint(640,480);

        init();
    }

    CanvasLayerTransform(ofPoint _position, 
                         ofPoint _anchorPoint, 
                         ofPoint _rotation) : 
    Enabler(true),  
    OscNodeListener("/transform") {
        
        position = ofxLimitedPoint(_position);
		anchorPoint = ofxLimitedPoint(_anchorPoint);
		rotation = ofxLimitedPoint(_rotation);
		scale = ofxLimitedPoint(ofPoint(1.0f, 1.0f, 1.0f));
        opacity = 255;
        size = ofPoint(640,480);

        init();
    }

    CanvasLayerTransform(ofPoint _position, 
                         ofPoint _anchorPoint) : 
    Enabler(true),  
    OscNodeListener("/transform") {
        
        position = ofxLimitedPoint(_position);
		anchorPoint = ofxLimitedPoint(_anchorPoint);
		scale = ofxLimitedPoint(ofPoint(1.0f, 1.0f, 1.0f));
        opacity = 255;
        size = ofPoint(640,480);

        init();
    }

    CanvasLayerTransform(ofPoint _position) : 
    Enabler(true),  
    OscNodeListener("/transform") {
        
        position = ofxLimitedPoint(_position);
		scale = ofxLimitedPoint(ofPoint(1.0f, 1.0f, 1.0f));
        opacity = 255;
        size = ofPoint(640,480);

        init();
    }

    CanvasLayerTransform() : Enabler(true), OscNodeListener("/transform") {
        
		scale = ofxLimitedPoint(ofPoint(1.0f, 1.0f, 1.0f));
        opacity = 255;
        size = ofPoint(640,480);

        init();
    }

    
    
    void init() {
        addOscCommand("/position");
        addOscCommand("/anchorpoint");
        addOscCommand("/rotate");
        addOscCommand("/scale");
        addOscCommand("/opacity");
        addOscCommand("/size");
        
    }
    
	virtual ~CanvasLayerTransform() {};

    void processOscMessage(string address, ofxOscMessage& m) {
        
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
                setSize(ofPoint(w,h));
            }
        }

    }


    
    int getWidth() {return size.getLimitedPoint().x; };
    int getHeight() {return size.getLimitedPoint().y; };
    ofPoint getSize() { return size.getLimitedPoint(); };
	void setSize(ofPoint p) {this->position.set(p.x, p.y, 0);onSetSize();}
	void setWidth(float w) {this->position.x = w; onSetSize();}
	void setHeight(float h) {this->position.y = h; onSetSize();}
    
    
    int getX() { return position.getLimitedPoint().x; };
    int getY() { return position.getLimitedPoint().y; };
    int getZ() { return position.getLimitedPoint().z; };
	ofPoint getPosition() { return position.getLimitedPoint(); };
	void setPosition(ofPoint p) {
        position.set(p.x, p.y, p.z);
        onSetPosition();
    }
	void setPositionX(float x) {position.x = x; onSetPosition();}
	void setPositionY(float y) {position.y = y; onSetPosition();}
	void setPositionZ(float z) {position.z = z; onSetPosition();}
	
	ofPoint getAnchorPoint() { return anchorPoint.getLimitedPoint(); };
	void setAnchorPoint(ofPoint p) {anchorPoint.set(p.x, p.y, p.z); onSetAnchorPoint();}
	void setAnchorPointX(float x) {anchorPoint.x = x; onSetAnchorPoint();}
	void setAnchorPointY(float y) {anchorPoint.y = y; onSetAnchorPoint();}
	void setAnchorPointZ(float z) {anchorPoint.z = z; onSetAnchorPoint();}
	
	ofPoint getRotation()	 { return rotation.getLimitedPoint(); };
	void setRotation(ofPoint p) {rotation.set(p.x, p.y, p.z);onSetRotation();}
	void setRotationX(float x) {rotation.x = x; onSetRotation();}
	void setRotationY(float y) {rotation.y = y; onSetRotation();}
	void setRotationZ(float z) {rotation.z = z; onSetRotation();}
	
	ofPoint getOrientation()	 { return orientation.getLimitedPoint(); };
	void setOrientation(ofPoint p) {orientation.set(p.x, p.y, p.z);onSetOrientation();}
	void setOrientationX(float x) {orientation.x = x; onSetOrientation();}
	void setOrientationY(float y) {orientation.y = y; onSetOrientation();}
	void setOrientationZ(float z) {orientation.z = z; onSetOrientation();}
	
	ofPoint getScale()	 { return scale.getLimitedPoint(); };
	void setScale(ofPoint p) {scale.set(p.x, p.y, p.z);onSetScale();}
	void setScaleX(float x) {scale.x = x; onSetScale();}
	void setScaleY(float y) {scale.y = y; onSetScale();}
	void setScaleZ(float z) {scale.z = z; onSetScale();}
	
	int getOpacity()	{ return opacity;}
	void setOpacity(int o) { opacity = o; onSetOpacity();};
	
    void onSetSize() {
        
    }
    
	void onSetPosition() {
        //cout << "OSP. x/y/z=" << getPosition().x << "/" << getPosition().y << "/" << getPosition().z << endl;
		//ofNotifyEvent(newPositionEvent,&position,this);
	}

	void onSetAnchorPoint() {
		//ofNotifyEvent(newAnchorPointEvent,&anchorPoint,this);
	}

	void onSetRotation() {
		//ofNotifyEvent(newRotationEvent, &rotation, this);
	}
	
	void onSetOrientation() {
		//ofNotifyEvent(newRotationEvent, &rotation, this);
	}
	
	
	void onSetScale() {
		//ofNotifyEvent(newRotationEvent, &rotation, this);
	}

	void onSetOpacity() {
		//ofNotifyEvent(newOpacityEvent, &opacity, this);
	}
	
	void onSetPositionLimit() {
		//ofNotifyEvent(newOpacityEvent, &position, this);
	}
	
	void onSetAnchorPointLimit() {
		//ofNotifyEvent(newOpacityEvent, &anchorPoint, this);
	}

	void onSetRotationLimit() {
		//ofNotifyEvent(newOpacityEvent, &rotation, this);
	}
	
	void onEnabled() {
		ofLog(OF_LOG_NOTICE, "Transform enabled");
	}
	
	void onDisabled() {
		ofLog(OF_LOG_NOTICE, "Transform diabled");
	}
	
//protected:
	
	ofxLimitedPoint position;
	ofxLimitedPoint anchorPoint;
	ofxLimitedPoint rotation;
	
	// A NOTE ON ORIENTATION 
	// http://help.adobe.com/en_US/aftereffects/cs/using/WS3878526689cb91655866c1103906c6dea-7e33a.html
	
	ofxLimitedPoint orientation;
	ofxLimitedPoint scale;

	// materials options ... ?
	
    ofxLimitedPoint size;
    
	float opacity; // 0-255
	
	/*
	ofEvent<ofxLimitedPoint*> newPositionEvent;
	ofEvent<ofxLimitedPoint*> newAnchorPointEvent;
	ofEvent<ofxLimitedPoint*> newRotationEvent;
	ofEvent<float>	newOpacityEvent;
	
	ofEvent<ofxLimitedPoint*> newPositionLimitEvent;
	ofEvent<ofxLimitedPoint*> newAnchorPointLimitEvent;
	ofEvent<ofxLimitedPoint*> newRotationLimitEvent;
	*/
    
};
