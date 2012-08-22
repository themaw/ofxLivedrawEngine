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

#include "ofxVideoBufferPlayer.h"
#include "ofxVideoSourceInterface.h"
#include "PlayableAsset.h"
#include "PlayerAssetInterface.h"

#include "BufferAsset.h"
#include "ImageAsset.h"
#include "MovieAsset.h"
#include "CacheableAsset.h"

class PlayerAsset : public virtual BaseMediaAsset,
                    public virtual ofxVideoSourceInterface,
                    public virtual PlayerAssetInterface
{
public:
    PlayerAsset(AssetManagerInterface* man, const string& _name);
    virtual ~PlayerAsset();

    void update();
    
    // Base media asset
    bool dispose();
    
    void processOscCommand(const string& command, const ofxOscMessage& m);

    void load(PlayableAsset* asset);
    void cacheComplete(CacheableAsset* asset);

    void  draw(float x,float y);
	void  draw(float x,float y,float w, float h);

    // Frame Source
    bool isFrameNew();

    ofPixelsRef getPixelsRef();

    void open();
    void close();
    bool isLoaded();
    
    void dump() {
        ofLogNotice("PlayerAsset") << "dump() : " << player->toString();
    }
    
protected:
    
    bool isPlayingCached() {
        
    }
    
    PlayableAsset* currentAssetLink;
    
    ofPtr<ofxVideoBufferPlayer> player;
};
