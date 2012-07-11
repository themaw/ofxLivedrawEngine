//
//  EffectsChain.h
//  livedraw
//
//  Created by Christopher P. Baker on 5/18/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#pragma once

#include "ofMain.h"
#include "ofxOscRouterNode.h"
#include "EffectsManager.h"
#include "ShaderCurves.h"
#include "ShaderAlphaMask.h"

class EffectsChain : public ofxOscRouterNode {
public:
    
    EffectsChain();
    virtual ~EffectsChain();

    void setup();
    void update();
    void draw();
    
    void processOscMessage(const string& pattern, const ofxOscMessage& m);
    void setEffectsManager(EffectsManager* manager);
    
private:
    
    EffectsManager* effectsManager;
    
    ShaderAlphaMaskSettings alphaMaskSettings;
    ShaderCurvesSettings    curvesSettings;
    
};
