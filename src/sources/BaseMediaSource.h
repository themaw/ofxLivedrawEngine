

#pragma once

//#include "ofVideoPlayer.h"
//#include "ofVideoGrabber.h"
//#include "ofxVideoStreamer.h"

#include "ofImage.h"
#include "MediaAssetTypes.h"
#include "BaseMediaAsset.h"
//#include "RingBuffer.h"

#include "Poco/URI.h"

// forward declaration
class BaseMediaAsset;


// a base media source provides an activeated
class BaseMediaSource {
	
public:
	
	BaseMediaSource() {//int bufferSize = DEFAULT_BUFFER_SIZE) {//: RingBuffer<ofImage*>(bufferSize, NULL) {
		// nothing to do here
	}
	
	virtual ~BaseMediaSource() {
		// nothing to do here
	}

	MediaAssetType getAssetType();
	
protected:


private:
	
	bool isBufferedSource;
	
	BaseMediaAsset* parentAsset;
	
};
 
 


