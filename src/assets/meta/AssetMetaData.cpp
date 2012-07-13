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
