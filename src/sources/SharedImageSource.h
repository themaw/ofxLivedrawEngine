//
//  SharedFrameSource.h
//  livedraw
//
//  Created by Christopher P. Baker on 4/14/11.
//  Copyright 2011 Murmur Labs LLC. All rights reserved.
//

#pragma once

#include "ofMain.h"

// this will work for grabbers, streams, and live input
class SharedImageSource : public ofBaseImage {
    
    public:
    SharedImageSource() {};
    virtual ~SharedImageSource() {};
    
};