//
//  SinkAsset.h
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 7/6/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#pragma once

#include "BaseMediaAsset.h"
#include "ofxVideoSourceInterface.h"

class SinkInterface : public virtual BaseMediaAsset, 
                      public virtual ofxVideoSourceInterface 
{
public:
    SinkInterface() { 
        canSink = true; 
    }
    
    virtual ~SinkInterface() {}
};
