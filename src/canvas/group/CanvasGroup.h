/*
 *  CanvasGroup.h
 *  livedraw
 *
 *  Created by Christopher P. Baker on 3/7/11.
 *  Copyright 2011 Murmur Labs LLC. All rights reserved.
 *
 */


#pragma once

#include "ofMain.h"
#include "CanvasLayer.h"

class CanvasGroup {
public:    
    
    CanvasGroup(string name);
    virtual ~CanvasGroup();
    
    bool addLayer(CanvasLayer* layer);
    bool removeLayer(CanvasLayer* layer);
    
    
private:
    string name;
    vector<CanvasLayer*> groupLayers;
    
};