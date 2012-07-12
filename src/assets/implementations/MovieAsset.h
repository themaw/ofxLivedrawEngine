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
    MovieAsset(const string& _name, string _filename) : DiskBasedAsset(_filename) {
       assetType = MEDIA_ASSET_MOVIE;
       name      = _name;
    }
    
    virtual ~MovieAsset() {}

    virtual bool dispose() {
        uncache();
        return true;
    }

// TODO: we don't even need this if we don't have any other messages.
//   void processOscMessage(const string& pattern, const ofxOscMessage& m) {
//       
//       if(isMatch(pattern, "/cache") || isMatch(pattern, "/uncache")) {
//           Cacheable::processOscMessage(pattern, m);
//       } else {
//           cout << "processing message inside of movie asset." << endl;
//       }
//
//       
//       
//   }
                       
                       
    bool doCache()   {
        
//        if(hasAssetManager()) {
//            cacheBuffer = manager->addBuffer("cache_" + name, 1, OFX_VIDEO_BUFFER_FIXED);
//        }
        
        
        
        return true;
    }
    
    bool doUncache() {
        cout << "uncaching" << endl;
        return true;
    }

protected:
};
