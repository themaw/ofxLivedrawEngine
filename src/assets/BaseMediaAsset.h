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

#pragma once

#include "ofMain.h"

#include "ofxOscRouterBaseNode.h"
#include "AssetManagerInterface.h"
#include "AssetMetaData.h"

enum MediaAssetType
{
    MEDIA_ASSET_UNDEFINED,
	MEDIA_ASSET_IMAGE,
	MEDIA_ASSET_MOVIE,
	MEDIA_ASSET_GRABBER,
	MEDIA_ASSET_STREAM,
    MEDIA_ASSET_BUFFER,
    MEDIA_ASSET_PLAYER,
    MEDIA_ASSET_SYPHON
};

class BaseMediaAsset : virtual public ofxOscRouterBaseNode, public ofBaseUpdates {
public:
	BaseMediaAsset(AssetManagerInterface* man);
	virtual ~BaseMediaAsset();

    virtual void update() = 0;
    
    virtual bool dispose() = 0;
    virtual void processOscCommand(const string& command, const ofxOscMessage& m) = 0;

    set<string>& getOscNodeAliasesRef();
    const set<string>& getOscNodeAliasesRef() const;
    
	MediaAssetType  getAssetType() const;   
	string          getAssetTypeString() const;

    string  getName() const;
    
    // interface capabilities
    bool isPlayable()  const;
    bool isSource()    const;
    bool isSink()      const;
    bool isCacheable() const;
    bool isDiskAsset() const;
    
    // utilities
    string toString() const;

    set<string>& getAliasesRef();
    
    string getFirstAlias() const;
    bool hasAlias(const string& alias) const;
    bool addAlias(const string& alias);
    bool removeAlias(const string& alias);
    
    bool hasAssetManager() const;
    AssetManagerInterface* getAssetManager() const;
    void setAssetManager(AssetManagerInterface* man);
    
protected:
    
    AssetManagerInterface* assetManager;


    
    set<string> aliases; // normal ascending order, reverse iterate later
    
    MediaAssetType assetType;

    bool canPlay;
    bool canSource;
    bool canSink;
    bool canCache;
    bool diskAsset;
    
    AssetMetaData meta;
        
};







