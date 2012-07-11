//
//  MovieAsset.h
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 7/6/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#pragma once

#include "Cacheable.h"

class MovieAsset : public virtual BaseMediaAsset,
                   public virtual Cacheable {
public:
    MovieAsset(const string& _name, string _filename) {
       assetType = MEDIA_ASSET_MOVIE;
       name      = _name;
       filename  = _filename;
    }
    
    virtual ~MovieAsset() {}

    virtual bool dispose() {
        return unCache();
    }

   void processOscMessage(const string& pattern, const ofxOscMessage& m) {
       
   }
                       
                       
    bool doCache()   {return true;}
    bool doUnCache() {return true;}

protected:
    string filename;
};
