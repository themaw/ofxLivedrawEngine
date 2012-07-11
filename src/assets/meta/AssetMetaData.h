/*
 *  AssetMetaData.h
 *  livedraw
 *
 *  Created by Christopher P. Baker on 12/3/10.
 *  Copyright 2010 Murmur Labs LLC. All rights reserved.
 *
 */

#pragma once

#include "ofMain.h"
#include "ofxOscRouterNode.h"
#include <set>

class AssetMetaData : public ofxOscRouterNode,
                      public ofxSimpleSet<string> {
  
public:
    AssetMetaData();
    virtual ~AssetMetaData();

    void processOscMessage(const string& address, const ofxOscMessage& m);

//    vector<string> getKeywords() const;
//    bool hasKeyword(string _keyword) const;
//    void addKeyword(string _keyword);
//    void removeKeyword(string _keyword);
//    int  getNumKeywords();
    
    void   setDescription(string _description);
    string getDescription();

protected:
    string description;
};