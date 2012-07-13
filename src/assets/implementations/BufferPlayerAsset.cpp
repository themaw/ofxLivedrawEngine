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


#include "BufferPlayerAsset.h"

//--------------------------------------------------------------
BufferPlayerAsset::BufferPlayerAsset(const string& _name) 
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

//--------------------------------------------------------------
BufferPlayerAsset::~BufferPlayerAsset() {}

//--------------------------------------------------------------
bool BufferPlayerAsset::dispose() {
    detachFromAllSinks();
}

//--------------------------------------------------------------
void BufferPlayerAsset::processOscMessage(const string& pattern, const ofxOscMessage& m) {
    
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

//--------------------------------------------------------------
void BufferPlayerAsset::draw(float x,float y) {
    player->draw(x,y);
}

//--------------------------------------------------------------
void BufferPlayerAsset::draw(float x,float y,float w, float h) {
    player->draw(x,y,w,h);
}

//--------------------------------------------------------------
bool BufferPlayerAsset::isFrameNew() {
    return player->isFrameNew(); // we loaded it once.
}

//--------------------------------------------------------------
ofPixelsRef BufferPlayerAsset::getPixelsRef() {
    return player->getPixelsRef();
}

//--------------------------------------------------------------
void BufferPlayerAsset::open()   {
    // Not applicable.
}

//--------------------------------------------------------------
void BufferPlayerAsset::close() {
    // Not applicable.
}

//--------------------------------------------------------------
bool BufferPlayerAsset::isLoaded() {
    return player->isLoaded();
}

