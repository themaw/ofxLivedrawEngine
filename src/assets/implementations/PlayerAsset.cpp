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
PlayerAsset::PlayerAsset(AssetManagerInterface* man, const string& _name) : BaseMediaAsset(man), PlayerAssetInterface(man) {
    
    canSource = true;
    
    assetType = MEDIA_ASSET_PLAYER;
    
    addAlias(_name);
    
    player = ofPtr<ofxVideoBufferPlayer>(new ofxVideoBufferPlayer());
    
    currentAssetLink = NULL;
    
    //addOscMethod("buffer");

    addOscMethod("play");
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
    
    if(currentAssetLink != NULL) {
        currentAssetLink->playerDisposed(this);
    }
    return true;
}

//--------------------------------------------------------------
void PlayerAsset::processOscCommand(const string& command, const ofxOscMessage& m) {
    
    if(isMatch(command,"load")) {
        if(validateOscSignature("s", m)) {
            string assetAlias = getArgAsStringUnchecked(m, 0);
            
            if(hasAssetManager()) {
                BaseMediaAsset* asset = getAssetManager()->getAsset(assetAlias);
                
                if(asset != NULL) {
                    if(asset->isPlayable()) {
                        PlayableAsset* playableAsset = dynamic_cast<PlayableAsset*>(asset);
                        if(playableAsset != NULL) {
                            load(playableAsset);
                        } else {
                            ofLogError("PlayerAsset") << assetAlias << " could not be cast to a playable asset.";
                        }
                        
                    } else {
                        ofLogError("PlayerAsset") << assetAlias << " is not a playable asset.";
                    }
                } else {
                    ofLogError("PlayerAsset") << "no asset called " << assetAlias << " exists.";
                }
            }
            
            
            
        }
    } else if(isMatch(command,"start")) {
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
    } else if(isMatch(command,"framen")) {
        if(validateOscSignature("[fi]", m)) {
            player->setFrameNorm(getArgAsFloatUnchecked(m,0));
        }
    } else if(isMatch(command,"speed")) {
        if(validateOscSignature("[fi]", m)) {
            player->setSpeed(getArgAsFloatUnchecked(m,0));
        }
    } else if(isMatch(command,"dump")) {
        dump();
    } else {
        // unknown command
    }
}

//--------------------------------------------------------------
void PlayerAsset::load(PlayableAsset* asset) {
    
    if(asset->getAssetType() == MEDIA_ASSET_MOVIE) {
        MovieAsset* movie = dynamic_cast<MovieAsset*>(asset);
        if(movie != NULL) {
            
            currentAssetLink = movie;
            currentAssetLink->addPlayer(this);

            if(movie->isCached() &&
               movie->getCacheBuffer() != NULL &&
               movie->getCacheBuffer()->getBuffer() != NULL) {
                movie->getCacheBuffer()->addPlayer(this); // link player to buffer
                
                // TODO, if buffer is deleted, attempt to buffer's parent file
                cout << "in here!" << endl;
                player->loadVideoBuffer(movie->getCacheBuffer()->getBuffer());
            } else {
                player->loadMovie(movie->getFilename());
            }
            
        } else {
            ofLogError("PlayerAsset") << "::load : unable to load, dynamic cast failed.";
        }
        
    } else if(asset->getAssetType() == MEDIA_ASSET_BUFFER) {
        BufferAsset* buffer = dynamic_cast<BufferAsset*>(asset);
        if(buffer != NULL) {
            currentAssetLink = buffer;
            currentAssetLink->addPlayer(this);
            player->loadVideoBuffer(buffer->getBuffer());
        } else {
            ofLogError("PlayerAsset") << "::load : unable to load, dynamic cast failed.";
        }
        
    } else {
        ofLogError("PlayerAsset") << "::load : a playable asset, but unknown type : " << asset->getAssetType();
    }

}

//--------------------------------------------------------------
void PlayerAsset::cacheComplete(CacheableAsset* asset) {
    //ofLogError("PlayerAsset") << "::cacheComplete from " << getName() << " reported () " ;

    if(currentAssetLink != NULL) {
        if(currentAssetLink->isCacheable()) {
            CacheableAsset* currentAssetLinkAsCachable = dynamic_cast<CacheableAsset*>(currentAssetLink);
            if(currentAssetLinkAsCachable == asset) {
//                cout << "0. >>" << player->toString() << endl;
//                cout << "hs0:="<<hasSinks() << endl;;
                player->replaceMovieWithBuffer(asset->getCacheBuffer()->getBuffer());
//                cout << "1. >>" << player->toString() << endl;
//                cout << "hs1:="<<hasSinks() << endl;;
                
                
            } else {
               
                cout << "not a match" << endl;
                // the incoming asset did not match our currently linked asset
            }
        
        } else {
            cout << "not cachable" << endl;
            // was not cachable.  odd.
        }
    } else {
        cout << "was null" << endl;
        // was null
    }
    
   // cout << "done." << endl;
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
    player->close();
}

//--------------------------------------------------------------
bool PlayerAsset::isLoaded() {
    return player->isLoaded();
}