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

#include "BaseMediaAsset.h"
#include "PlayableAsset.h"

#include "ofxVideoBuffer.h"
#include "ofxVideoSinkInterface.h"

class CacheableAsset;

class BufferAsset : public virtual BaseMediaAsset, 
                    public virtual PlayableAsset,
                    public virtual ofxVideoSinkInterface
{
public:
    BufferAsset(AssetManagerInterface* man, const string& _name, int size, ofxVideoBufferType t);
    virtual ~BufferAsset();

    void update();
    
    // From BaseMediaAsset
    bool dispose();
    
    void processOscCommand(const string& command, const ofxOscMessage& m);

    void loadMovie(const string& filename);
    bool isLoaded() const;
    bool isLoading() const;
    
    // From FrameSink
    bool frameReceived(ofxSharedVideoFrame frame);

    bool isCacheBuffer() const;
    // here we keep a link to the source file
    void unlinkCacheSource();  // used when the original source is disposed
    CacheableAsset* getCacheSource();
    ofPtr<ofxVideoBuffer> getBuffer();
        
protected:
    CacheableAsset* cacheSource;
    ofxSharedVideoBuffer buffer;
};
