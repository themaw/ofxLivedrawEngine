/*
 *  VideoSource.h
 *  livedraw
 *
 *  Created by Christopher P. Baker on 1/1/11.
 *  Copyright 2011 Murmur Labs LLC. All rights reserved.
 *
 */

#pragma once

#include "ofVideoPlayer.h"
#include "BaseMediaSource.h"


class VideoSource : public ofVideoPlayer, public BaseMediaSource  {
	
public:
	VideoSource();
	~VideoSource();
	
};
