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

#include "PlayerAsset.h"

//--------------------------------------------------------------
PlayerAsset::PlayerAsset(AssetManagerInterface* man, const string& _name) : BaseMediaAsset(man){
    
    canSource = true;
    
    assetType = MEDIA_ASSET_PLAYER;
    
    addAlias(_name);
    
    player = ofPtr<ofxVideoBufferPlayer>(new ofxVideoBufferPlayer());
    
    addOscMethod("buffer");
    
    addOscMethod("start");
    addOscMethod("stop");
    addOscMethod("pause");
    
    addOscMethod("loopmode");
    
    addOscMethod("looppoints");
    addOscMethod("looppointstart");
    addOscMethod("looppointend");
    
    addOscMethod("looppointsn");
    addOscMethod("looppointstartn");
    addOscMethod("looppointendn");
    
    addOscMethod("frame");
    addOscMethod("framen");    
    
    addOscMethod("speed");
    
    addOscMethod("dump");
    
}

//--------------------------------------------------------------
PlayerAsset::~PlayerAsset() {}

//--------------------------------------------------------------
void PlayerAsset::update() {
    player->update();
    
    // everybody has some work to do
    ofxVideoSourceInterface::update();
}

//--------------------------------------------------------------
bool PlayerAsset::dispose() {
    detachFromSinks();
    return true;
}

//--------------------------------------------------------------
void PlayerAsset::processOscCommand(const string& command, const ofxOscMessage& m) {
    
    ofLogNotice() << "PlayerAsset::processOscCommand(): " << getFirstOscNodeAlias() << " got a meessssaaaage!!!!" << endl;
    
    /*
     if(isMatch(command,"buffer")) {
     
     cout << "buffer ";
     
     if(validateOscSignature("[s][sfi]?", m)) {
     
     string assetId = getArgAsStringUnchecked(m,0);
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
    
    if(isMatch(command,"start")) { 
        player->start();
    } else if(isMatch(command,"stop")) {
        player->stop();
    } else if(isMatch(command,"pause")) {
        if(validateOscSignature("[sfi]", m)) {
            player->setPaused(getArgAsBoolean(m,0));
        }
    } else if(isMatch(command,"loopmode")) {
        if(validateOscSignature("s", m)) {
            string loopMode = getArgAsStringUnchecked(m,0);
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
    } else if(isMatch(command,"looppoints")) {
        if(validateOscSignature("[fi][fi]", m)) {
            player->setLoopPoints(getArgAsFloatUnchecked(m,0),getArgAsFloatUnchecked(m,1));
        }
    } else if(isMatch(command,"looppointstart")) {
        if(validateOscSignature("[fi]", m)) {
            player->setLoopPointStart(getArgAsFloatUnchecked(m,0));
        }
    } else if(isMatch(command,"looppointend")) {
        if(validateOscSignature("[fi]", m)) {
            player->setLoopPointStart(getArgAsFloatUnchecked(m,0));
        }
    } else if(isMatch(command,"looppointsn")) {
        if(validateOscSignature("[fi][fi]", m)) {
            player->setLoopPointsNorm(getArgAsFloatUnchecked(m,0),getArgAsFloatUnchecked(m,1));
        }
    } else if(isMatch(command,"looppointstartn")) {
        if(validateOscSignature("[fi]", m)) {
            player->setLoopPointStartNorm(getArgAsFloatUnchecked(m,0));
        }
    } else if(isMatch(command,"looppointendn")) {
        if(validateOscSignature("[fi]", m)) {
            player->setLoopPointStartNorm(getArgAsFloatUnchecked(m,0));
        }
    } else if(isMatch(command,"frame")) {
        if(validateOscSignature("[fi]", m)) {
            player->setFrame(getArgAsFloatUnchecked(m,0));
        }
    } else if(isMatch(command,"/framen")) {
        if(validateOscSignature("[fi]", m)) {
            player->setFrameNorm(getArgAsFloatUnchecked(m,0));
        }
    } else if(isMatch(command,"speed")) {
        if(validateOscSignature("[fi]", m)) {
            player->setSpeed(getArgAsFloatUnchecked(m,0));
        }
    } else {
        // unknown command
    }
}

//--------------------------------------------------------------
void PlayerAsset::load(BufferAsset* buffer) {
    
}

//--------------------------------------------------------------
void PlayerAsset::load(ImageAsset* image) {
    
}

//--------------------------------------------------------------
void PlayerAsset::load(MovieAsset* movie) {
    
}

//--------------------------------------------------------------
void PlayerAsset::draw(float x,float y) {
    player->draw(x,y);
}

//--------------------------------------------------------------
void PlayerAsset::draw(float x,float y,float w, float h) {
    player->draw(x,y,w,h);
}

//--------------------------------------------------------------
bool PlayerAsset::isFrameNew() {
    return player->isFrameNew(); // we loaded it once.
}

//--------------------------------------------------------------
ofPixelsRef PlayerAsset::getPixelsRef() {
    return player->getPixelsRef();
}

//--------------------------------------------------------------
void PlayerAsset::open()   {
    ofLogVerbose() << "PlayerAsset::open(): is not implemented.";
}

//--------------------------------------------------------------
void PlayerAsset::close() {
    ofLogVerbose() << "PlayerAsset::close(): is not implemented.";
}

//--------------------------------------------------------------
bool PlayerAsset::isLoaded() {
    return player->isLoaded();
}


//--------------------------------------------------------------
ofPtr<ofxVideoBufferPlayer> PlayerAsset::getPlayer() {
    return player;
}

