//
//  SyphonAsset.h
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 7/6/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#pragma once

#include "BaseMediaAsset.h"
#include "FrameSourceAsset.h"

#include "ofxSyphonVideoClient.h"

class SyphonAsset : public virtual BaseMediaAsset,
                    public virtual FrameSourceAsset 
{
public:
    SyphonAsset(const string& _name) {
        assetType = MEDIA_ASSET_SYPHON;
        name = _name;
        
        syphonClient = ofPtr<ofxSyphonVideoClient>(new ofxSyphonVideoClient());
        syphonClient->setup();
        syphonClient->setApplicationName("ofxLivedrawEngine Asset");
        syphonClient->setServerName("");

    }
    virtual ~SyphonAsset() {}

    void processOscMessage(const string& pattern, const ofxOscMessage& m) {
        
    }
    
    virtual bool dispose() {
        detachFromAllSinks();
        
        cout << "disposing of syphon " << getName() << endl;
    }
    
    bool isFrameNew() {
        return syphonClient->isFrameNew();
    }
    
    ofPixelsRef getPixelsRef() {
        return syphonClient->getPixelsRef();
    }
    
    void open() {
        syphonClient->open();
    }
    
    void close() {
        syphonClient->close();
    }
    
    bool isLoaded() {
        return syphonClient->isConnected();
    }

    
    
protected:
    
    ofPtr<ofxSyphonVideoClient> syphonClient;

};
