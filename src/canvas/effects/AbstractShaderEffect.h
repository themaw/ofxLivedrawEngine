/*
 *  AbstractEffect.h
 *  livedraw
 *
 *  Created by Christopher P. Baker on 12/3/10.
 *  Copyright 2010 Murmur Labs LLC. All rights reserved.
 *
 */



#pragma once

#include "ofMain.h"


class AbstractShaderEffect : public ofShader {
    
public:
    AbstractShaderEffect() : ofShader() {
    }
    virtual ~AbstractShaderEffect() {};
    void setSourceTexture(int i) {
        setUniform1i("sourceTexture", i);
    }
    
};
