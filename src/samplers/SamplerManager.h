//
//  Header.h
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 5/13/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#pragma once

#include "ofMain.h"
#include <set>
#include "BaseMediaAsset.h"
#include "ofxVideoBuffer.h"

#include "ofMain.h"
#include "AssetManager.h"
#include "OscManager.h"
#include "Sampler.h"

class SamplerManager : public OscNodeListener {
public:
    
    SamplerManager();
    virtual ~SamplerManager();
    
    void update();
    void processOscMessage(string pattern, ofxOscMessage& m);
    
    Sampler* getNewSampler();
    
    //int getTotalFramesBuffered();
    //int getTotalBytesBuffered();
    
protected:
    AssetManager*   assetManager;
    
private:
    vector<Sampler> samplers;
    
};