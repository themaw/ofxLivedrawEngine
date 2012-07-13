//
//  ImageAsset.h
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 7/6/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#pragma once

#include "BaseMediaAsset.h"
#include "DiskBasedAsset.h"
#include "FrameSourceAsset.h"

class ImageAsset : public virtual BaseMediaAsset,
                   public virtual DiskBasedAsset,
                   public virtual FrameSourceAsset 
{
public:
    ImageAsset(const string& _name, string _filename);
    virtual ~ImageAsset();
    void processOscMessage(const string& pattern, const ofxOscMessage& m);

    bool dispose();

    bool isFrameNew();
    ofPixelsRef getPixelsRef();
    
    void open();
    void close();
    bool isLoaded();
        
};
