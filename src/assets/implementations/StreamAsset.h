//
//  StreamAsset.h
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 7/6/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#pragma once

#include "BaseMediaAsset.h"
#include "FrameSourceAsset.h"

#include "ofxIpVideoGrabber.h"

enum StreamType
{
    STREAM_TYPE_IPCAM,
    STREAM_TYPE_RTSP,
    STREAM_TYPE_QT
};

class StreamAsset : public virtual BaseMediaAsset,
                    public virtual FrameSourceAsset 
{
public:
    StreamAsset(const string& _name, StreamType _type, string _url, string _username, string _password);
    virtual ~StreamAsset();
    
    void processOscMessage(const string& pattern, const ofxOscMessage& m);
    
    bool dispose();
    
    bool isFrameNew();
    ofPixelsRef getPixelsRef();
    
    void open();
    void close();
    
    bool isLoaded();
    
    // getters and setters
    string getUrl();
    string getUsername();
    string getPassword();

    StreamType getStreamType();
    
protected:
    string     url;
    string     username;
    string     password;
    StreamType streamType;
    
    bool isIpVideo;
    
    ofPtr<ofxIpVideoGrabber> ipcam;
    ofPtr<ofVideoPlayer>     qtcam;

};
