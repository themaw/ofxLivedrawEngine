//
//  BufferPlayerAsset.h
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 7/6/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#pragma once

#include "ofxVideoBufferPlayer.h"

#include "BaseMediaAsset.h"
#include "FrameSourceAsset.h"


class BufferPlayerAsset : public virtual BaseMediaAsset, 
                          public virtual FrameSourceAsset 
{
public:
    BufferPlayerAsset(const string& _name) 
    {
        assetType = MEDIA_ASSET_BUFFERPLAYER;
        name = _name;
        player = ofPtr<ofxVideoBufferPlayer>(new ofxVideoBufferPlayer());

        addOscMethod("/buffer");
        
        addOscMethod("/start");
        addOscMethod("/stop");
        addOscMethod("/pause");
        
        addOscMethod("/loopmode");
        
        addOscMethod("/looppoints");
        addOscMethod("/looppointstart");
        addOscMethod("/looppointend");
        
        addOscMethod("/looppointsn");
        addOscMethod("/looppointstartn");
        addOscMethod("/looppointendn");
        
        addOscMethod("/frame");
        addOscMethod("/framen");    
        
        addOscMethod("/speed");

    }

    virtual ~BufferPlayerAsset() {}

    // Base media asset
    bool dispose() {
        detachFromAllSinks();

    }
    
    void processOscMessage(const string& pattern, const ofxOscMessage& m) {
        
        cout << getFirstOscNodeAlias() << " got a meessssaaaage!!!!" << endl;
        
        /*
        if(isMatch(pattern,"/buffer")) {
            
            cout << "buffer ";
            
            if(validateOscSignature("[s][sfi]?", m)) {
                
                string assetId = m.getArgAsString(0);
                bool useDisk = getArgAsBoolean(m,1);
                
                cout << "asset=" << assetId << " useDisk= " << useDisk << endl; 
                
                if(hasParentLayer()) {
                    
                    cout << parentLayer->getEngine() << endl;;
                    
                    AssetManager* assets = parentLayer->getEngine()->getAssetManager();
                    
                    BaseMediaAsset* asset = assets->getAsset(assetId);
                    //assets->getAssetBackedBuffer(<#MediaAsset *asset#>, <#bool wantDiskBackedAsset#>)
                    
                    if(asset != NULL) {
                        //cout << asset->toString() << endl;
                        cout << "STRINGGGG" << endl;
                    } else {
                        cout << "INVALID ASSET.  Does not exist." << endl;
                    }
                    
                    
                    
                    
                } else {
                    ofLog(OF_LOG_ERROR, "FrameBufferPlayer::const string& pattern, const ofxOscMessage& m(const string& pattern, ofxOscMessage& m)() - player has no parent layer!");
                }
            }
        } else 
            */
            
        if(isMatch(pattern, "/start")) { 
            player->start();
        } else if(isMatch(pattern, "/stop")) {
            player->stop();
        } else if(isMatch(pattern, "/pause")) {
            if(validateOscSignature("[sfi]", m)) {
                player->setPaused(getArgAsBoolean(m,0));
            }
        } else if(isMatch(pattern, "/loopmode")) {
            if(validateOscSignature("s", m)) {
                string loopMode = m.getArgAsString(0);
                if(isMatch(loopMode,"NONE")) {
                    player->setLoopType(OF_LOOP_NONE);
                } else if(isMatch(loopMode,"LOOP")) {
                    player->setLoopType(OF_LOOP_NORMAL);
                } else if(isMatch(loopMode,"PALINDROME")) {
                    player->setLoopType(OF_LOOP_PALINDROME);
                } else {
                    ofLog(OF_LOG_WARNING, "FrameBufferPlayer: Unknown loop mode: " + loopMode);
                }
            }
        } else if(isMatch(pattern, "/looppoints")) {
            if(validateOscSignature("[fi][fi]", m)) {
                player->setLoopPoints(m.getArgAsFloat(0),m.getArgAsFloat(1));
            }
        } else if(isMatch(pattern, "/looppointstart")) {
            if(validateOscSignature("[fi]", m)) {
                player->setLoopPointStart(m.getArgAsFloat(0));
            }
        } else if(isMatch(pattern, "/looppointend")) {
            if(validateOscSignature("[fi]", m)) {
                player->setLoopPointStart(m.getArgAsFloat(0));
            }
        } else if(isMatch(pattern, "/looppointsn")) {
            if(validateOscSignature("[fi][fi]", m)) {
                player->setLoopPointsNorm(m.getArgAsFloat(0),m.getArgAsFloat(1));
            }
        } else if(isMatch(pattern, "/looppointstartn")) {
            if(validateOscSignature("[fi]", m)) {
                player->setLoopPointStartNorm(m.getArgAsFloat(0));
            }
        } else if(isMatch(pattern, "/looppointendn")) {
            if(validateOscSignature("[fi]", m)) {
                player->setLoopPointStartNorm(m.getArgAsFloat(0));
            }
        } else if(isMatch(pattern, "/frame")) {
            if(validateOscSignature("[fi]", m)) {
                player->setFrame(m.getArgAsFloat(0));
            }
        } else if(isMatch(pattern, "/framen")) {
            if(validateOscSignature("[fi]", m)) {
                player->setFrameNorm(m.getArgAsFloat(0));
            }
        } else if(isMatch(pattern, "/speed")) {
            if(validateOscSignature("[fi]", m)) {
                player->setSpeed(m.getArgAsFloat(0));
            }
        } else {
            // unknown command
        }
    }

    void  draw(float x,float y) {
        player->draw(x,y);
    }
    
	void  draw(float x,float y,float w, float h) {
        player->draw(x,y,w,h);
    }

    
    // Frame Source
    
    bool isFrameNew() {
        return player->isFrameNew(); // we loaded it once.
    }
    
    ofPixelsRef getPixelsRef() {
        return player->getPixelsRef();
    }
    
    void open()   {
        // Not applicable.
    }
    
    void close() {
        // Not applicable.
    }
    
    bool isLoaded() {
        return player->isLoaded();
    }

    
    
    
protected:
    ofPtr<ofxVideoBufferPlayer> player;
};
