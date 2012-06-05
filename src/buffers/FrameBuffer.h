//
//  Header.h
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 5/13/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#pragma once

#include "ofMain.h"
#include <set>
#include "MediaAsset.h"
#include "ofxVideoBuffer.h"
#include "ofxOscRouterNode.h"
#include "BaseVideoSink.h"

// Frame Buffer is a wrapper for ofxVideoBuffer.
// When it has a backing asset, it cannot be modified
// but simply acts as a place to store full video 
// assets in memory (GPU/RAM).

//class BaseVideoSink;
class ofxVideoBuffer;
//class ofxVideoPlayer;
//class MediaAsset;

class FrameBuffer : public ofxVideoBuffer, public ofxOscRouterNode /* , public BaseVideoSink*/{
public:
    FrameBuffer(string alias);
    FrameBuffer(string alias, int _bufferSize);
    FrameBuffer(string alias, int _bufferSize, ofVideoBufferType _type);
    virtual ~FrameBuffer();
    
    void processOscMessage(string pattern, ofxOscMessage& m);

    
    string getAlias();
    void   setAlias(string _alias);
    
    //  void setBackingAsset(MediaAsset* _asset);
//    bool        hasBackingAsset();
//    MediaAsset* getBackingAsset();
    
//    bool        attachedPlayer(ofxVideoPlayer* player);
//    bool        detatchPlayer(ofxVideoPlayer* player);
    
protected:
    void init(string alias);
    
  //  MediaAsset*
    string      alias;
//    MediaAsset* backingAsset; // only one source at a time

};