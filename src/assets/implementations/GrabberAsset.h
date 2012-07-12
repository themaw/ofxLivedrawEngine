//
//  GrabberAsset.h
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 7/6/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#pragma once

#include "BaseMediaAsset.h"
#include "FrameSourceAsset.h"

class GrabberAsset : public virtual BaseMediaAsset, 
                     public virtual FrameSourceAsset 
{
public:
    GrabberAsset(const string& _name, int _devId, int _width, int _height) {
        assetType = MEDIA_ASSET_GRABBER;
        name   = _name;
        width  = _width;
        height = _height;
        devId  = _devId;
        grabber = ofPtr<ofVideoGrabber>(new ofVideoGrabber());

        //        grabber->initGrabber(width, height);
    }
    virtual ~GrabberAsset() {}

    bool dispose() {
        detachFromAllSinks();
        close();
    }
    
    void processOscMessage(const string& pattern, const ofxOscMessage& m) {
        cout << "cout process osc message" << endl;
    }
    
    bool isFrameNew() {
        return grabber->isFrameNew();
    }
    
    ofPixelsRef getPixelsRef() {
        return grabber->getPixelsRef();
    }
    
    void open() {
        grabber->setDeviceID(devId);
        grabber->initGrabber(width, height);
    }
    
    void close() {
        grabber->close();
    }

    bool isLoaded() {
        return grabber->isInitialized();
    }


protected:
    int width;
    int height;
    int devId;
    
    ofPtr<ofVideoGrabber> grabber;
    
};
