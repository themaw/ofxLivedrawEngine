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

#include "MovieAsset.h"

//--------------------------------------------------------------
MovieAsset::MovieAsset(AssetManagerInterface* man, const string& _name, const string& _filename) : BaseMediaAsset(man),CacheableAsset(man, _filename),
                                                                       DiskBasedAsset(man, _filename),
                                                                       PlayableAsset(man) {
    assetType = MEDIA_ASSET_MOVIE;
    addAlias(_name);
}

//--------------------------------------------------------------
MovieAsset::~MovieAsset() {}

//--------------------------------------------------------------
void MovieAsset::processOscCommand(const string& command, const ofxOscMessage& m) {
    CacheableAsset::processOscCommand(command, m);
    
    cout << "movie asset got a command" << endl;
    
    
    cout << "MOVIEDASSET: " << getName() << " we are connected to : " << players.size() << " players." << endl;
    
}

//--------------------------------------------------------------
void MovieAsset::update() {

    
    // everybody has some work to do
    CacheableAsset::update();
}

//--------------------------------------------------------------
bool MovieAsset::dispose() {
    
    PlayableAsset::dispose();
    
    if(isCached() && getCacheBuffer() != NULL) {
        getCacheBuffer()->unlinkCacheSource();
    }
    uncache();
    return true;
}

//--------------------------------------------------------------
void MovieAsset::doCache() {
    if(hasAssetManager()) {
        ofLogVerbose() << "MovieAsset::doCache() : caching.";
        getAssetManager()->cacheAsset(this);
    } else {
        ofLogVerbose() << "MovieAsset::doCache() : failing - no cache provider.";
    }
}

//--------------------------------------------------------------
void MovieAsset::doUncache() {
    if(hasAssetManager()) {
        ofLogVerbose() << "MovieAsset::doUncache() : uncaching.";
        getAssetManager()->uncacheAsset(this);
    } else {
        ofLogVerbose() << "MovieAsset::doUncache() : failing - no cache provider.";
    }
}

