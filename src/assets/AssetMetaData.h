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
#include <set>

class AssetMetaData {
  
public:
    AssetMetaData();
    virtual ~AssetMetaData();

    bool containsKeyword(string _keyword);
    void addKeyword(string _keyword);
    void removeKeyword(string _keyword);
    int  getNumKeywords();
    
    void   setDescription(string _description);
    string getDescription();

protected:
    
    string description;
    
    set<string> keywords;
    set<string>::iterator it;

};