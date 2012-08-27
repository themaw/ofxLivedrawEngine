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



class LayerTransform : public ofxOscRouterNode, public ofxEnablerInterface {
	
public:
	
    LayerTransform();
    
    virtual ~LayerTransform();
        
    void processOscCommand(const string& command, const ofxOscMessage& m);
    
    int getWidth() const;
    int getHeight() const;
    ofPoint getSize() const;
	void setWidth(float w);
	void setHeight(float h);
    void setSize(float w, float h);
    
    int getX() const;
    int getY() const;
    int getZ() const;
	ofPoint getPosition() const;
    void setPosition(const ofPoint& p);
	void setPositionX(float x);
	void setPositionY(float y);
	void setPositionZ(float z);
	bool isPositionNormalized() const;
    void setPositionNormalized(bool norm);
    
	ofPoint getAnchorPoint() const;
	void setAnchorPoint(const ofPoint& p);
	void setAnchorPointX(float x);
	void setAnchorPointY(float y);
	void setAnchorPointZ(float z);
    bool isAnchorPointNormalized() const;
    void setAnchorPointNormalized(bool norm);
    
	ofPoint getRotation() const;
	void setRotation(const ofPoint& p);
	void setRotationX(float x);
	void setRotationY(float y);
	void setRotationZ(float z);
    bool isRotationNormalized() const;
    void setRotationNormalized(bool norm);
	
//	ofPoint getOrientation() const;
//	void setOrientation(const ofPoint& p);
//	void setOrientationX(float x);
//	void setOrientationY(float y);
//	void setOrientationZ(float z);
	
	ofPoint getScale() const;
	void setScale(const ofPoint& p);
	void setScaleX(float x);
	void setScaleY(float y);
	void setScaleZ(float z);
	
    int  getOpacity() const;
	void setOpacity(int o);
    void setOpacityNormalized(float norm);

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
    bool bIsPositionNormalized;

	ofxClampedPoint anchorPoint;
    bool bIsAnchorPointNormalized;
    
	ofxClampedPoint rotation;
    bool bIsRotationNormalized;
	
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
