/*==============================================================================
 
 Copyright (c) 2010, 2011, 2012 Christopher Baker <http://christopherbaker.net>
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 
 ==============================================================================*/

#pragma once

#include "ofMain.h"
#include "ofxOscRouterNode.h"
#include "ofxEnablerInterface.h"

class AlphaMaskSettings : public ofxOscRouterNode, public ofxEnablerInterface {
    
public:
    
    AlphaMaskSettings() : ofxOscRouterNode("alphamask"), ofxEnablerInterface(true) {
        alphaMode    = 5;
        invertMask   = 0; // 0 = dark-alpha, 1 = light-alpha
        invertSource = 0; // 1 = invert, 0 = thru
        threshold    = 1.0; // range 0 - 1
        spread       = 0.01; //0.2);  //rtb runs between 0-1
        gain         = 1.0; // gain = 0 - 1000
        
        addOscMethod("alphamode");
        addOscMethod("invertmask");
        addOscMethod("invertsource");
        addOscMethod("threshold");
        addOscMethod("spread");
        addOscMethod("gain");
        addOscMethod("enable");
        
    }
    
    virtual ~AlphaMaskSettings() {}
    
    void processOscCommand(const string& command, const ofxOscMessage& m) {
        if(isMatch(command,"alphamode")) {
            if(validateOscSignature("[if]", m)) {
                setAlphaMode(getArgAsIntUnchecked(m,0));
            }
        } else if(isMatch(command,"invertmask")) {
            if(validateOscSignature("[sfi]", m)) {
                setInvertMask(getArgAsBoolUnchecked(m,0));
            }
        } else if(isMatch(command,"invertsource")) {
            if(validateOscSignature("[sfi]", m)) {
                setInvertSource(getArgAsBoolUnchecked(m,0));
            }
        } else if(isMatch(command,"threshold")) {
            if(validateOscSignature("[fi]", m)) {
                setThreshold(getArgAsFloatUnchecked(m,0));
            }
        } else if(isMatch(command,"spread")) {
            if(validateOscSignature("[fi]", m)) {
                setSpread(getArgAsFloatUnchecked(m,0));
            }
            
        } else if(isMatch(command,"gain")) {
            if(validateOscSignature("[fi]", m)) {
                setGain(getArgAsFloatUnchecked(m,0));
            }     
        } else if(isMatch(command,"enable")) {
            if(validateOscSignature("[sfi]", m)) {
                setEnabled(getArgAsFloatUnchecked(m,0));
            }
        }
    }

    void setAlphaMode(int am)       { alphaMode = ofClamp(am,0,5);}
    void setInvertMask(bool im)     { invertMask = im;}
    void setInvertSource(bool is)   { invertSource = is;}
    void setThreshold(float thresh) { threshold = ofClamp(thresh,0,1);}
    void setSpread(float s)         { spread = ofClamp(s,0,1);}
    void setGain(float g)           { gain = g;} // TODO: clamp gain?
    
    int   getAlphaMode() const {return alphaMode;}
    bool  getInvertMask() const {return invertMask;}
    bool  getInvertSource() const {return invertSource;}
    float getThreshold() const { return threshold;}
    float getSpread() const {return spread;}
    float getGain() const {return gain;}
    
    void onEnabled(){}
	void onDisabled(){}
    
private:
    
    int   alphaMode;
    bool  invertMask;
    bool  invertSource;
    float threshold;
    float spread;
    float gain;
    
};


class AlphaMask : public ofShader {
    
public:
    AlphaMask() : ofShader() {}
    ~AlphaMask() {};
    
    void setup() {
        setupShaderFromFile(GL_FRAGMENT_SHADER, "application/shaders/maw.shader.alphamasker.frag");
        linkProgram();
    }
    
    void apply(ofTexture& input, ofTexture& mask, const AlphaMaskSettings& settings) {
        
        bIsEnabled = settings.isEnabled();
        
        if(bIsEnabled) { // don't set anything unless it's enabled
            setUniformTexture("sourceTexture", input, 1 );
            setUniformTexture("maskTexture", mask, 2);
            
            setUniform1i("alphaMode",   settings.getAlphaMode());
            setUniform1i("invertMask",  settings.getInvertMask());
            setUniform1i("invertSource",settings.getInvertSource());
            setUniform1f("thresh",      settings.getThreshold());
            setUniform1f("spread",      settings.getSpread());
            setUniform1f("gain",        settings.getGain());
        }
    }
    
    bool isEnabled() const {
        return bIsEnabled;
    }
    
private:
    bool bIsEnabled;
};