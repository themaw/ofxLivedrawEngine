//
//  DiskInterface.h
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 7/7/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#pragma once

#include "BaseMediaAsset.h"

class DiskBased : public virtual BaseMediaAsset {
public:
    DiskBased(string _filename) {
        filename  = _filename;
        diskAsset = true;
    }
    virtual ~DiskBased() {}

    string getFilename() const {
        return filename;
    }
    
protected:
    string filename;
};
