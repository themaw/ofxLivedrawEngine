/*
 *  SourceManager.cpp
 *  livedraw
 *
 *  Created by Christopher P. Baker on 1/15/11.
 *  Copyright 2011 Murmur Labs LLC. All rights reserved.
 *
 */

#include "AssetManager.h"

//--------------------------------------------------------------
AssetManager::AssetManager() : ofxOscRouterNode("/assets")
{
    addOscMethod("alias"); // allows id changes
}

//--------------------------------------------------------------
AssetManager::~AssetManager() {
    ofLog(OF_LOG_NOTICE, "Destroying Asset Manager.");

}

//--------------------------------------------------------------
void AssetManager::setup() {
    loadAssets();
}

//--------------------------------------------------------------
void AssetManager::update() {
    // TODO: add directory watchers?  or put those in another thread?
}

//--------------------------------------------------------------
void AssetManager::processOscMessage(string pattern, ofxOscMessage& m) {
    cout << "OSC MESSAGE FOR THE ASSET MANAGER " << endl;
}

//--------------------------------------------------------------
MediaAsset* AssetManager::addAsset(MediaAssetType _assetType, string _assetURI) {
    string assetId = generateAssetId(_assetType,_assetURI);
    MediaAsset* asset = new MediaAsset(_assetType,assetId,_assetURI);
    assets.push_back(asset);
}

//--------------------------------------------------------------
void AssetManager::loadAssets() {
	loadFilesAssets();
    loadGrabberAssets();
    loadStreamAssets();
    loadSyphonAssets();
}
//
//--------------------------------------------------------------
void AssetManager::loadFilesAssets()
{
	int nFiles = dir.listDir("media/");
    
    // lower case
    string validVideoTypes = "[\\.](wm|wmv|asf|mov|qt|mp4|mpeg|mpg|mpe|m1v|mp2|mpv2|mod|vob|m1v|avi)";
    string validImageTypes = "[\\.](jpg|jpeg|png|tiff|tif|gif|exr|ico|bmp|pict|psd|raw)";
    string validOtherTypes = "[\\.](xml|txt)";

    RegularExpression vidTypes(validVideoTypes,RegularExpression::RE_CASELESS);
    RegularExpression imgTypes(validImageTypes,RegularExpression::RE_CASELESS);
    RegularExpression otherTypes(validOtherTypes,RegularExpression::RE_CASELESS);
    
    string s;
    
	for (int i = 0; i < nFiles; i++) {
		// create video sources
		
		string name = dir.getName(i);
		string path = dir.getPath(i);
		
        if(vidTypes.extract(name, 0, s) > 0) {
            addAsset(MEDIA_ASSET_VIDEO,path);
        } else if(imgTypes.extract(name, 0, s) > 0) {
            addAsset(MEDIA_ASSET_IMAGE,path);
        } else if(otherTypes.extract(name, 0, s)) {
            //ofLog(OF_LOG_WARNING, "AssetManager::loadFilesAssets() - other valid non-media " + path); 
        } else {
            ofLog(OF_LOG_WARNING, "AssetManager::loadFilesAssets() - Unknown file type :  " + path);
        }
        
		

	}
    
    ofLog(OF_LOG_NOTICE, "Loaded " + ofToString(getNumImageAssets()) + " images.");
    ofLog(OF_LOG_NOTICE, "Loaded " + ofToString(getNumVideoAssets()) + " videos.");	
}

//--------------------------------------------------------------
void AssetManager::loadSyphonAssets() {
    ofLog(OF_LOG_NOTICE, "Loaded " + ofToString(getNumSyphonAssets()) + " syphon sources.");	
}

//--------------------------------------------------------------
void AssetManager::loadGrabberAssets() {
    // TODO: no way to get a vector of names?
    ofVideoGrabber grabber;
    grabber.listDevices();
    ofLog(OF_LOG_NOTICE, "Loaded " + ofToString(getNumGrabberAssets()) + " grabbers.");
}


//--------------------------------------------------------------
void AssetManager::loadStreamAssets(){
	ofxXmlSettings XML;

	if( XML.loadFile("media/streams.xml") ){
		
		XML.pushTag("streams");
		string tag = "stream";
		
		int nStreams = XML.getNumTags(tag);
		
		for(int n = 0; n < nStreams; n++) {
			string name = XML.getAttribute(tag, "name", "unknown", n);
			string address = XML.getAttribute(tag, "address", "NULL", n);
			string username = XML.getAttribute(tag, "username", "NULL", n); 
			string password = XML.getAttribute(tag, "password", "NULL", n); 
			string type     = XML.getAttribute(tag,"type","NULL",n);

            // TODO DIFFERENTIATE BETWEEN RTSP, QT HTTP, IPCAM, ETC
//            string logMessage = "STREAM LOADED: " + name + 
//			" address: " +  address + 
//			" username: " + username + 
//			" password: " + password;
            addAsset(MEDIA_ASSET_STREAM,address);
		}
		
		XML.popTag();
		
	} else {
		ofLog(OF_LOG_ERROR, "Unable to load media/streams.xml.");
	}

    ofLog(OF_LOG_NOTICE, "Loaded " + ofToString(getNumStreamAssets()) + " streams.");

}





int AssetManager::getNumAssets() {return assets.size();}

//--------------------------------------------------------------
int AssetManager::getNumImageAssets() {
    int cnt = 0;
    for(int i = 0; i < assets.size(); i++) if(assets[i]->isImageAsset()) cnt++;
    return cnt;
}
//--------------------------------------------------------------
int AssetManager::getNumGrabberAssets() {
    int cnt = 0;
    for(int i = 0; i < assets.size(); i++) if(assets[i]->isGrabberAsset()) cnt++;
    return cnt;
}
//--------------------------------------------------------------
int AssetManager::getNumVideoAssets() {
    int cnt = 0;
    for(int i = 0; i < assets.size(); i++) if(assets[i]->isVideoAsset()) cnt++;
    return cnt;   
}
//--------------------------------------------------------------
int AssetManager::getNumStreamAssets() {
    int cnt = 0;
    for(int i = 0; i < assets.size(); i++) if(assets[i]->isStreamAsset()) cnt++;
    return cnt;
}
//--------------------------------------------------------------
int AssetManager::getNumSyphonAssets() {
    int cnt = 0;
    for(int i = 0; i < assets.size(); i++) if(assets[i]->isSyphonAsset()) cnt++;
    return cnt;
}

//--------------------------------------------------------------
bool AssetManager::hasId(string id) {
    for(int i  = 0; i < assets.size(); i++) {
        if(id.compare(assets[i]->getAssetId()) == 0) return true;
    }
    return false;
}


//--------------------------------------------------------------
MediaAsset* AssetManager::getAsset(string id) {
    for(int i  = 0; i < assets.size(); i++) {
        if(id.compare(assets[i]->getAssetId()) == 0) return assets[i];
    }
    return NULL;
}

//--------------------------------------------------------------
string AssetManager::generateAssetId(MediaAssetType _assetType, string _assetURI) {
    /*
	if(assetID.empty()) {
		assetID = assetURI.toString();
		return true;
	} else{
		ofLog(OF_LOG_WARNING, "Asset ID already set to " + assetID);
		return false;	
	}*/
}

//--------------------------------------------------------------
//--------------------------------------------------------------
//--------------------------------------------------------------
//--------------------------------------------------------------