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
    string assetId = "";
    if(generateAssetId(_assetType,_assetURI,assetId)) {
        
        if(hasId(assetId)) {
            MediaAsset* asset = new MediaAsset(_assetType,assetId,_assetURI);
            assets[assetId] = asset;
            return asset;
        } else {
            ofLog(OF_LOG_WARNING, "AssetManager::addAsset alreadh has asset called : " + assetId);
            return NULL;
        }
    }
    return NULL;
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
    map<string,MediaAsset*>::iterator iter = assets.begin();
    while(iter != assets.end()) {
        if(iter->second->isImageAsset()) cnt++;
        iter++;
    }
    return cnt;
}
//--------------------------------------------------------------
int AssetManager::getNumGrabberAssets() {
    int cnt = 0;
    map<string,MediaAsset*>::iterator iter = assets.begin();
    while(iter != assets.end()) {
        if(iter->second->isGrabberAsset()) cnt++;
        iter++;
    }
    return cnt;
}
//--------------------------------------------------------------
int AssetManager::getNumVideoAssets() {
    int cnt = 0;
    map<string,MediaAsset*>::iterator iter = assets.begin();
    while(iter != assets.end()) {
        if(iter->second->isVideoAsset()) cnt++;
        iter++;
    }
    return cnt;   
}
//--------------------------------------------------------------
int AssetManager::getNumStreamAssets() {
    int cnt = 0;
    map<string,MediaAsset*>::iterator iter = assets.begin();
    while(iter != assets.end()) {
        if(iter->second->isStreamAsset()) cnt++;
        iter++;
    }
    return cnt;
}
//--------------------------------------------------------------
int AssetManager::getNumSyphonAssets() {
    int cnt = 0;
    map<string,MediaAsset*>::iterator iter = assets.begin();
    while(iter != assets.end()) {
        if(iter->second->isSyphonAsset()) cnt++;
        iter++;
    }
    return cnt;
}

//--------------------------------------------------------------
bool AssetManager::hasId(string id) {
    return assets.find(id) != assets.end();
}


//--------------------------------------------------------------
MediaAsset* AssetManager::getAsset(string id) {
    map<string,MediaAsset*>::iterator iter = assets.find(id);
    if(iter!=assets.end()) {
        return iter->second;
    } else {
        return NULL;
    }
}

//--------------------------------------------------------------
bool AssetManager::generateAssetId(MediaAssetType _assetType, string _assetURI, string& assetId) {
    
    string id;
    string prefix = "";
    string filename = "";
    
    
    switch (_assetType) {
        case MEDIA_ASSET_UNKNOWN:
            return false;
            break;
        case MEDIA_ASSET_IMAGE:
            prefix = "image_";
            break;
        case MEDIA_ASSET_GRABBER:
            prefix = "grabber_";
            break;
        case MEDIA_ASSET_STREAM:
            prefix = "stream_";
            break;
        case MEDIA_ASSET_BUFFER:
            prefix = "buffer_";
            break;
        case MEDIA_ASSET_SYPHON:
            prefix = "syphon_";
            break;
        default:
            break;
    }
    
    filename = _assetURI;
    
    id = prefix + filename;
    
    

    /*
    Animated Robot[22].mov    >>>   file_Animated-Robot-22-.mov
    USB camera #2             >>>   grabber_2 (use OpenFrameworks/QuickTime indexing)
    syphon source "tex69"     >>>   syphon_tex69
    IP camera named "ipcam3"  >>>   stream_ipcam3 (use source name from streams.xml file)
    Recording Buffers         >>>   buffer_name_of_buffer
    Buffer Player             >>>   bufferplayer_name_of_buffer_player
    */
    
    
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