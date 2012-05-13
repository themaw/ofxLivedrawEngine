/*
 *  GrabberSource.h
 *  livedraw
 *
 *  Created by Christopher P. Baker on 1/1/11.
 *  Copyright 2011 Murmur Labs LLC. All rights reserved.
 *
 */

#pragma once

#include "ofVideoGrabber.h"
#include "BaseMediaSource.h"

class GrabberSource : public ofVideoGrabber, public BaseMediaSource {
	
public:
	GrabberSource();
	~GrabberSource();
    
    

	
};
