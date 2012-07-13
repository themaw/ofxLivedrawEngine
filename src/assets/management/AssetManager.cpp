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

#include "AssetManager.h"

string validMovieTypes = "[\\.](wm|wmv|asf|mov|qt|mp4|mpeg|mpg|mpe|m1v|mp2|mpv2|mod|vob|m1v|avi)";
string validImageTypes = "[\\.](jpg|jpeg|png|tiff|tif|gif|exr|ico|bmp|pict|psd|raw)";
string validOtherTypes = "[\\.](xml|txt)";

RegularExpression movieTypes(validMovieTypes,RegularExpression::RE_CASELESS);
RegularExpression imageTypes(validImageTypes,RegularExpression::RE_CASELESS);
RegularExpression otherTypes(validOtherTypes,RegularExpression::RE_CASELESS);

bool isUndefinedAsset(BaseMediaAsset* m)    { return m->getAssetType() == MEDIA_ASSET_UNDEFINED; }
bool isImageAsset(BaseMediaAsset* m)        { return m->getAssetType() == MEDIA_ASSET_IMAGE;     }
bool isGrabberAsset(BaseMediaAsset* m)      { return m->getAssetType() == MEDIA_ASSET_GRABBER;   }
bool isMovieAsset(BaseMediaAsset* m)        { return m->getAssetType() == MEDIA_ASSET_MOVIE;     }
bool isStreamAsset(BaseMediaAsset* m)       { return m->getAssetType() == MEDIA_ASSET_STREAM;    }
bool isBufferAsset(BaseMediaAsset* m)       { return m->getAssetType() == MEDIA_ASSET_BUFFER;    }
bool isBufferPlayerAsset(BaseMediaAsset* m) { return m->getAssetType() == MEDIA_ASSET_BUFFERPLAYER; }
bool isSyphonAsset(BaseMediaAsset* m)       { return m->getAssetType() == MEDIA_ASSET_SYPHON;    }

//--------------------------------------------------------------
AssetManager::AssetManager() : ofxOscRouterNode("/media") {
    
    // TODO: move some of these to their respective asset implementations
    
    addOscNodeAlias("/med");
    addOscNodeAlias("/m");
    
    // give an asset a new alias
    addOscMethod("/alias"); // allows id aliasing
    
    // delte an asset
    addOscMethod("/delete");
    
    // for disk data
    addOscMethod("/cache");
    addOscMethod("/uncache");
    
    // for live data (move to streaming type)
    addOscMethod("/start");
    addOscMethod("/stop");

    // utility
    addOscMethod("/dump");
    

    
    // buffer
    addOscMethod("/buffer");
    // buffer
    addOscMethod("/player");
    
    
    loadAssets();
}

//--------------------------------------------------------------
AssetManager::~AssetManager() {
    ofLog(OF_LOG_NOTICE, "Destroying Asset Manager.");
//    delete bufferManager;
}

//--------------------------------------------------------------
void AssetManager::update() {
    // TODO: add directory watchers?  or put those in another thread?
}

//--------------------------------------------------------------
bool AssetManager::attachSourceToSink(string sourceAlias, string sinkAlias) {
    return attachSourceToSink(getAsset(sourceAlias), getAsset(sinkAlias));
}

//--------------------------------------------------------------
bool AssetManager::attachSourceToSink(BaseMediaAsset* sourceAsset, BaseMediaAsset* sinkAlias) {
    
}

//--------------------------------------------------------------
void AssetManager::processOscMessage(const string& pattern, const ofxOscMessage& m) {

    if(isMatch(pattern,"/alias")) {
        if(validateOscSignature("ss", m)) {
            string existingAlias = m.getArgAsString(0);
            string additionalAlias = m.getArgAsString(1);
            BaseMediaAsset * a = getAsset(existingAlias);
            if(a != NULL) {
                addAlias(a,additionalAlias);
            } else {
                ofLog(OF_LOG_WARNING,"Attempted to set alias, but media asset did not exist.");
            }
        }
    } else if(isMatch(pattern,"/delete")) {
        if(validateOscSignature("s", m)) {
            string alias = m.getArgAsString(0);
            bool ret = unregisterAsset(alias);
            if(!ret) {
                cout << "error deleting " << alias << endl; 
            }
        }
    } else if(isMatch(pattern,"/start")) {
        string alias = m.getArgAsString(0);
        if(validateOscSignature("s", m)) {
            startAsset(alias);
        }
    } else if(isMatch(pattern,"/stop")) {
        string alias = m.getArgAsString(0);
        if(validateOscSignature("s", m)) {
            stopAsset(alias);
        }
    } else if(isMatch(pattern,"/dump")) {
        dump();
    } else if(isMatch(pattern, "/buffer")) {
        cout << "in buffer manager" << endl;
        
//        if(isMatch(pattern,"/new")) {
//            cout << "making new buffer" << endl;
//            
//            if(validateOscSignature("s(is?)?", m)) {
//                int numArgs = m.getNumArgs();
//                
//                if(numArgs > 0) {
//                    string alias = m.getArgAsString(0);
//                    int    size = 1;
//                    ofxVideoBufferType type = OFX_VIDEO_BUFFER_FIXED;
//                    
//                    if(numArgs > 1) size  = m.getArgAsInt32(1);
//                    if(numArgs > 2) {
//                        string type = m.getArgAsString(2);
//                        if(isMatch(type, "norm") || isMatch(type, "fixed") || isMatch(type, "default")) {
//                            type = OFX_VIDEO_BUFFER_FIXED;
//                        } else if(isMatch(type, "ring") || isMatch(type, "circ") || isMatch(type, "cirular")) {
//                            type = OFX_VIDEO_BUFFER_CIRCULAR;
//                        } else if(isMatch(type, "pass") || isMatch(type, "passthrough")) {
//                            type = OFX_VIDEO_BUFFER_PASSTHROUGH;
//                        } else {
//                            ofLog(OF_LOG_WARNING,"Unknown buffer type, using default.");
//                        }    
//                    }
//                    
//                    assetManager->addBuffer(alias, size, type);
//                    
//                } else {
//                    cout << "unknown num args." << endl;
//                }
//            }
//        } else if(isMatch(pattern,"/dump")) {
//            vector<FrameBuffer*> b = buffers.toArray();
//            cout << "dumping buffer" << endl;
//            for(int i = 0; i < b.size(); i++) {
//                cout << b[i]->toString() << endl;
//            }
//            
//        }

    } else if(isMatch(pattern, "/player")) {
        cout << "in player manager" << endl;
    }                      
                      
     
}

//--------------------------------------------------------------
bool AssetManager::registerAsset(BaseMediaAsset* asset) {
    // generate its uniqe id
    string assetId = generateAssetId(asset);

    // create a link to the asset manager
    //asset->setAssetManager(this);
    
    if(!addAlias(asset, assetId)) {
        ofLog(OF_LOG_ERROR, "AssetManager::registerAsset - failed to add asset alias");
        return false;
    }
    
    if(!addOscChild(asset)) {
        ofLog(OF_LOG_ERROR, "AssetManager::registerAsset - failed to add as an osc child node");
        return false;
    }

    if(!assets.add(asset)) {
        ofLog(OF_LOG_ERROR, "AssetManager::registerAsset - failed to add asset");
        return false;
    }

    return true;
}


//--------------------------------------------------------------
bool AssetManager::unregisterAsset(string alias) {
    BaseMediaAsset* toDelete = getAsset(alias);
    if(toDelete != NULL) {
        return unregisterAsset(toDelete);
    } else {
        return false;   
    }
}

//--------------------------------------------------------------
bool AssetManager::unregisterAsset(BaseMediaAsset* asset) {

    // is there a there there?
    if(asset == NULL) {
        ofLog(OF_LOG_WARNING, "AssetManager::unregisterAsset - asset is NULL ");
        return false;
    }
    
    // tell the object to dispose of itself (free connections, kill other things, etc)
    if(asset->dispose()) {
        ofLog(OF_LOG_WARNING, "AssetManager::unregisterAsset - unable to dispose " + asset->getName());
        return false;
    }
    
    if(!removeOscChild(asset)) {
        ofLog(OF_LOG_ERROR, "AssetManager::registerAsset - failed to remove as an osc child node");
        return false;
    }

    // get a list of the asset's aliases and remove them
    vector<string> aliases = getAliases(asset);
    for(int i = 0; i < aliases.size(); i++) {
        if(!removeAlias(aliases[i])) {
            ofLog(OF_LOG_WARNING, "AssetManager::unregisterAsset - unable to remove alias " + aliases[i] + " for " + asset->getName());
            return false;
        }
    }
    
    // remove the asset pointer from the assets set
    if(!assets.remove(asset)) {
        ofLog(OF_LOG_WARNING, "AssetManager::unregisterAsset - unable to remove asset " + asset->getName());
        return false;
    }
    
    // free the memory
    delete asset; // free the memory
    
    // success
    return true;
}

//--------------------------------------------------------------
bool AssetManager::cacheAsset(CacheableAsset* asset) {
    if(asset == NULL) {
        ofLog(OF_LOG_WARNING, "AssetManager::cacheAsset - Asset is NULL");
        return false;
    }
    
    BufferAsset* cacheAsset = addBuffer("BUFFER_" + asset->getName(), 1, OFX_VIDEO_BUFFER_FIXED);
    
    if(cacheAsset != NULL) {
        asset->setCacheBuffer(cacheAsset);
        return true;
    } else {
        ofLog(OF_LOG_WARNING, "AssetManager::cacheAsset - Only non-live assets can be cached");
        return false;
    }
}

//--------------------------------------------------------------
bool AssetManager::uncacheAsset(CacheableAsset* asset) {

    if(asset == NULL) {
        ofLog(OF_LOG_WARNING, "AssetManager::cacheAsset - Asset is NULL");
        return false;
    }

    unregisterAsset(asset);
    asset->setCacheBuffer(NULL);

    return true;

}

//--------------------------------------------------------------
bool AssetManager::startAsset(string alias) {
    BaseMediaAsset* asset = getAsset(alias);
    if(asset == NULL) {
        ofLog(OF_LOG_WARNING, "AssetManager::cacheAsset - Asset not found " + alias);
        return false;
    }

//    if(asset->isLiveAsset()) {
//        
//        cout << "starting cam." << endl;
//        
//        
//        
//    } else {
//        ofLog(OF_LOG_WARNING, "AssetManager::cacheAsset - Only live assets can be started " + alias);
//        return false;
//    }

}

//--------------------------------------------------------------
bool AssetManager::stopAsset(string alias) {
    BaseMediaAsset* asset = getAsset(alias);
    if(asset == NULL) {
        ofLog(OF_LOG_WARNING, "AssetManager::cacheAsset - Asset not found " + alias);
        return false;
    }
    
//    if(asset->isLiveAsset()) {
//        cout << "stopping cam." << endl;
//
//    } else {
//        ofLog(OF_LOG_WARNING, "AssetManager::cacheAsset - Only live assets can be stopped " + alias);
//        return false;
//    }

}

//--------------------------------------------------------------
ImageAsset* AssetManager::addImage(string name, string filename) {
   ImageAsset* asset = new ImageAsset(name, filename);
    
    if(!registerAsset(asset)) {
        ofLog(OF_LOG_ERROR, "AssetManager::addImage - failed to add image");
        unregisterAsset(asset);
        assert(asset == NULL);
        return asset;
    }

    return asset;
}

//--------------------------------------------------------------
MovieAsset* AssetManager::addMovie(string name, string filename) {
    MovieAsset* asset = new MovieAsset(name, filename);
    
    if(!registerAsset(asset)) {
        ofLog(OF_LOG_ERROR, "AssetManager::addImage - failed to add image");
        unregisterAsset(asset);
        assert(asset == NULL);
        return asset;
    }
    
    return asset;
}

//--------------------------------------------------------------
StreamAsset* AssetManager::addStream(string name, StreamType type, string url, string username, string password) {
    
    StreamAsset* asset = new StreamAsset(name, type, url, username, password);
    
    if(!registerAsset(asset)) {
        ofLog(OF_LOG_ERROR, "AssetManager::addImage - failed to add image");
        unregisterAsset(asset);
        assert(asset == NULL);
        return asset;
    }
    
    return asset;
}

//--------------------------------------------------------------
BufferAsset* AssetManager::addBuffer(string name, int size, ofxVideoBufferType t) {
    BufferAsset* asset = new BufferAsset(name, size, t);
    
    if(!registerAsset(asset)) {
        ofLog(OF_LOG_ERROR, "AssetManager::addBuffer - failed to add buffer");
        unregisterAsset(asset);
        assert(asset == NULL);
        return asset;
    }
    
    return asset;
}

//--------------------------------------------------------------
BufferPlayerAsset* AssetManager::addBufferPlayer(string name) {
    BufferPlayerAsset* asset = new BufferPlayerAsset(name);
    
    if(!registerAsset(asset)) {
        ofLog(OF_LOG_ERROR, "AssetManager::addBufferPlayer - failed to add buffer");
        unregisterAsset(asset);
        assert(asset == NULL);
        return asset;
    }
    
    return asset;
}

//--------------------------------------------------------------
GrabberAsset* AssetManager::addGrabber(string name, int devId, int width, int height) {
    GrabberAsset* asset = new GrabberAsset(name, devId, width, height);
    
    if(!registerAsset(asset)) {
        ofLog(OF_LOG_ERROR, "AssetManager::addGrabber - failed to add buffer");
        unregisterAsset(asset);
        assert(asset == NULL);
        return asset;
    }
    
    return asset;
}

//--------------------------------------------------------------
SyphonAsset* AssetManager::addSyphon(string name) {
    return NULL;
}

//--------------------------------------------------------------
bool AssetManager::hasAlias(string alias) {
    return assetAliases.find(alias) != assetAliases.end();
}

//--------------------------------------------------------------
bool AssetManager::addAlias(BaseMediaAsset* asset, string alias) {
    if(!hasAlias(alias)) {
        assetAliases[alias] = asset;
        asset->addOscNodeAlias("/"+alias); // add the osc node alias
        return true;
    } else {
        ofLog(OF_LOG_WARNING, "AssetManager::addAlias - failed to add alias because it already exists.");
        return false;
    }
} 

//--------------------------------------------------------------
bool AssetManager::removeAlias(string alias) {
    
    BaseMediaAsset* asset = getAsset(alias);
    if(asset == NULL) return false;
    
    vector<string> aliases = getAliases(asset);
    
    if(aliases.size() > 1) {
        assetAliases.erase(alias); // remove the alias
        asset->removeOscNodeAlias("/"+alias); // remove the node alias
        return true;
    } else if(aliases.size() == 0) {
        ofLog(OF_LOG_ERROR, "AssetManager::removeAlias - found an asset with no aliases.  This is a problem.");
        return false;
    } else {
        ofLog(OF_LOG_WARNING, "AssetManager::removeAlias - failed to remove alias because it was the last one for that asset.");
        return false;
    }
}

////--------------------------------------------------------------
//bool AssetManager::changeAlias(string fromAlias, string toAlias) {
//    
//    if(hasAlias(toAlias)) {
//        ofLog(OF_LOG_ERROR, "AssetManager::changeAlias - target alias already exists");
//        return false;
//    }
//    
//    map<string,BaseMediaAsset*>::iterator iter = assetAliases.find(fromAlias);
//    
//    if(iter!=assetAliases.end()) {
//        std::swap(assetAliases[toAlias], iter->second);
//        assetAliases.erase(iter);
//        return true;
//    } else {
//        ofLog(OF_LOG_ERROR, "AssetManager::changeAlias - fromAlias does not exist");
//        return false;
//    }
//    
//}

//--------------------------------------------------------------
vector<string> AssetManager::getAliases(BaseMediaAsset* asset) {
    vector<string> aliases;
    
    map<string,BaseMediaAsset*>::iterator iter = assetAliases.begin();
    
    for(; iter != assetAliases.end(); iter++) {
        if(iter->second == asset) aliases.push_back(iter->first);
    }
    
    return aliases;
}

//--------------------------------------------------------------
void AssetManager::loadAssets() {
	loadFilesAssets();
    loadGrabberAssets();
    loadStreamAssets();
    loadSyphonAssets();
}

//--------------------------------------------------------------
void AssetManager::loadFilesAssets() {

	int nFiles = dir.listDir("media/");
    
    string s;
    
	for (int i = 0; i < nFiles; i++) {
		// create video sources
		
		string name = dir.getName(i);
		string path = dir.getPath(i);
		
        if(movieTypes.extract(name, 0, s) > 0) {
            if(addMovie(name, path) == NULL) {
                ofLog(OF_LOG_WARNING, "AssetManager::loadFilesAssets() - Could not load :  " + path);
            }
        } else if(imageTypes.extract(name, 0, s) > 0) {
            if(addImage(name, path) == NULL) {
                ofLog(OF_LOG_WARNING, "AssetManager::loadFilesAssets() - Could not load :  " + path);
            }
        } else if(otherTypes.extract(name, 0, s)) {
            // ofLog(OF_LOG_WARNING, "AssetManager::loadFilesAssets() - other valid non-media " + path); 
        } else {
            ofLog(OF_LOG_WARNING, "AssetManager::loadFilesAssets() - Unknown file type :  " + path);
        }
	}
    
    ofLog(OF_LOG_NOTICE, "Loaded " + ofToString(getNumAssets(MEDIA_ASSET_IMAGE)) + " images.");
    ofLog(OF_LOG_NOTICE, "Loaded " + ofToString(getNumAssets(MEDIA_ASSET_MOVIE)) + " movies.");	
}

//--------------------------------------------------------------
void AssetManager::loadSyphonAssets() {
    ofLog(OF_LOG_NOTICE, "Loaded " + ofToString(getNumAssets(MEDIA_ASSET_SYPHON)) + " syphon sources.");	
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
			string name = XML.getAttribute(tag, "name", "NO_NAME", n);
			int id = XML.getAttribute(tag, "id", 0, n);
            int width = XML.getAttribute(tag, "width",   320, n);
            int height = XML.getAttribute(tag, "height", 240, n);
            
            if(addGrabber(name,id,width,height) == NULL) {
                ofLog(OF_LOG_WARNING, "AssetManager::loadFilesAssets() - Could not load grabber :  " + name );
            }
		}
		
		XML.popTag();
		
	} else {
		ofLog(OF_LOG_ERROR, "Unable to load media/streams.xml.");
	}
    
    ofLog(OF_LOG_NOTICE, "Loaded " + ofToString(getNumAssets(MEDIA_ASSET_GRABBER)) + " grabbers.");
}


//--------------------------------------------------------------
void AssetManager::loadStreamAssets(){
	ofxXmlSettings XML;

	if( XML.loadFile("media/streams.xml") ){
		
		XML.pushTag("streams");
		string tag = "stream";
		
		int nStreams = XML.getNumTags(tag);
		
		for(int n = 0; n < nStreams; n++) {
			string name = XML.getAttribute(tag, "name", "", n);
			string address = XML.getAttribute(tag, "address", "", n);
			string username = XML.getAttribute(tag, "username", "", n); 
			string password = XML.getAttribute(tag, "password", "", n); 
			string type     = XML.getAttribute(tag,"type","",n);

            if(name.empty()) {
                ofLog(OF_LOG_WARNING, "AssetManager::loadFilesAssets() - Could not load stream - empty name.");
                continue;
            }

            if(address.empty()) {
                ofLog(OF_LOG_WARNING, "AssetManager::loadFilesAssets() - Could not load stream - empty address.");
                continue;
            }
            
            if(type.empty()) {
                ofLog(OF_LOG_WARNING, "AssetManager::loadFilesAssets() - Could not load stream " + address + " type not specified.");
                continue;
            }
            
            StreamType streamType;
            
            if(Poco::icompare(type, "ipcam") == 0) {
                streamType = STREAM_TYPE_IPCAM;
            } else if(Poco::icompare(type, "rtsp") == 0) {
                streamType = STREAM_TYPE_RTSP;
            } else if(Poco::icompare(type, "qt") == 0) {
                streamType = STREAM_TYPE_QT;
            } else {
                ofLog(OF_LOG_WARNING, "AssetManager::loadFilesAssets() - Could not load stream " + address + " type " + type + " unknown.");
                continue;
            }
            
            // TODO DIFFERENTIATE BETWEEN RTSP, QT HTTP, IPCAM, ETC
//            string logMessage = "STREAM LOADED: " + name + 
//			" address: " +  address + 
//			" username: " + username + 
//			" password: " + password;
            // TODO: URL support for username / password, type
            
            if(addStream(name, streamType, address,username,password) == NULL) {
                ofLog(OF_LOG_WARNING, "AssetManager::loadFilesAssets() - Could not load stream :  " + address);
            }

		}
		
		XML.popTag();
		
	} else {
		ofLog(OF_LOG_ERROR, "Unable to load media/streams.xml.");
	}

    ofLog(OF_LOG_NOTICE, "Loaded " + ofToString(getNumAssets(MEDIA_ASSET_STREAM)) + " streams.");

}

//--------------------------------------------------------------
int AssetManager::getNumAssets() {
    return assets.size();
}

//--------------------------------------------------------------
int AssetManager::getNumAssets(MediaAssetType assetType) {
    switch (assetType) {
        case MEDIA_ASSET_UNDEFINED:
            return count_if(assets.begin(), assets.end(), isUndefinedAsset);
        case MEDIA_ASSET_IMAGE:
            return count_if(assets.begin(), assets.end(), isImageAsset);
        case MEDIA_ASSET_MOVIE:
            return count_if(assets.begin(), assets.end(), isMovieAsset);
        case MEDIA_ASSET_GRABBER:
            return count_if(assets.begin(), assets.end(), isGrabberAsset);
        case MEDIA_ASSET_STREAM:
            return count_if(assets.begin(), assets.end(), isStreamAsset);
        case MEDIA_ASSET_BUFFER:
            return count_if(assets.begin(), assets.end(), isBufferAsset);
        case MEDIA_ASSET_BUFFERPLAYER:
            return count_if(assets.begin(), assets.end(), isBufferPlayerAsset);
        case MEDIA_ASSET_SYPHON:
            return count_if(assets.begin(), assets.end(), isSyphonAsset);
        default:
            ofLog(OF_LOG_ERROR, "AssetManager::getNumAssets() - unknwon asset type " + ofToString(assetType));
            return -1;
    }
}

//--------------------------------------------------------------
BaseMediaAsset* AssetManager::getAsset(string alias) {
    map<string,BaseMediaAsset*>::iterator iter = assetAliases.find(alias);
    
    if(iter!=assetAliases.end()) {
        return iter->second;
    } else {
        return NULL;
    }
}

void AssetManager::dump() {
    vector<BaseMediaAsset*> vec = assets.toArray();
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i]->toString() << endl;
    }
        
//        std::map<string,MediaAsset*>::iterator iter;
//        
//        for (iter = assetAliases.begin(); iter != assetAliases.end(); ++iter) {
//            cout << iter->first << "=>";
//            cout << iter->second->getAssetId() << endl;
//        }
}


//--------------------------------------------------------------
string AssetManager::generateAssetId(BaseMediaAsset* asset) {
    string assetId = asset->getName();

    string normalizedAssetId = normalizeMethodName(assetId);
    
    if(icompare(assetId, normalizedAssetId) != 0) {
        ofLog(OF_LOG_ERROR, "AssetManager::generateAssetId() - changed name from " + assetId + " to " + normalizedAssetId);
    }
    
    // this is very unlikely to happen
    while(hasAlias(assetId)) {
        assetId = assetId + "_" + ofToString((int)ofGetElapsedTimeMillis());
    }
    
    return assetId;
}

//--------------------------------------------------------------
//--------------------------------------------------------------
//--------------------------------------------------------------
//--------------------------------------------------------------