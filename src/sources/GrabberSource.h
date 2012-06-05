//
//  GrabberSource.h
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 6/5/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#pragma once

#include "ofMain.h"

class GrabberSource {
public:
    GrabberSource();
    virtual ~GrabberSource();
protected:

    ofVideoGrabber grabber;
    
private:
};
