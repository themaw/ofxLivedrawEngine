//
//  CanvasGroupManager.h
//  livedraw
//
//  Created by Christopher P. Baker on 5/17/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//


#pragma once

#include "ofMain.h"
#include "OscNodeListener.h"
#include "CanvasGroup.h"
#include "CanvasLayer.h"
#include "CanvasLayerManager.h"


class CanvasGroupManager : public OscNodeListener {
public:
    
    CanvasGroupManager(CanvasLayerManager* layerManager);
    virtual ~CanvasGroupManager();
    
    void processOscMessage(string pattern, ofxOscMessage& m);
    
	CanvasGroup* newGroup(string groupName, vector<CanvasLayer*> layers);
	bool deleteGroup(string groupName);
    
private:
    CanvasLayerManager* layerManager;
    vector<CanvasGroup*> groups;
    

    
};