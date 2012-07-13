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
#include "ofxSimpleSet.h"
#include "ofxVideoFrame.h"
#include "FrameSourceAsset.h"
#include "BaseMediaAsset.h"


class FrameSourceAsset;

class FrameSinkAsset : public virtual BaseMediaAsset {
public:
    FrameSinkAsset();
    
    virtual ~FrameSinkAsset();
    
    bool sink(ofxVideoFrame frame);
    virtual bool frameReceived(ofxVideoFrame frame) = 0;
    
    // connect / disconnect
    bool isConnected();
    bool attachToSource(FrameSourceAsset* source);    
    bool detachFromAllSources();
    bool detachFromSource(FrameSourceAsset* source);
    
    //    bool remoteAttachToSource(ofxVideoSourceInterface* source);
    //    bool remoteDetachFromSource(ofxVideoSourceInterface* source);
 

    // callbacks
    void sourceWasAttached(FrameSourceAsset* source)  {}; // these callbacks are available
    void sourceWasDetatched(FrameSourceAsset* source) {}; // these callbacks are available
    
    void sinkingEnabled() {};
    void sinkingDisabled() {};
    
    // get source list
    vector<FrameSourceAsset*> getSources();
    
    bool isSinking();
    void setSinking(bool _sinking);
private:
    
    bool sinking;
    
    ofxSimpleSet<FrameSourceAsset*> sources;
};
