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

#include "MaskedInput.h"

//--------------------------------------------------------------
MaskedInput::MaskedInput(LayerManagerInterface* _lmi, const string& name) : ofxOscRouterNode(name) {
    lmi = _lmi;
    input = new LayerSink(lmi,"input");
    mask = new LayerSink(lmi,"mask");
    addOscChild(input);
    addOscChild(mask);
    
    alphaMaskSettings = new AlphaMaskSettings();
    addOscChild(alphaMaskSettings);
    
    
    
    alphaMaskSettings->setAlphaMode(1);
    alphaMaskSettings->setInvertMask(false);
    alphaMaskSettings->setInvertSource(false);
    alphaMaskSettings->setThreshold(.9);
    alphaMaskSettings->setSpread(.1);
    alphaMaskSettings->setGain(1);

    
}

//--------------------------------------------------------------
MaskedInput::~MaskedInput() {
    delete input;
    delete mask;
    
    delete alphaMaskSettings;
}

//--------------------------------------------------------------
void MaskedInput::update() {
    input->update();
    mask->update();
}

//--------------------------------------------------------------
bool MaskedInput::dispose() {
    input->detachFromSources();
    mask->detachFromSources();
    return true;
}

//--------------------------------------------------------------
void MaskedInput::processOscCommand(const string& command, const ofxOscMessage& m) {
    ofLogNotice("MaskedInput") << "processOscCommand " << getFirstOscNodeAlias() << endl;
}

//--------------------------------------------------------------
LayerSink& MaskedInput::getInput() {
    return *input;
}

//--------------------------------------------------------------
LayerSink& MaskedInput::getMask() {
    return *mask;
}

//--------------------------------------------------------------
AlphaMaskSettings& MaskedInput::getAlphaMaskSettings() {
    return *alphaMaskSettings;
}

