/*
 *  Sampler.h
 *  livedraw
 *
 *  Created by Christopher P. Baker on 3/7/11.
 *  Copyright 2011 Murmur Labs LLC. All rights reserved.
 *
 */

#pragma once

#include "MediaAssetTypes.h"
#include "ofImage.h"
#include "RingBuffer.h"

#include "BaseMediaAsset.h"

// EASING MODES


class MediaSampler {
	
public:
	
	MediaSampler();
	virtual ~MediaSampler();
	
	//virtual void play() {};//= 0;
	//virtual void pause() {};//= 0;
	//virtual void stop() {};//= 0;
	//virtual void setLoopMode(int loopMode) {};//= 0;
	//virtual void setLoopPoints(int start, int end) {};//= 0;
	//virtual void setRate(float f) {};//= 0;
	//virtual void setEasing(int easingMode) {};//= 0;
	//  from ofBaseVideo
	//	virtual bool isFrameNew()=0;
	
	
	virtual void update() = 0;

	
	//virtual bool isFrameNew() {};//= 0;
	
	//float getSpeed();
	//float getDuration();
	//bool getIsMovieDone();
	
	//void setPosition(float pct);
	//void setVolume(int volume);
	//void setLoopState(int state);
	//void setSpeed(float speed);
	//void setFrame(int frame);  // frame 0 = first frame...
	
	//virtual int	getCurrentFrame();
	//virtual int getTotalNumFrames();
	
	//virtual void firstFrame();
	//virtual void nextFrame();
	//virtual void previousFrame();
	
	//bool isPaused();
	//bool isLoaded();
	//bool isPlaying();
	
private:
	
	int loopMode;
	float speed;

	
};


class BufferSampler : public MediaSampler {

	
};


class VideoSampler : public ofVideoPlayer, public MediaSampler {
	
	
	
};


