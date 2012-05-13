

#pragma once

#include "BaseMediaAsset.h"

//--------------------------------------------------------------
class GrabberMediaAsset : public BaseMediaAsset {
	
public:
	
	GrabberMediaAsset(string assetURI) : BaseMediaAsset(MEDIA_ASSET_GRABBER, assetURI) {
		createCache();
        
        // this should come from the media asset XML definition
        // or it can be adjusted via GUI
        deviceWidth 		= 320;	// try to grab at this size. 
        deviceHeight 		= 240;
        deviceId            = -1;
        
        vidGrabberInited = false;
        
        vidGrabber.listDevices(); // compare it to this list
        
	}
	~GrabberMediaAsset() {}
	
	void createCache();	
    void close() {};
    
    ofVideoGrabber* getVideoGrabber() {
        
        // we only init if we have been asked for it
        if(!vidGrabberInited) {
            vidGrabber.setVerbose(true);
            if(deviceId != -1) // only set it if we have set it.
                vidGrabber.setDeviceID(deviceId);
            vidGrabber.initGrabber(deviceWidth,deviceHeight);
            vidGrabberInited = true;
        }
        
        return &vidGrabber; // return a pointer to the ini
    
    }
    
    
    
protected: 
    
    int deviceWidth, deviceHeight;
    int deviceId;
    bool vidGrabberInited;
    ofVideoGrabber vidGrabber; // not automatically initiated

    // where is it being used
    //vector<ofVideoGrabber 
    
};

