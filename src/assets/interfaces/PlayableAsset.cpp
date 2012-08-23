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

#include "PlayableAsset.h"

//--------------------------------------------------------------
PlayableAsset::PlayableAsset(AssetManagerInterface* man) : BaseMediaAsset(man) {
    canPlay = true;
}

//--------------------------------------------------------------
PlayableAsset::~PlayableAsset() {
    // nothing
}

//--------------------------------------------------------------
void PlayableAsset::loadedByPlayer(PlayerAssetInterface* player) {
    addPlayer(player);
}

//--------------------------------------------------------------
bool PlayableAsset::dispose() {
    detatchFromAllPlayers();
    return true;
}

//--------------------------------------------------------------
void PlayableAsset::playerDisposed(PlayerAssetInterface* player) {
    removePlayer(player);
}

//--------------------------------------------------------------
bool PlayableAsset::hasPlayers() const {
    return !players.empty();
}

//--------------------------------------------------------------
int  PlayableAsset::getNumPlayers() const {
    return players.size();
}

//--------------------------------------------------------------
bool PlayableAsset::hasPlayer(PlayerAssetInterface* player) const {
    return players.find(player) != players.end();
}

//--------------------------------------------------------------
void PlayableAsset::addPlayer(PlayerAssetInterface* player) {
    if(!hasPlayer(player)) {
        players.insert(player);
    } else {
        ofLogWarning("PlayableAsset") << "addPlayer() : Tried to add player, but player was already there.";
    }
}

//--------------------------------------------------------------
void PlayableAsset::removePlayer(PlayerAssetInterface* player) {
    if(hasPlayer(player)) {
        players.erase(player);
    } else {
        ofLogWarning("PlayableAsset") << "removePlayer() : Tried to remove player, but player wasn't there.";
    }
}

//--------------------------------------------------------------
void PlayableAsset::reportCacheComplete(CacheableAsset* asset) {
    //cout << getName() << "  << I AM CONNECTED TO " << players.size() << " players." << endl;
    for(playersIter  = players.begin();
        playersIter != players.end();
        playersIter++) {
        (*playersIter)->cacheComplete(asset);
    }
}


//--------------------------------------------------------------
void PlayableAsset::detatchFromAllPlayers() {
    for(playersIter  = players.begin();
        playersIter != players.end();
        playersIter++) {
        (*playersIter)->close();
    }
    players.clear();
}

//--------------------------------------------------------------
std::set<PlayerAssetInterface*>& PlayableAsset::getPlayersRef() {
    return players;
}

