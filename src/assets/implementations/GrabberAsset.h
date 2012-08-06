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

#include "ofxVideoSourceInterface.h"
#include "BaseMediaAsset.h"
#include "FrameSourceAsset.h"

class GrabberAsset : public virtual BaseMediaAsset, 
                     public virtual ofxVideoSourceInterface
{
public:
    GrabberAsset(const string& _name, int _devId, int _width, int _height);
    virtual ~GrabberAsset();

    void update();
    
    bool dispose();
    void processOscCommand(const string& command, const ofxOscMessage& m);
    
    ofPixelsRef getPixelsRef();
    bool isFrameNew();

    void open();
    void close();
    bool isLoaded();

protected:
    int width;
    int height;
    int devId;
    
    ofPtr<ofVideoGrabber> grabber;
    
};
