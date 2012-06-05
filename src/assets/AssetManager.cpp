/*
 *  SourceManager.cpp
 *  livedraw
 *
 *  Created by Christopher P. Baker on 1/15/11.
 *  Copyright 2011 Murmur Labs LLC. All rights reserved.
 *
 */

#include "AssetManager.h"


bool isImageAsset (MediaAsset* m) { return m->isImageAsset(); }
bool isGrabberAsset (MediaAsset* m) { return m->isGrabberAsset(); }
bool isVideoAsset (MediaAsset* m) { return m->isVideoAsset(); }
bool isStreamAsset (MediaAsset* m) { return m->isStreamAsset(); }
bool isSyphonAsset (MediaAsset* m) { return m->isSyphonAsset(); }

//--------------------------------------------------------------
AssetManager::AssetManager() : ofxOscRouterNode("/assets")
{
    addOscNodeAlias("/a");
    addOscNodeAlias("/ass");
    
    addOscMethod("/alias"); // allows id aliasing
    
    loadAssets();
}

//--------------------------------------------------------------
AssetManager::~AssetManager() {
    ofLog(OF_LOG_NOTICE, "Destroying Asset Manager.");
}

//--------------------------------------------------------------
void AssetManager::update() {
    // TODO: add directory watchers?  or put those in another thread?
}

//--------------------------------------------------------------
void AssetManager::processOscMessage(string pattern, ofxOscMessage& m) {
    
    if(isMatch(pattern,"/alias")) {
        cout << "processing alias " << pattern <<  endl;
        if(validateOscSignature("ss", m)) {
            string existingAlias = m.getArgAsString(0);
            string additionalAlias = m.getArgAsString(1);
            MediaAsset * a = getAsset(existingAlias);
            if(a != NULL) {
                addAssetAlias(a,additionalAlias);
            } else {
                ofLog(OF_LOG_WARNING,"Attempted to set alias, but media asset did not exist.");
            }
        }
    }
}

//--------------------------------------------------------------
MediaAsset* AssetManager::addAsset(MediaAssetType _assetType, string _assetName, string _assetURI) {
    string assetId = "";
    if(generateAssetId(_assetType,_assetName,assetId)) {
        if(!hasId(assetId)) {
            MediaAsset* asset = new MediaAsset(_assetType,assetId,_assetURI);
            bool added = assets.add(asset);
            
            // TODO: do checkint here ...
            addAssetAlias(asset,assetId);    
            addAssetAlias(asset,_assetName); // two default asset names

            return asset;
        } else {
            ofLog(OF_LOG_WARNING, "AssetManager::addAsset alreadh has asset called : " + assetId);
            return NULL;
        }
    }
    return NULL;
}

//--------------------------------------------------------------
bool AssetManager::addAssetAlias(MediaAsset* asset, string alias) {
    asset->addAlias(alias);
    assetAliases[alias] = asset;
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
		
        cout << "name=" << name << endl;
        cout << "path=" << path << endl;
        
        if(vidTypes.extract(name, 0, s) > 0) {
            addAsset(MEDIA_ASSET_VIDEO,name,path);
        } else if(imgTypes.extract(name, 0, s) > 0) {
            addAsset(MEDIA_ASSET_IMAGE,name,path);
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
    // this is a total hack.  Should be:
    // vector<int> devIds = ofVideoGrabber:getDeviceList();
    // https://github.com/openframeworks/openFrameworks/issues/91
    // 
    
    ofxXmlSettings XML;
    
    if( XML.loadFile("media/grabbers.xml") ){
		
		XML.pushTag("grabbers");
		string tag = "grabber";
		
		int nStreams = XML.getNumTags(tag);
		
		for(int n = 0; n < nStreams; n++) {
			string name = XML.getAttribute(tag, "name", "unknown", n);
			int id = XML.getAttribute(tag, "id", 0, n);
            addAsset(MEDIA_ASSET_GRABBER, name, ofToString(id));
		}
		
		XML.popTag();
		
	} else {
		ofLog(OF_LOG_ERROR, "Unable to load media/streams.xml.");
	}
    
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
            // TODO: URL support for username / password, type
            
            addAsset(MEDIA_ASSET_STREAM,name,address);
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
    return count_if(assets.begin(), assets.end(), isImageAsset);
}
//--------------------------------------------------------------
int AssetManager::getNumGrabberAssets() {
    return count_if(assets.begin(), assets.end(), isGrabberAsset);
}
//--------------------------------------------------------------
int AssetManager::getNumVideoAssets() {
    return count_if(assets.begin(), assets.end(), isVideoAsset);
}
//--------------------------------------------------------------
int AssetManager::getNumStreamAssets() {
    return count_if(assets.begin(), assets.end(), isStreamAsset);
}
//--------------------------------------------------------------
int AssetManager::getNumSyphonAssets() {
    return count_if(assets.begin(), assets.end(), isSyphonAsset);
}

//--------------------------------------------------------------
bool AssetManager::hasId(string id) {
    return assetAliases.find(id) != assetAliases.end();
}

//--------------------------------------------------------------
MediaAsset* AssetManager::getAsset(string id) {
    map<string,MediaAsset*>::iterator iter = assetAliases.find(id);
    if(iter!=assetAliases.end()) {
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
        case MEDIA_ASSET_EMPTY:
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
        case MEDIA_ASSET_VIDEO:
            prefix = "video_";
            break;
        default:
            break;
    }
    
    filename = _assetURI;
    
    assetId = prefix + filename;
    
    return  true;
    

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