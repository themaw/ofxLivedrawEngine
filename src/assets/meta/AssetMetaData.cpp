/*
 *  AssetMetaData.cpp
 *  livedraw
 *
 *  Created by Christopher P. Baker on 12/3/10.
 *  Copyright 2010 Murmur Labs LLC. All rights reserved.
 *
 */

#include "AssetMetaData.h"

//--------------------------------------------------------------
AssetMetaData::AssetMetaData() : ofxOscRouterNode("/meta") {
    description = "";

    addOscMethod("/add");
    addOscMethod("/remove");
    addOscMethod("/change");
    addOscMethod("/description");
}

//--------------------------------------------------------------
AssetMetaData::~AssetMetaData() {};

//--------------------------------------------------------------
void AssetMetaData::processOscMessage(const string& pattern, const ofxOscMessage& m) {
    
    cout << "processing meta data." << endl;
    
    //    ofLog(OF_LOG_ERROR, "AssetMetaData::const string& pattern, const ofxOscMessage& m(const string& pattern, ofxOscMessage& m) - unimplemented.");
}

////--------------------------------------------------------------
//bool AssetMetaData::containsKeyword(string keyword) {
//    return keywords.find(keyword) != keywords.end();
//}
//
////--------------------------------------------------------------
//void AssetMetaData::addKeyword(string keyword) {
//    keywords.insert(keyword);
//}
//
////--------------------------------------------------------------
//void AssetMetaData::removeKeyword(string keyword) {
//    keywords.erase (keywords.find(keyword));
//}
//
////--------------------------------------------------------------
//int AssetMetaData::getNumKeywords() {
//    return (int) keywords.size();
//}

//--------------------------------------------------------------
void AssetMetaData::setDescription(string _description) {
    description = _description;
}

//--------------------------------------------------------------
string AssetMetaData::getDescription() {
    return description;
}
