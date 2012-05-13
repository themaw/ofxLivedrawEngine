/*
 *  LimitablePoint.h
 *  livedraw
 *
 *  Created by Christopher P. Baker on 3/6/11.
 *  Copyright 2011 Murmur Labs LLC. All rights reserved.
 *
 */

#pragma once

#include "ofTypes.h"

class ofxLimitedPoint : public ofPoint {
	
	
public:
	
	ofxLimitedPoint( const ofPoint & pnt)
		: ofPoint(pnt) {

		minLimit.set(-FLT_MAX,-FLT_MAX,-FLT_MAX);
		maxLimit.set(FLT_MAX,FLT_MAX,FLT_MAX);

    }
	
	ofxLimitedPoint(float _x=0.0f, float _y=0.0f, float _z=0.0f)
		: ofPoint(_x,_y,_z) {

		minLimit.set(-FLT_MAX,-FLT_MAX,-FLT_MAX);
		maxLimit.set(FLT_MAX,FLT_MAX,FLT_MAX);
			
	};
	 
	~ofxLimitedPoint() {}
	
			
	ofPoint getLimitedPoint() {
		return ofPoint(getLimitedX(), getLimitedY(), getLimitedZ());
	};
	
	float getLimitedX() {return CLAMP(x,minLimit.x,maxLimit.x);}
	float getLimitedY() {return CLAMP(y,minLimit.y,maxLimit.y);}
	float getLimitedZ() {return CLAMP(z,minLimit.z,maxLimit.z);}

	void setMinLimits(ofPoint minLimit) {this->minLimit = minLimit; onLimitChange();};
	void setMaxLimits(ofPoint maxLimit) {this->maxLimit = maxLimit; onLimitChange();};

	void setMinX(float x) {minLimit.x = x; onLimitChange();};
	void setMaxX(float x) {maxLimit.x = x; onLimitChange();};

	void setMinY(float y) {minLimit.y = y; onLimitChange();};
	void setMaxY(float y) {maxLimit.y = y; onLimitChange();};

	void setMinZ(float z) {minLimit.z = z; onLimitChange();};
	void setMaxZ(float z) {maxLimit.z = z; onLimitChange();};

	void clearMaxLimits() { maxLimit.set(FLT_MAX,FLT_MAX,FLT_MAX); onLimitChange();}
	void clearMinLimits() { minLimit.set(-FLT_MAX,-FLT_MAX,-FLT_MAX); onLimitChange();}
	
	void onLimitChange() { /* nothing here now */}

	
//private:
	
	ofPoint minLimit;
	ofPoint maxLimit;
		
		
};


