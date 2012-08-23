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
bool isPlayerAsset(BaseMediaAsset* m)       { return m->getAssetType() == MEDIA_ASSET_PLAYER;    }
bool isSyphonAsset(BaseMediaAsset* m)       { return m->getAssetType() == MEDIA_ASSET_SYPHON;    }


ImageAsset*   toImageAsset(BaseMediaAsset* asset)   { return dynamic_cast<ImageAsset*>(asset);   }
MovieAsset*   toMovieAsset(BaseMediaAsset* asset)   { return dynamic_cast<MovieAsset*>(asset);   }
BufferAsset*  toBufferAsset(BaseMediaAsset* asset)  { return dynamic_cast<BufferAsset*>(asset);  }
PlayerAsset*  toPlayerAsset(BaseMediaAsset* asset)  { return dynamic_cast<PlayerAsset*>(asset);  }
PlayableAsset*  toPlayableAsset(BaseMediaAsset* asset)  { return dynamic_cast<PlayableAsset*>(asset);  }
CacheableAsset*  toCacheableAsset(BaseMediaAsset* asset)  { return dynamic_cast<CacheableAsset*>(asset);  }
GrabberAsset* toGrabberAsset(BaseMediaAsset* asset) { return dynamic_cast<GrabberAsset*>(asset); }
StreamAsset*  toStreamAsset(BaseMediaAsset* asset)  { return dynamic_cast<StreamAsset*>(asset);  }
SyphonAsset*  toSyphonAsset(BaseMediaAsset* asset)  { return dynamic_cast<SyphonAsset*>(asset);  }


//--------------------------------------------------------------
AssetManager::AssetManager() : ofxOscRouterNode("media") {

    
    engine = NULL;
    
    // TODO: move some of these to their respective asset implementations
    
    addOscNodeAlias("med");
    addOscNodeAlias("m");
    
//    // give an asset a new alias
//    addOscMethod("alias"); // allows id aliasing
//    
//    // delte an asset
//    addOscMethod("delete");
//    
//    // for disk data
//    addOscMethod("cache");
//    addOscMethod("uncache");
//    
//    // for live data (move to streaming type)
//    addOscMethod("start");
//    addOscMethod("stop");
//
//    // utility
    addOscMethod("dump");
//    
//
//    
//    // buffer
//    addOscMethod("buffer");
//    // buffer
//    addOscMethod("player");
    
    
    loadAssets();
}

//--------------------------------------------------------------
AssetManager::~AssetManager() {
    ofLogNotice("AssetManager") << "Destroying Asset Manager.";
}

//--------------------------------------------------------------
void AssetManager::update() {
    
    // process all de/registration queues
    processQueues();

    // update assets
    updateAssets();
    
}

//--------------------------------------------------------------
void AssetManager::processOscCommand(const string& command, const ofxOscMessage& m) {
    
    if(isMatch(command,"new")) {
        // /livedraw/media/new player NAME
        // /livedraw/media/new buffer NAME [SIZE [TYPE]]
        if(validateOscSignature("ss(is?)?", m)) {
            string assetType = getArgAsStringUnchecked(m,0);
            string name = getArgAsStringUnchecked(m,1);

            if(isMatch(assetType,"buffer") || isMatch(assetType,"buf")) {
                int size = 1;
                ofxVideoBufferType type = OFX_VIDEO_BUFFER_FIXED;

                if(m.getNumArgs() > 2) {
                    size  = getArgAsIntUnchecked(m,2);
                    if(size < 0) {
                        ofLog(OF_LOG_WARNING,"Invalid buffer size, using default.");
                        size = 1;
                    }
                }
                
                if(m.getNumArgs() > 3) {
                    string bufTypStr = getArgAsStringUnchecked(m,3);
                    if(isMatch(bufTypStr, "norm") || isMatch(bufTypStr, "fixed") || isMatch(bufTypStr, "default")) {
                        type = OFX_VIDEO_BUFFER_FIXED;
                    } else if(isMatch(bufTypStr, "ring") || isMatch(bufTypStr, "circ") || isMatch(bufTypStr, "circular")) {
                        type = OFX_VIDEO_BUFFER_CIRCULAR;
                    } else if(isMatch(bufTypStr, "pass") || isMatch(bufTypStr, "passthrough")) {
                        type = OFX_VIDEO_BUFFER_PASSTHROUGH;
                    } else {
                        ofLog(OF_LOG_WARNING,"Unknown buffer type, using default.");
                    }
                }

                addBuffer(name, size, type);
                
            } else if(isMatch(assetType,"player") || isMatch(assetType,"play")) {

                addPlayer(name);
            
            } else {
                ofLog(OF_LOG_ERROR,"Unknown asset type " + assetType + " returning.");
            }
        }
        
    } else if(isMatch(command,"delete")) {
        if(validateOscSignature("s", m)) {
            string alias = getArgAsStringUnchecked(m,0);
            bool ret = queueUnregisterAsset(alias);
            if(!ret) {
                cout << "error deleting " << alias << endl; 
            }
        }
    } else if(isMatch(command,"start")) {
        string alias = getArgAsStringUnchecked(m,0);
        if(validateOscSignature("s", m)) {
            startAsset(alias);
        }
    } else if(isMatch(command,"stop")) {
        string alias = getArgAsStringUnchecked(m,0);
        if(validateOscSignature("s", m)) {
            stopAsset(alias);
        }
    } else if(isMatch(command,"dump")) {
        dump();
    } else if(isMatch(command, "buffer")) {
        cout << "in buffer manager" << endl;
        
    } else if(isMatch(command,"player")) {
        cout << "in player manager" << endl;
    }                      
}

//--------------------------------------------------------------
ofxVideoSourceInterface* AssetManager::getSourceAsset(const string& alias) const {
    BaseMediaAsset* sourceAsset = getAsset(alias);

    if(sourceAsset == NULL) {
        ofLogError("AssetManager") << "getSourceAsset: " << alias << " is not the name of a known asset.";
        return NULL;
    }

    if(!sourceAsset->isSource()) {
        ofLogError("AssetManager") << "getSourceAsset: " << sourceAsset->getName() << " is not a source.";
        return false;
    }

    ofxVideoSourceInterface* source = dynamic_cast<ofxVideoSourceInterface*>(sourceAsset);
    if(source == NULL) {
        ofLogError("AssetManager") << "getSourceAsset: " << sourceAsset->getName() + " could not be cast to source.";
        return false;
    }

    return source;
}

//--------------------------------------------------------------
ofxVideoSinkInterface* AssetManager::getSinkAsset(const string& alias) const {
    BaseMediaAsset* sinkAsset = getAsset(alias);
    
    if(sinkAsset == NULL) {
        ofLogError("AssetManager") << "getSinkAsset: " << alias << " is not the name of a known asset.";
        return NULL;
    }
    
    if(!sinkAsset->isSink()) {
        ofLogError("AssetManager") << "getSinkAsset: " << sinkAsset->getName() << " is not a source.";
        return false;
    }
    
    ofxVideoSinkInterface* sink = dynamic_cast<ofxVideoSinkInterface*>(sinkAsset);
    if(sink == NULL) {
        ofLogError("AssetManager") << "getSinkAsset: " << sinkAsset->getName() + " could not be cast to source.";
        return false;
    }
    
    return sink;
}

void AssetManager::attachSourceToSink(const string& sourceAlias, const string& sinkAlias) {
    ofxVideoSourceInterface* source = getSourceAsset(sourceAlias);
    ofxVideoSinkInterface*   sink = getSinkAsset(sinkAlias);

    if(source != NULL && sink != NULL) {
        source->attachToSink(sink);
    }
}

//--------------------------------------------------------------
bool AssetManager::queueUnregisterAsset(const string& alias) {
    BaseMediaAsset* toDelete = getAsset(alias);
    if(toDelete != NULL) {
        return queueUnregisterAsset(toDelete);
    } else {
        return false;   
    }
}

//--------------------------------------------------------------
bool AssetManager::queueUnregisterAsset(BaseMediaAsset* asset) {
    asset->setNodeActive(false);
    return unregisterQueue.insert(asset).second;
}

//--------------------------------------------------------------
bool AssetManager::registerAsset(BaseMediaAsset* asset) {
    
    if(!hasAlias(asset->getName())) { // double check
        assetAliases[asset->getName()] = asset;
    } else {
        ofLogError("AssetManager") << "registerAsset - alias already exists";
        return false;
    }
    
    if(!addOscChild(asset)) {
        ofLogError("AssetManager") << "registerAsset - failed to add as an osc child node";
        return false;
    }

    // turn it on
    asset->setNodeActive(true);

    // add it to our collection
    assets.insert(asset);
    
//    // special procedures
//    if(isMovieAsset(asset)) {
//        toMovieAsset(asset)->setCacheProvider(this);
//    }
//
    return true;
}

//--------------------------------------------------------------
bool AssetManager::unregisterAsset(BaseMediaAsset* asset) {

    ofLogVerbose("AssetManager") << "unregisterAsset: " << asset->getName();
    
    // is there a there there?
    if(asset == NULL) {
        ofLogWarning("AssetManager") << "unregisterAsset: asset is NULL ";
        return false;
    }
    
    cout << "0. unregistering asset " << asset->getName() << endl;

    // tell the object to dispose of itself (free connections, kill other things, etc)
    if(!asset->dispose()) {
        ofLogWarning("AssetManager") << "unregisterAsset: unable to dispose " << asset->getName();
        return false;
    }

    // get rid of the alias
    if(hasAlias(asset->getName())) { // double check
        assetAliases.erase(asset->getName());
    }
    
    if(hasOscChild(asset) && !removeOscChild(asset)) {
        ofLogError("AssetManager") << "registerAsset: failed to remove as an osc child node";
        return false;
    }
    
    // remove the asset pointer from the assets set
    assets.erase(asset);
    
    // free the memory
    delete asset; // free the memory
    asset = NULL;
    // success
    
    return true;
}

//--------------------------------------------------------------
void AssetManager::cacheAsset(CacheableAsset* asset) {
    if(asset == NULL) {
        ofLogWarning("AssetManager") << "cacheAsset: - Asset is NULL";
        return;
    }
    
    if(asset->isCached()) {
        ofLogWarning("AssetManager") << "cacheAsset: Asset is already cached.";
        return;
    }
    
    BufferAsset* cacheAsset = addBuffer("BUFFER_" + asset->getName(), 1, OFX_VIDEO_BUFFER_FIXED);
    
    if(cacheAsset != NULL) {
        cacheAsset->loadMovie(asset->getFilename());
        asset->setCacheBuffer(cacheAsset);
        assetsBeingCached.insert(asset);
        return;
    } else {
        ofLogWarning("AssetManager") << "cacheAsset: could not create buffer.";
        return;
    }
}


//--------------------------------------------------------------
void AssetManager::uncacheAsset(CacheableAsset* asset) {

    if(asset == NULL) {
        ofLogError("AssetManager") << "uncacheAsset: Asset is NULL";
        return;
    }

    if(!asset->isCached()) {
        ofLogError("AssetManager") << "uncacheAsset: Asset has no cache.";
        return;
    }
    
    if(!queueUnregisterAsset(asset->getCacheBuffer())) {
        ofLogError("AssetManager") << "uncacheAsset: Unable to uncache buffer.";
        return;
    } else {
        asset->setCacheBuffer(NULL);
        return;
    }
}

//--------------------------------------------------------------
bool AssetManager::startAsset(const string& alias) {
    BaseMediaAsset* asset = getAsset(alias);
    if(asset == NULL) {
        ofLogWarning("AssetManager") << "startAsset: Asset not found " << alias;
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
bool AssetManager::stopAsset(const string& alias) {
    BaseMediaAsset* asset = getAsset(alias);
    if(asset == NULL) {
        ofLogWarning("AssetManager") << "stopAsset: Asset not found " << alias;
        return false;
    }
}

//--------------------------------------------------------------
ImageAsset* AssetManager::addImage(const string& name, const string& filename) {
    ImageAsset* asset = new ImageAsset(this, validateAssetId(name), filename);
    registerAsset(asset);
    return asset;
}

//--------------------------------------------------------------
MovieAsset* AssetManager::addMovie(const string& name, const string& filename) {
    MovieAsset* asset = new MovieAsset(this, validateAssetId(name), filename);
    registerAsset(asset);
    return asset;
}

//--------------------------------------------------------------
StreamAsset* AssetManager::addStream(const string& name, StreamType type, const string& url, const string& username, const string& password) {
    StreamAsset* asset = new StreamAsset(this, validateAssetId(name), type, url, username, password);
    registerAsset(asset);
    return asset;
}

//--------------------------------------------------------------
BufferAsset* AssetManager::addBuffer(const string& name, int size, ofxVideoBufferType t) {
    BufferAsset* asset = new BufferAsset(this, validateAssetId(name), size, t);
    registerAsset(asset);
    return asset;
}

//--------------------------------------------------------------
PlayerAsset* AssetManager::addPlayer(const string& name) {
    PlayerAsset* asset = new PlayerAsset(this, validateAssetId(name));
    registerAsset(asset);
    return asset;
}

//--------------------------------------------------------------
GrabberAsset* AssetManager::addGrabber(const string& name, int devId, int width, int height) {
    GrabberAsset* asset = new GrabberAsset(this, validateAssetId(name), devId, width, height);
    registerAsset(asset);
    return asset;
}

//--------------------------------------------------------------
SyphonAsset* AssetManager::addSyphon(const string& name) {
    return NULL;
}

//--------------------------------------------------------------
bool AssetManager::hasAlias(const string& alias) const {
    return assetAliases.find(alias) != assetAliases.end();
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
                ofLogWarning("AssetManager") << "loadFilesAssets: Could not load :  " << path;
            }
        } else if(imageTypes.extract(name, 0, s) > 0) {
            if(addImage(name, path) == NULL) {
                ofLogWarning("AssetManager") << "loadFilesAssets: Could not load :  " << path;
            }
        } else if(otherTypes.extract(name, 0, s)) {
            // ofLog(OF_LOG_WARNING, "AssetManager::loadFilesAssets() - other valid non-media " + path); 
        } else {
            ofLogWarning("AssetManager") << "loadFilesAssets: Unknown file type :  " << path;
        }
	}
    
    ofLogNotice("AssetManager") << getTotalNumAssets(MEDIA_ASSET_IMAGE) << " images.";
    ofLogNotice("AssetManager") << getTotalNumAssets(MEDIA_ASSET_MOVIE) << " movies.";
}

//--------------------------------------------------------------
void AssetManager::loadSyphonAssets() {
    ofLogNotice("AssetManager") << getTotalNumAssets(MEDIA_ASSET_SYPHON) << " syphon sources.";
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
                ofLogWarning("AssetManager") << "loadFilesAssets: Could not load grabber : " << name;
            }
		}
		
		XML.popTag();
		
	} else {
        ofLogError("AssetManager") << "loadFilesAssets: Unable to load media/grabbers.xml";
	}
    
    ofLogNotice("AssetManager") << getTotalNumAssets(MEDIA_ASSET_GRABBER) << " grabbers.";
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
        ofLogError("AssetManager") << "loadFilesAssets: Unable to load media/streams.xml";
	}

    ofLogNotice("AssetManager") << getTotalNumAssets(MEDIA_ASSET_STREAM) << " streams.";

}

//--------------------------------------------------------------
int AssetManager::getTotalNumAssets() {
    return assets.size() - unregisterQueue.size();
}

//--------------------------------------------------------------
int AssetManager::getTotalNumAssets(MediaAssetType assetType) {
    return getNumAssetsInSet(assetType, assets) -
           getNumAssetsInUnregisterQueue(assetType);
}

//--------------------------------------------------------------
int AssetManager::getNumAssetsInUnregisterQueue(MediaAssetType assetType) {
    return getNumAssetsInSet(assetType, unregisterQueue);
}


//--------------------------------------------------------------
int AssetManager::getNumAssetsInSet(MediaAssetType assetType, set<BaseMediaAsset*> _assets) {
    
    switch (assetType) {
        case MEDIA_ASSET_UNDEFINED:
            return count_if(_assets.begin(), _assets.end(), isUndefinedAsset);
        case MEDIA_ASSET_IMAGE:
            return count_if(_assets.begin(), _assets.end(), isImageAsset);
        case MEDIA_ASSET_MOVIE:
            return count_if(_assets.begin(), _assets.end(), isMovieAsset);
        case MEDIA_ASSET_GRABBER:
            return count_if(_assets.begin(), _assets.end(), isGrabberAsset);
        case MEDIA_ASSET_STREAM:
            return count_if(_assets.begin(), _assets.end(), isStreamAsset);
        case MEDIA_ASSET_BUFFER:
            return count_if(_assets.begin(), _assets.end(), isBufferAsset);
        case MEDIA_ASSET_PLAYER:
            return count_if(_assets.begin(), _assets.end(), isPlayerAsset);
        case MEDIA_ASSET_SYPHON:
            return count_if(_assets.begin(), _assets.end(), isSyphonAsset);
        default:
            ofLog(OF_LOG_ERROR, "AssetManager::getNumAssetsInSet() - unknwon asset type " + ofToString(assetType));
            return -1;
    }
}

//--------------------------------------------------------------
BaseMediaAsset* AssetManager::getAsset(const string& alias) const {
    map<string,BaseMediaAsset*>::const_iterator iter = assetAliases.find(alias);
    
    if(iter!=assetAliases.end()) {
        return iter->second;
    } else {
        return NULL;
    }
}

//--------------------------------------------------------------
void AssetManager::dump() {
    for(assetsIter = assets.begin(); assetsIter != assets.end(); assetsIter++) {
        ofLogNotice() << (*assetsIter)->toString() << endl;
    }
}

//--------------------------------------------------------------
string AssetManager::validateAssetId(const string& name) {
    // get the original asset name
    string assetName = name;
    
    // get the normalized name for OSC purposes
    string assetId = normalizeOscNodeName(assetName);
    
    // if the alias exists, add an incremental
    bool     foundIt = false;
    int      maxSuffix = -1;
    
    // with the new natural ordering we probably don't need to
    // go through all of the items, but rather reverse_iterator from the end
    for(assetsIter=assets.begin();
        assetsIter != assets.end();
        assetsIter++) {
        
        string thisName = (*assetsIter)->getName();
        if(isMatch(assetId,thisName.substr(0,assetId.length()))) {
            if(thisName.length() > assetId.length()) {
                string suffix = thisName.substr(assetId.length()+1);
                string number = suffix.substr(suffix.find_first_of("0123456789"));
                if(number.length() > 0) maxSuffix = MAX(maxSuffix,ofToInt(number));
            }
            foundIt = true;
        }
    }
    
    if(foundIt) {
        assetId +=  ("_" + ofToString(maxSuffix + 1));
    }
        
    // toss a warning if the asset id differs from the asset's original name
    if(!isMatch(assetName, assetId)) {
        ofLog(OF_LOG_WARNING, "AssetManager::generateAssetId() - " + assetName + " produced variant : " + assetId + ".");
    }
    
    // return the generated asset id
    return assetId;
}

//--------------------------------------------------------------
void AssetManager::processQueues() {
    
    // clear unregister queue
    if(!unregisterQueue.empty()) {
        for(assetsIter = unregisterQueue.begin(); 
            assetsIter != unregisterQueue.end(); 
            assetsIter++) {
            unregisterAsset(*assetsIter);
        }
        unregisterQueue.clear(); // done!
    }
}

//--------------------------------------------------------------
void AssetManager::updateAssets() {
    
    // clear register queues
    if(!assets.empty()) {
        for(assetsIter = assets.begin(); 
            assetsIter != assets.end(); 
            assetsIter++) {
            (*assetsIter)->update();
        }
    }
    
    // look through loading assets
    if(!assetsBeingCached.empty()) {
        for(assetsBeingCachedIter = assetsBeingCached.begin();
            assetsBeingCachedIter != assetsBeingCached.end();
            ) {
            if(!(*assetsBeingCachedIter)->isCaching()) {
                // tell someone that it's done caching here
                //(*assetsBeingCachedIter)->getCacheSource()->cacheComplete();
                //
                if((*assetsBeingCachedIter)->isPlayable()) {
                    
                    PlayableAsset* a = toPlayableAsset(*assetsBeingCachedIter);
                    CacheableAsset* b = toCacheableAsset(*assetsBeingCachedIter);
                    if(a != NULL && b != NULL) {
//                        cout << "reporting cache complete!" << endl;
                        a->reportCacheComplete(b);
                    }
                }
                
                assetsBeingCached.erase(*assetsBeingCachedIter++); // erase it
            } else {
                assetsBeingCachedIter++;
            }
        }
    }

}


//--------------------------------------------------------------
//--------------------------------------------------------------
//--------------------------------------------------------------
//--------------------------------------------------------------