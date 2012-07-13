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
    DiskBasedAsset(string _filename);
    virtual ~DiskBasedAsset();
    string getFilename() const;
//    void fileMoved(const string& newLocation) {};
    
protected:
    string filename;
};
