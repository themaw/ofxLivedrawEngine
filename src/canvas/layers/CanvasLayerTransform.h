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

#pragma once 

#include "ofMain.h"
#include "ofEvents.h"
#include "ofxEnablerInterface.h"
#include "ofxClampedPoint.h"
#include "ofxOscRouterNode.h"



class CanvasLayerTransform : public ofxOscRouterNode, public ofxEnablerInterface {
	
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
    
    void processOscMessage(const string& address, const ofxOscMessage& m);
    
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
	
	ofxClampedPoint position;
	ofxClampedPoint anchorPoint;
	ofxClampedPoint rotation;
	
	// A NOTE ON ORIENTATION 
	// http://help.adobe.com/en_US/aftereffects/cs/using/WS3878526689cb91655866c1103906c6dea-7e33a.html
	
	ofxClampedPoint orientation;
	ofxClampedPoint scale;

	// materials options ... ?
	
    ofxClampedPoint size;
    
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
