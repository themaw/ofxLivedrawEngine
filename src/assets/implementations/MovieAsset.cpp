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
MovieAsset::MovieAsset(const string& _name, const string& _filename) : CacheableAsset(_filename), DiskBasedAsset(_filename){
    assetType = MEDIA_ASSET_MOVIE;
    addAlias(_name);
}

//--------------------------------------------------------------
MovieAsset::~MovieAsset() {}

//--------------------------------------------------------------
void MovieAsset::update() {

    
    // everybody has some work to do
    CacheableAsset::update();
}

//--------------------------------------------------------------
bool MovieAsset::dispose() {
    uncache();
    return true;
}

// TODO: we don't even need this if we don't have any other messages.
//   void processOscCommand(const string& command, const ofxOscMessage& m) {
//       
//       if(isMatch(pattern, "/cache") || isMatch(pattern, "/uncache")) {
//           Cacheable::processOscCommand(pattern, m);
//       } else {
//           cout << "processing message inside of movie asset." << endl;
//       }
//
//       
//       
//   }


//--------------------------------------------------------------
bool MovieAsset::doCache() {
    
    cout << "MovieAsset::doCache  " << endl;

    if(hasCacheProvider()) {
        cout << "MovieAsset::caching asset  " << endl;

        return cacheProvider->cacheAsset(this);
    } else {
        cout << "didn't have a cache provider  " << endl;
        
        return false;
    }
    
}

//--------------------------------------------------------------
bool MovieAsset::doUncache() {

    cout << "MovieAsset::doUncache  " << endl;

    
    if(hasCacheProvider()) {
        cout << "MovieAsset::uncaching asset  " << endl;
        
        return cacheProvider->uncacheAsset(this);
    } else {
        cout << "didn't have a cache provider  " << endl;
        
        return false;
    }

}
