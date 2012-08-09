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


ImageAsset*   toImageAsset(BaseMediaAsset* asset)   { return dynamic_cast<ImageAsset*>(asset); }
MovieAsset*   toMovieAsset(BaseMediaAsset* asset)   { return dynamic_cast<MovieAsset*>(asset); }
BufferAsset*  toBufferAsset(BaseMediaAsset* asset)  { return dynamic_cast<BufferAsset*>(asset); }
BufferPlayerAsset* toBufferPlayerAsset(BaseMediaAsset* asset) { return dynamic_cast<BufferPlayerAsset*>(asset); }
GrabberAsset* toGrabberAsset(BaseMediaAsset* asset) { return dynamic_cast<GrabberAsset*>(asset); }
StreamAsset*  toStreamAsset(BaseMediaAsset* asset)  { return dynamic_cast<StreamAsset*>(asset); }
SyphonAsset*  toSyphonAsset(BaseMediaAsset* asset)  { return dynamic_cast<SyphonAsset*>(asset); }


//--------------------------------------------------------------
AssetManager::AssetManager() : ofxOscRouterNode("media") {
    
    engine = NULL;
    
    // TODO: move some of these to their respective asset implementations
    
//    addOscNodeAlias("med");
//    addOscNodeAlias("m");
    
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
    ofLog(OF_LOG_NOTICE, "Destroying Asset Manager.");
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

//    if(isMatch(command,"alias")) {
//        if(validateOscSignature("ss", m)) {
//            string existingAlias = getArgAsStringUnchecked(m,0);
//            string additionalAlias = getArgAsStringUnchecked(m,1);
//            BaseMediaAsset * a = getAsset(existingAlias);
//            if(a != NULL) {
//                addAlias(a,additionalAlias);
//            } else {
//                ofLog(OF_LOG_WARNING,"Attempted to set alias, but media asset did not exist.");
//            }
//        }
//    } else 
//    
    if(isMatch(command,"delete")) {
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
        
//        if(isMatch(command,"new")) {
//            cout << "making new buffer" << endl;
//            
//            if(validateOscSignature("s(is?)?", m)) {
//                int numArgs = m.getNumArgs();
//                
//                if(numArgs > 0) {
//                    string alias = getArgAsStringUnchecked(m,0);
//                    int    size = 1;
//                    ofxVideoBufferType type = OFX_VIDEO_BUFFER_FIXED;
//                    
//                    if(numArgs > 1) size  = getArgAsIntUnchecked(m,1);
//                    if(numArgs > 2) {
//                        string type = getArgAsStringUnchecked(m,2);
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
//        } else if(isMatch(command,"dump")) {
//            vector<FrameBuffer*> b = buffers.toArray();
//            cout << "dumping buffer" << endl;
//            for(int i = 0; i < b.size(); i++) {
//                cout << b[i]->toString() << endl;
//            }
//            
//        }

    } else if(isMatch(command,"player")) {
        cout << "in player manager" << endl;
    }                      
                      
     
}

//--------------------------------------------------------------
ofxVideoSourceInterface* AssetManager::getSourceAsset(const string& alias) {
    BaseMediaAsset* sourceAsset = getAsset(alias);

    if(sourceAsset == NULL) {
        ofLogError() << "AssetManager::getSourceAsset : " << alias << " is not the name of a known asset.";
        return NULL;
    }

    if(!sourceAsset->isSource()) {
        ofLogError() << "AssetManager::getSourceAsset : " << sourceAsset->getName() << " is not a source.";
        return false;
    }

    ofxVideoSourceInterface* source = dynamic_cast<ofxVideoSourceInterface*>(sourceAsset);
    if(source == NULL) {
        ofLogError() << "AssetManager::getSourceAsset : " << sourceAsset->getName() + " could not be cast to source.";
        return false;
    }

    return source;
}

//--------------------------------------------------------------
ofxVideoSinkInterface* AssetManager::getSinkAsset(const string& alias) {
    BaseMediaAsset* sinkAsset = getAsset(alias);
    
    if(sinkAsset == NULL) {
        ofLogError() << "AssetManager::getSinkAsset : " << alias << " is not the name of a known asset.";
        return NULL;
    }
    
    if(!sinkAsset->isSink()) {
        ofLogError() << "AssetManager::getSinkAsset : " << sinkAsset->getName() << " is not a source.";
        return false;
    }
    
    ofxVideoSinkInterface* sink = dynamic_cast<ofxVideoSinkInterface*>(sinkAsset);
    if(sink == NULL) {
        ofLogError() << "AssetManager::getSinkAsset : " << sinkAsset->getName() + " could not be cast to source.";
        return false;
    }
    
    return sink;
}

bool AssetManager::attachSourceToSink(const string& sourceAlias, const string& sinkAlias) {
    ofxVideoSourceInterface* source = getSourceAsset(sourceAlias);
    ofxVideoSinkInterface*   sink = getSinkAsset(sinkAlias);

    if(source != NULL && sink != NULL) {
        return source->attachToSink(sink);
    } else {
        return false;
    }
    

}


//--------------------------------------------------------------
bool AssetManager::queueRegisterAsset(BaseMediaAsset* asset) {
    asset->setNodeActive(false);
    return registerQueue.insert(asset).second;
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
        ofLog(OF_LOG_ERROR, "AssetManager::registerAsset - alias already exists");
        return false;
    }
    
    if(!addOscChild(asset)) {
        ofLog(OF_LOG_ERROR, "AssetManager::registerAsset - failed to add as an osc child node");
        return false;
    }

    // turn it on
    asset->setNodeActive(true);

    // add it to our collection
    assets.insert(asset);
    
    // special procedures
    if(isMovieAsset(asset)) {
        toMovieAsset(asset)->setCacheProvider(this);
    }
    

    return true;
}

//--------------------------------------------------------------
bool AssetManager::unregisterAsset(BaseMediaAsset* asset) {

    cout << "unregistering asset --- " << asset->getName() << endl;
    
    // is there a there there?
    if(asset == NULL) {
        ofLogWarning() << "AssetManager::unregisterAsset - asset is NULL ";
        return false;
    }
    
    // tell the object to dispose of itself (free connections, kill other things, etc)
    if(!asset->dispose()) {
        ofLogWarning() << "AssetManager::unregisterAsset - unable to dispose " << asset->getName();
        return false;
    }
    
    // get rid of the alias
    if(hasAlias(asset->getName())) { // double check
        assetAliases.erase(asset->getName());
    }
    
    
    if(hasOscChild(asset) && !removeOscChild(asset)) {
        ofLogError() << "AssetManager::registerAsset - failed to remove as an osc child node";
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
bool AssetManager::cacheAsset(CacheableAsset* asset) {
    cout << "AssetManager::cacheAsset" << endl;
    
    if(asset == NULL) {
        ofLog(OF_LOG_WARNING, "AssetManager::cacheAsset - Asset is NULL");
        return false;
    }
    
    if(asset->isCached()) {
        ofLogError("AssetManager::cacheAsset - Asset is already cached.");
        return false;
    }
    
    
    BufferAsset* cacheAsset = addBuffer("BUFFER_" + asset->getName(), 1, OFX_VIDEO_BUFFER_FIXED);
    
    if(cacheAsset != NULL) {
        cacheAsset->getBuffer()->loadMovie(asset->getFilename());
        asset->setCacheBuffer(cacheAsset);
        return true;
    } else {
        ofLog(OF_LOG_WARNING, "AssetManager::cacheAsset - could not create buffer.");
        return false;
    }
}

//--------------------------------------------------------------
bool AssetManager::uncacheAsset(CacheableAsset* asset) {

    if(asset == NULL) {
        ofLog(OF_LOG_WARNING, "AssetManager::uncacheAsset - Asset is NULL");
        return false;
    }

    if(!asset->isCached()) {
        ofLogError("AssetManager::uncacheAsset - Asset has no cache.");
        return false;
    }
    
    if(!queueUnregisterAsset(asset->getCacheBuffer())) {
        ofLog(OF_LOG_WARNING, "AssetManager::cacheAsset - Unable to uncache buffer.");
        return false;
    } else {
        asset->setCacheBuffer(NULL);
        return true;
    }
}

//--------------------------------------------------------------
bool AssetManager::startAsset(const string& alias) {
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
bool AssetManager::stopAsset(const string& alias) {
    BaseMediaAsset* asset = getAsset(alias);
    if(asset == NULL) {
        ofLog(OF_LOG_WARNING, "AssetManager::stopAsset - Asset not found " + alias);
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
ImageAsset* AssetManager::addImage(const string& name, const string& filename) {
    ImageAsset* asset = new ImageAsset(validateAssetId(name), filename);

    queueRegisterAsset(asset);
    
//    if(!registerAsset(asset)) {
//        ofLog(OF_LOG_ERROR, "AssetManager::addImage - failed to add image");
//        if(!unregisterAsset(asset)) {
//            ofLog(OF_LOG_ERROR, "AssetManager::addImage - failed unregister problem image.");
//            assert(asset == NULL);
//            return asset;
//        } else {
//            return asset;
//        }
//    }

    return asset;
}

//--------------------------------------------------------------
MovieAsset* AssetManager::addMovie(const string& name, const string& filename) {
    MovieAsset* asset = new MovieAsset(validateAssetId(name), filename);
    
    queueRegisterAsset(asset);

//    if(!registerAsset(asset)) {
//        ofLog(OF_LOG_ERROR, "AssetManager::addMovie - failed to add image");
//        if(!unregisterAsset(asset)) {
//            ofLog(OF_LOG_ERROR, "AssetManager::addMovie - failed unregister problem image.");
//            assert(asset == NULL);
//            return asset;
//        } else {
//            return asset;
//        }
//    }
    
    return asset;
}

//--------------------------------------------------------------
StreamAsset* AssetManager::addStream(const string& name, StreamType type, const string& url, const string& username, const string& password) {
    StreamAsset* asset = new StreamAsset(validateAssetId(name), type, url, username, password);
    
    queueRegisterAsset(asset);

//    if(!registerAsset(asset)) {
//        ofLog(OF_LOG_ERROR, "AssetManager::addStream - failed to add image");
//        if(!unregisterAsset(asset)) {
//            ofLog(OF_LOG_ERROR, "AssetManager::addStream - failed unregister problem image.");
//            assert(asset == NULL);
//            return asset;
//        } else {
//            return asset;
//        }
//    }
    
    return asset;
}

//--------------------------------------------------------------
BufferAsset* AssetManager::addBuffer(const string& name, int size, ofxVideoBufferType t) {
    BufferAsset* asset = new BufferAsset(validateAssetId(name), size, t);
    
    queueRegisterAsset(asset);

//    if(!registerAsset(asset)) {
//        ofLog(OF_LOG_ERROR, "AssetManager::addBuffer - failed to add image");
//        if(!unregisterAsset(asset)) {
//            ofLog(OF_LOG_ERROR, "AssetManager::addBuffer - failed unregister problem image.");
//            assert(asset == NULL);
//            return asset;
//        } else {
//            return asset;
//        }
//    }
    
    return asset;
}

//--------------------------------------------------------------
BufferPlayerAsset* AssetManager::addBufferPlayer(const string& name) {
    BufferPlayerAsset* asset = new BufferPlayerAsset(validateAssetId(name));
    queueRegisterAsset(asset);

//    if(!registerAsset(asset)) {
//        ofLog(OF_LOG_ERROR, "AssetManager::addBufferPlayer - failed to add image");
//        if(!unregisterAsset(asset)) {
//            ofLog(OF_LOG_ERROR, "AssetManager::addBufferPlayer - failed unregister problem image.");
//            assert(asset == NULL);
//            return asset;
//        } else {
//            return asset;
//        }
//    }
    
    return asset;
}

//--------------------------------------------------------------
GrabberAsset* AssetManager::addGrabber(const string& name, int devId, int width, int height) {
    GrabberAsset* asset = new GrabberAsset(validateAssetId(name), devId, width, height);
    queueRegisterAsset(asset);

//    if(!registerAsset(asset)) {
//        ofLog(OF_LOG_ERROR, "AssetManager::addGrabber - failed to add image");
//        if(!unregisterAsset(asset)) {
//            ofLog(OF_LOG_ERROR, "AssetManager::addGrabber - failed unregister problem image.");
//            assert(asset == NULL);
//            return asset;
//        } else {
//            return asset;
//        }
//    }    
    
    return asset;
}

//--------------------------------------------------------------
SyphonAsset* AssetManager::addSyphon(const string& name) {
    return NULL;
}

//--------------------------------------------------------------
bool AssetManager::hasAlias(const string& alias) {
    return assetAliases.find(alias) != assetAliases.end();
}

////--------------------------------------------------------------
//bool AssetManager::addAlias(BaseMediaAsset* asset, string alias) {
//    if(!hasAlias(alias)) {
//        assetAliases[alias] = asset;
//        asset->addOscNodeAlias(alias); // add the osc node alias
//        return true;
//    } else {
//        ofLog(OF_LOG_WARNING, "AssetManager::addAlias - failed to add alias because it already exists.");
//        return false;
//    }
//} 

////--------------------------------------------------------------
//bool AssetManager::removeAlias(string alias) {
//    
//    BaseMediaAsset* asset = getAsset(alias);
//    if(asset == NULL) {
//        ofLog(OF_LOG_ERROR, "AssetManager::removeAlias - alias doesn't exist.");
//        return false;
//    }
//    
//    vector<string> aliases = getAliases(asset);
//    
//    if(aliases.size() > 1) {
//        assetAliases.erase(alias); // remove the alias
//        asset->removeOscNodeAlias(alias); // remove the node alias
//        return true;
//    } else if(aliases.size() == 0) {
//        ofLog(OF_LOG_ERROR, "AssetManager::removeAlias - found an asset with no aliases.  This is a problem.");
//        return false;
//    } else {
//        ofLog(OF_LOG_WARNING, "AssetManager::removeAlias - failed to remove alias because it was the last one for that asset.");
//        return false;
//    }
//}

//bool AssetManager::removeAliasesForAsset(BaseMediaAsset* asset) {
//    
//    if(asset == NULL) {
//        ofLog(OF_LOG_ERROR, "AssetManager::removeAliases - asset is null.");
//        return false;
//    }
//
//    vector<string> aliases = getAliases(asset);
//    for(int i = 0; i < aliases.size(); i++) {
//        assetAliases.erase(aliases[i]); // remove the alias
//        asset->removeOscNodeAlias(aliases[i]); // remove the node alias
//    }
//    
//    return true;
//}



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

////--------------------------------------------------------------
//vector<string> AssetManager::getAliases(BaseMediaAsset* asset) {
//    vector<string> aliases;
//    
//    map<string,BaseMediaAsset*>::iterator iter = assetAliases.begin();
//    
//    for(; iter != assetAliases.end(); iter++) {
//        if(iter->second == asset) aliases.push_back(iter->first);
//    }
//    
//    return aliases;
//}

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
    
    ofLog(OF_LOG_NOTICE, "Loaded " + ofToString(getTotalNumAssets(MEDIA_ASSET_IMAGE)) + " images.");
    ofLog(OF_LOG_NOTICE, "Loaded " + ofToString(getTotalNumAssets(MEDIA_ASSET_MOVIE)) + " movies.");	
}

//--------------------------------------------------------------
void AssetManager::loadSyphonAssets() {
    ofLog(OF_LOG_NOTICE, "Loaded " + ofToString(getTotalNumAssets(MEDIA_ASSET_SYPHON)) + " syphon sources.");	
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
    
    ofLog(OF_LOG_NOTICE, "Loaded " + ofToString(getTotalNumAssets(MEDIA_ASSET_GRABBER)) + " grabbers.");
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

    ofLog(OF_LOG_NOTICE, "Loaded " + ofToString(getTotalNumAssets(MEDIA_ASSET_STREAM)) + " streams.");

}

//--------------------------------------------------------------
int AssetManager::getTotalNumAssets() {
    return assets.size() + registerQueue.size() - unregisterQueue.size();
}

//--------------------------------------------------------------
int AssetManager::getTotalNumAssets(MediaAssetType assetType) {
    return getNumAssetsInSet(assetType, assets) +
           getNumAssetsInRegisterQueue(assetType) -
           getNumAssetsInUnregisterQueue(assetType);
}

//--------------------------------------------------------------
int AssetManager::getNumAssetsInRegisterQueue(MediaAssetType assetType) {
    return getNumAssetsInSet(assetType, registerQueue);
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
        case MEDIA_ASSET_BUFFERPLAYER:
            return count_if(_assets.begin(), _assets.end(), isBufferPlayerAsset);
        case MEDIA_ASSET_SYPHON:
            return count_if(_assets.begin(), _assets.end(), isSyphonAsset);
        default:
            ofLog(OF_LOG_ERROR, "AssetManager::getNumAssetsInSet() - unknwon asset type " + ofToString(assetType));
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
    for(assetsIter = assets.begin(); assetsIter != assets.end(); assetsIter++) {
        cout << (*assetsIter)->toString() << endl;
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
    
    // clear register queues
    if(!registerQueue.empty()) {
        for(assetsIter = registerQueue.begin(); 
            assetsIter != registerQueue.end(); 
            assetsIter++) {
            registerAsset(*assetsIter);
        }
        registerQueue.clear(); // done!
    }
    
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
}


//--------------------------------------------------------------
//--------------------------------------------------------------
//--------------------------------------------------------------
//--------------------------------------------------------------