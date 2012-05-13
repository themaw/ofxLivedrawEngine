//
//  ShaderAlphaMask.h
//  livedraw
//
//  Created by Christopher P. Baker on 5/16/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#pragma once

#include "ofMain.h"
#include "AbstractShaderEffect.h"
#include "OscNodeListener.h"
#include "EnablerInterface.h"

class ShaderAlphaMaskSettings : public OscNodeListener, public Enabler {
    
public:
    
    ShaderAlphaMaskSettings() : OscNodeListener("/alphamask"), Enabler(true) {
        alphaMode = 5;
        invertMask = 0; // 0 = dark-alpha, 1 = light-alpha
        invertSource = 0; // 1 = invert, 0 = thru
        threshold = 1.0; // range 0 - 1
        spread = 0.01; //0.2);  //rtb runs between 0-1
        gain = 1.0; // gain = 0 - 1000
        
        addOscCommand("/alphamode");
        addOscCommand("/invertmask");
        addOscCommand("/invertsource");
        addOscCommand("/threshold");
        addOscCommand("/spread");
        addOscCommand("/gain");
        addOscCommand("/enable");
        
    }
    
    virtual ~ShaderAlphaMaskSettings() {
        
    }
    
    void processOscMessage(string pattern, ofxOscMessage& m) {
        if(isMatch("/alphamode",pattern)) {
            if(validateOscSignature("[if]", m)) {
                setAlphaMode(m.getArgAsInt32(0));
            }
        } else if(isMatch("/invertmask",pattern)) {
            if(validateOscSignature("[fi]", m)) {
                setInvertMask(m.getArgAsInt32(0) == 1);
            }
        } else if(isMatch("/invertsource",pattern)) {
            if(validateOscSignature("[fi]", m)) {
                setInvertSource(m.getArgAsInt32(0) == 1);
            }
        } else if(isMatch("/threshold",pattern)) {
            if(validateOscSignature("[fi]", m)) {
                setThreshold(m.getArgAsFloat(0));
            }
        } else if(isMatch("/spread",pattern)) {
            if(validateOscSignature("[fi]", m)) {
                setSpread(m.getArgAsFloat(0));
            }
            
        } else if(isMatch("/gain",pattern)) {
            if(validateOscSignature("[fi]", m)) {
                setGain(m.getArgAsFloat(0));
            }     
        } else if(isMatch("/enable",pattern)) {
            if(validateOscSignature("[fi]", m)) {
                bool _enable = (m.getArgAsInt32(0) == 1);
                setEnabled(_enable);
            }
        }
    }

    void setAlphaMode(int am) {alphaMode = ofClamp(am,0,5);}
    void setInvertMask(bool im) {invertMask = im;}
    void setInvertSource(bool is) {invertSource = is;}
    void setThreshold(float thresh) {threshold = ofClamp(thresh,0,1);}
    void setSpread(float s) {spread = ofClamp(s,0,1);}
    void setGain(float g) {gain = ofClamp(g,0,1000);}
    
//    void setMaskTexture(int tex) {
///        maskTexture = tex;
 //   }
    
    int getAlphaMode() {return alphaMode;}
    bool getInvertMask() {return invertMask;}
    bool getInvertSource() {return invertSource;}
    float getThreshold() { return threshold;}
    float getSpread() {return spread;}
    float getGain() {return gain;}
    
   // void setMaskTexture
    
    void onEnabled(){}
	void onDisabled(){}

    
private:
    int alphaMode;
    bool invertMask;
    bool invertSource;
    float threshold;
    float spread;
    float gain;
    
};


class ShaderAlphaMask : public AbstractShaderEffect {
    
public:
    
    ShaderAlphaMask() : AbstractShaderEffect() {
    }

    ~ShaderAlphaMask() {};
    
    
    void setup() {
        load("application/shaders/maw.shader.passthrough.vert",   
                        "application/shaders/maw.shader.alphamasker.frag");
       
         //set the texture parameters for the maks shader. just do this at the beginning
         /*
         begin();
         setUniform1i("alphaMode",   5); // 
         setUniform1i("invertMask",  0);  // 0 = dark-alpha, 1 = light-alpha
         setUniform1i("invertSource",0);  // 1 = invert, 0 = thru
         setUniform1f("thresh",      1.0);  // range 0 - 1
         setUniform1f("spread",      0.01);  //0.2);  //rtb runs between 0-1
         setUniform1f("gain",        1.0);  // gain = 0 - 1000
         end();
        */

    }
    
    void applySettings(ShaderAlphaMaskSettings* settings) {
        setUniform1i("alphaMode",   settings->getAlphaMode()); 
        setUniform1i("invertMask",  settings->getInvertMask());
        setUniform1i("invertSource",settings->getInvertSource());
        setUniform1f("thresh",      settings->getThreshold());
        setUniform1f("spread",      settings->getSpread());
        setUniform1f("gain",        settings->getGain());
    }

    
    void setMaskTexture(int i) {
        setUniform1i("maskTexture", i);
    }
    

};