//
//  DiskBasedAsset.cpp
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 7/12/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#include "DiskBasedAsset.h"

//--------------------------------------------------------------
DiskBasedAsset::DiskBasedAsset(string _filename) {
    filename  = _filename;
    diskAsset = true;
}

//--------------------------------------------------------------
DiskBasedAsset::~DiskBasedAsset() {}

//--------------------------------------------------------------
string DiskBasedAsset::getFilename() const {
    return filename;
}
