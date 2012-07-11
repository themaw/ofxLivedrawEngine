//
//  StreamAsset.h
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 7/6/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#pragma once

#include "BaseMediaAsset.h"
#include "FrameSource.h"

#include "ofxIpVideoGrabber.h"

enum StreamType
{
    STREAM_TYPE_IPCAM,
    STREAM_TYPE_RTSP,
    STREAM_TYPE_QT
};


class StreamAsset : public virtual BaseMediaAsset,
                    public virtual FrameSource 
{
public:
    StreamAsset(const string& _name, StreamType _type, string _url, string _username, string _password) {
        assetType  = MEDIA_ASSET_STREAM;
        streamType = _type;
        name       = _name;
        url        = _url;
        username   = _username;
        password   = _password;
        
        isIpVideo = streamType == STREAM_TYPE_IPCAM;

        if(isIpVideo) {
            ipcam = ofPtr<ofxIpVideoGrabber>(new ofxIpVideoGrabber());
            ipcam->setURI(url);
            ipcam->setUsername(username);
            ipcam->setPassword(password);
        } else {
            qtcam = ofPtr<ofVideoPlayer>(new ofVideoPlayer());
            qtcam->loadMovie(url); // TODO: construct correct user/pass string
        }
        
        addOscMethod("/open");
        addOscMethod("/close");
        addOscMethod("/start");
        addOscMethod("/stop");
        addOscMethod("/size");
    }
    virtual ~StreamAsset() {
        // ofPtr!
    }
    
    void processOscMessage(const string& pattern, const ofxOscMessage& m) {
        
    }
    virtual bool dispose() {
        cout << "disposing of stream " << getName() << endl;
    }
    
    bool isFrameNew() {
        if(isIpVideo) {
            return ipcam->isFrameNew();
        } else {
            return qtcam->isFrameNew();
        }
    }
    ofPixelsRef getPixelsRef() {
        if(isIpVideo) {
            return ipcam->getPixelsRef();
        } else {
            return qtcam->getPixelsRef();
        }
    }
    
    void open()   {
        if(isIpVideo) {
            ipcam->connect();
        } else {
            qtcam->loadMovie(url);
        }
    }
    
    void close()  {
        if(isIpVideo) {
            ipcam->close();
        } else {
            qtcam->close();;
        }
    }
    
    bool isLoaded() {
        if(isIpVideo) {
            return ipcam->isConnected();
        } else {
            return qtcam->isLoaded();
        }
    }
    
    // getters and setters
    string getUrl() {
        return url;
    }
    
    string getUsername() {
        return username;
    }
    
    string getPassword() {
        return password;
    }
    
    StreamType getStreamType() {
        return streamType;
    }
    
protected:
    string     url;
    string     username;
    string     password;
    StreamType streamType;
    
    bool isIpVideo;
    
    ofPtr<ofxIpVideoGrabber> ipcam;
    ofPtr<ofVideoPlayer>     qtcam;

};
