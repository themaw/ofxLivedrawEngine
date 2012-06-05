/*
 *  SourceManager.cpp
 *  livedraw
 *
 *  Created by Christopher P. Baker on 1/15/11.
 *  Copyright 2011 Murmur Labs LLC. All rights reserved.
 *
 */

#include "AssetManager.h"


bool isImageAsset  (MediaAsset* m) { return m->isImageAsset(); }
bool isGrabberAsset (MediaAsset* m) { return m->isGrabberAsset(); }
bool isVideoAsset  (MediaAsset* m) { return m->isVideoAsset(); }
bool isStreamAsset (MediaAsset* m) { return m->isStreamAsset(); }
bool isBufferAsset (MediaAsset* m) { return m->isBufferAsset(); }
bool isSyphonAsset (MediaAsset* m) { return m->isSyphonAsset(); }

//--------------------------------------------------------------
AssetManager::AssetManager() : ofxOscRouterNode("/assets")
{
    addOscNodeAlias("/a");
    addOscNodeAlias("/ass");
    
    addOscMethod("/alias"); // allows id aliasing
    addOscMethod("/buffer"); // allows id aliasing
    
    addOscMethod("/delete");
    
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
    
    cout << "processing-- " << pattern << endl;
    
    if(isMatch(pattern,"/alias")) {
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
    } else if(isMatch(pattern,"/buffer")) {
        cout << "doing buffer" << endl;
        
        if(validateOscSignature("s(is?)?", m)) {
            int numArgs = m.getNumArgs();
            if(numArgs == 1) {      
                string alias = m.getArgAsString(0);
                addBuffer(alias,new FrameBuffer(alias));
            } else if(numArgs == 2) {
                string alias = m.getArgAsString(0);
                int    size  = m.getArgAsInt32(1);
                addBuffer(alias,new FrameBuffer(alias,size));
            } else if(numArgs == 3) {
                string alias = m.getArgAsString(0);
                int    size  = m.getArgAsInt32(1);
                string type = m.getArgAsString(2);

                ofVideoBufferType t = OFX_VIDEO_BUFFER_FIXED;
                
                if(isMatch(type, "norm") || isMatch(type, "fixed") || isMatch(type, "default")) {
                    t = OFX_VIDEO_BUFFER_FIXED;
                } else if(isMatch(type, "ring") || isMatch(type, "circ") || isMatch(type, "cirular")) {
                    t = OFX_VIDEO_BUFFER_CIRCULAR;
                } else if(isMatch(type, "pass") || isMatch(type, "passthrough")) {
                    t = OFX_VIDEO_BUFFER_PASSTHROUGH;
                } else {
                    ofLog(OF_LOG_WARNING,"Unknown buffer type, using default.");
                }
                
                addBuffer(alias,new FrameBuffer(alias,size,t));
            } else {
                cout << "unknown num args." << endl;
            }
        }
                        
    } else if(isMatch(pattern,"/delete")) {
        cout << "in here" << endl;
        if(validateOscSignature("s", m)) {
            string alias = m.getArgAsString(0);
            bool ret = removeAsset(alias);
            if(!ret) {
                cout << "error deleting " << alias << endl; 
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
bool AssetManager::removeAsset(string alias) {
    MediaAsset* toDelete = getAsset(alias);
    
    if(toDelete == NULL) {
        ofLog(OF_LOG_WARNING, "AssetManager::removeAsset - unable to remove " + alias);
        return false;
    }

    if(toDelete->getAssetType() == MEDIA_ASSET_BUFFER) {
        FrameBuffer* buffer = toDelete->getBuffer();
        if(buffer == NULL) {
            cout << "ERROR, the attached buffer was null ..." << endl;
        } else {
            bool success = buffers.remove(buffer); // remove the buffer
            if(!success) {
                cout << "ERROR deleting the buffer" << endl;
            } else {
                toDelete->setBuffer(NULL); // clear buffer
                removeOscChild(buffer); // break osc link
                delete buffer;
            }
        }
    }
    vector<string> aliases = toDelete->getAliases();
    for(int i = 0; i < aliases.size(); i++) {
        assetAliases.erase(assetAliases.find(aliases[i]));
    }
    assets.remove(toDelete);
    return true;
    
}

//--------------------------------------------------------------
MediaAsset* AssetManager::addImage(string alias, string filename) {
    MediaAsset* asset = addAsset(MEDIA_ASSET_IMAGE, alias, filename);
}
//--------------------------------------------------------------
MediaAsset* AssetManager::addVideo(string alias, string filename) {
    MediaAsset* asset = addAsset(MEDIA_ASSET_VIDEO, alias, filename);
}
//--------------------------------------------------------------
MediaAsset* AssetManager::addStream(string alias, string url, string username, string password, string type) {
    // TODO: take care of username, password and type
    MediaAsset* asset = addAsset(MEDIA_ASSET_STREAM, alias, url);
}

//--------------------------------------------------------------
MediaAsset* AssetManager::addBuffer(string alias, FrameBuffer* buffer) {
    MediaAsset* asset = addAsset(MEDIA_ASSET_BUFFER, alias, "NULL");
    asset->setBuffer(buffer);
    buffers.add(buffer);
    addOscChild(buffer); // be sure to break this if deleted
}

//--------------------------------------------------------------
MediaAsset* AssetManager::addGrabber(string alias, string url) {
    MediaAsset* asset = addAsset(MEDIA_ASSET_GRABBER, alias, url);
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
		
        if(vidTypes.extract(name, 0, s) > 0) {
            addVideo(name,path);
        } else if(imgTypes.extract(name, 0, s) > 0) {
            addImage(name,path);
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
            addGrabber(name,ofToString(id));
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
            
            addStream(name,address,username,password,type);
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
int AssetManager::getNumBufferAssets() {
    return count_if(assets.begin(), assets.end(), isBufferAsset);
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