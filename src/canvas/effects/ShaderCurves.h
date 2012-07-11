//
//  ShaderCurves.h
//  livedraw
//
//  Created by Christopher P. Baker on 5/16/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//


#pragma once

#include "ofMain.h"
#include "AbstractShaderEffect.h"
#include "ofxEnablerInterface.h"

#define LUT_LENGTH 3 // assume 8 bit pis / color / pixel

class ShaderCurvesSettings : public ofxOscRouterNode, public ofxEnablerInterface {
    
public:
    ShaderCurvesSettings() : ofxOscRouterNode("/curves"), ofxEnablerInterface(true) {
        // just init a normal map
        for(int i = 0; i < LUT_LENGTH; i++) {
            dataLUT[i][0] = ofMap(i, 0, LUT_LENGTH-1, 0, 1);   // R low
            dataLUT[i][1] = ofMap(i, 0, LUT_LENGTH-1, 0, 1);   // G low
            dataLUT[i][2] = ofMap(i, 0, LUT_LENGTH-1, 0, 1);   // B low
        }
        
        addOscMethod("/lut");
        addOscMethod("/enable");
    }
    
    ~ShaderCurvesSettings() {
        
    }
    
    void processOscMessage(const string& pattern, const ofxOscMessage& m) {
        if(isMatch("/lut",pattern)) {
            if(validateOscSignature("([if][if][if])([if][if][if])([if][if][if])", m)) {
                int j = 0;
                for(int i = 0; i < 3; i++) {
                    dataLUT[i][0] = m.getArgAsInt32(j++);
                    dataLUT[i][1] = m.getArgAsInt32(j++);
                    dataLUT[i][2] = m.getArgAsInt32(j++);
                }
            }
        } else if(isMatch("/enable",pattern)) {
            if(validateOscSignature("[fi]", m)) {
                setEnabled(getArgAsBoolean(m,0));
            }
        }
    }
    
    void setLUT(int i, int rgb, float val) {
        dataLUT[i][rgb] = val;
    }
    
    void setLUTRed(int i, float val) {
        dataLUT[i][0] = val;
    }

    void setLUTGreen(int i, float val) {
        dataLUT[i][1] = val;
    }

    void setLUTBlue(int i, float val) {
        dataLUT[i][2] = val;
    }

    
    float* getLUT() {
        return &dataLUT[0][0];
    }
    
    int getLUTLength() {
        return LUT_LENGTH;
    }
    
    GLuint getLUTTexture() {
        return textureLUT[0];
    }
    
    void onEnabled(){}
	void onDisabled(){}
    
private:
    float dataLUT[LUT_LENGTH][3];
    GLuint textureLUT[1];
};


class ShaderCurves : public AbstractShaderEffect {
    
public:
    
    ShaderCurves() : AbstractShaderEffect() {
    }
    
    ~ShaderCurves() {};
    
    
    void setup() {
        load("application/shaders/maw.shader.passthrough.vert",   
                        "application/shaders/maw.shader.curves.frag");
    }
    
    void applySettings(ShaderCurvesSettings* settings) {
        
        setUniform1i("LUT_LENGTH",settings->getLUTTexture());
        
        glBindTexture (GL_TEXTURE_1D, settings->getLUTTexture());	// Bind This Texture. From Now On It Will Be 1D
        glTexImage1D (GL_TEXTURE_1D, 0, GL_RGB, settings->getLUTLength(), 0, GL_RGB , GL_FLOAT, settings->getLUT());
        glDisable(GL_TEXTURE_1D);
    }
    
};