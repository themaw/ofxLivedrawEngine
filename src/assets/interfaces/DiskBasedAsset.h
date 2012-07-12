//
//  DiskInterface.h
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 7/7/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#pragma once

#include "BaseMediaAsset.h"

class DiskBasedAsset : public virtual BaseMediaAsset 
{
public:
    DiskBasedAsset(string _filename) {
        filename  = _filename;
        diskAsset = true;
    }
    virtual ~DiskBasedAsset() {}

    string getFilename() const {
        return filename;
    }
    
//    void fileMoved(const string& newLocation) {};
    
protected:
    string filename;
};
