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
#include "ofxOscRouterNode.h"



class CanvasLayerTransform : public ofxOscRouterNode, public Enabler {
	
public:
	
    
    CanvasLayerTransform(ofPoint _position, 
                         ofPoint _anchorPoint, 
                         ofPoint _rotation, 
                         ofPoint _scale, 
                         int _opacity);
    CanvasLayerTransform(ofPoint _position, 
                         ofPoint _anchorPoint, 
                         ofPoint _rotation, 
                         ofPoint _scale);
    CanvasLayerTransform(ofPoint _position, 
                         ofPoint _anchorPoint, 
                         ofPoint _rotation);

    CanvasLayerTransform(ofPoint _position, 
                         ofPoint _anchorPoint);

    CanvasLayerTransform(ofPoint _position);

    CanvasLayerTransform();

    
    virtual ~CanvasLayerTransform();
    
    void init();
    
    void processOscMessage(string address, ofxOscMessage& m);
    
    int getWidth();
    int getHeight();
	void setWidth(float w);
	void setHeight(float h);
    void setSize(float w, float h);
    
    int getX();
    int getY();
    int getZ();
	ofPoint getPosition();
	void setPosition(ofPoint const p);
	void setPositionX(float x);
	void setPositionY(float y);
	void setPositionZ(float z);
	
	ofPoint getAnchorPoint();
	void setAnchorPoint(ofPoint const p);
	void setAnchorPointX(float x);
	void setAnchorPointY(float y);
	void setAnchorPointZ(float z);
	
	ofPoint getRotation();
	void setRotation(ofPoint const p);
	void setRotationX(float x);
	void setRotationY(float y);
	void setRotationZ(float z);
	
	ofPoint getOrientation();
	void setOrientation(ofPoint const p);
	void setOrientationX(float x);
	void setOrientationY(float y);
	void setOrientationZ(float z);
	
	ofPoint getScale();
	void setScale(ofPoint p);
	void setScaleX(float x);
	void setScaleY(float y);
	void setScaleZ(float z);
	
    int  getOpacity();
	void setOpacity(int o);
    
    void onSetSize();
	void onSetPosition();
	void onSetAnchorPoint();
	void onSetRotation();
	void onSetOrientation();
	void onSetScale();
	void onSetOpacity();
	void onSetPositionLimit();
	void onSetAnchorPointLimit();
	void onSetRotationLimit();
	void onEnabled();
	void onDisabled();
	
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
