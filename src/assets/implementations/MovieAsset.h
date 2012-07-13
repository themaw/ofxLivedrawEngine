//
//  MovieAsset.h
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 7/6/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#pragma once

#include "BaseMediaAsset.h"
#include "DiskBasedAsset.h"
#include "CacheableAsset.h"
//#include "BufferAsset.h"

class MovieAsset : public virtual BaseMediaAsset,
                   public virtual DiskBasedAsset,
                   public virtual CacheableAsset
{
public:
    MovieAsset(const string& _name, string _filename);
    virtual ~MovieAsset();
    bool dispose();

    bool doCache();
    bool doUncache();
};
