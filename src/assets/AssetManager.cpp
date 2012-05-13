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
AssetManager::AssetManager() : OscNodeListener("/sources")
{
	//loadAssets();
    addOscCommand("alias"); // allows id changes
}

//--------------------------------------------------------------
AssetManager::~AssetManager()
{
	
	ofLog(OF_LOG_NOTICE, "Destroying manager.");
	
	// is this the correct way to free all of the memory?
	while (!images.empty())
	{
		delete images.back();
		images.pop_back();
	}
	
	// is this the correct way to free all of the memory?
	while (!videos.empty())
	{
		delete videos.back();
		videos.pop_back();
	}
	
	// is this the correct way to free all of the memory?
	while (!grabbers.empty())
	{
		delete grabbers.back();
		grabbers.pop_back();
	}
	
	// is this the correct way to free all of the memory?
	while (!streams.empty())
	{
		delete streams.back();
		streams.pop_back();
	}
	
	
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
void AssetManager::loadImages()
{
	ofLog(OF_LOG_NOTICE, "Loading Images:");
	ofLog(OF_LOG_NOTICE, "---------------");
	
    int nImages = a.listDir("sources/images/");
	for (int i = 0; i < nImages; i++) {
		// create image sources
		string name = a.getName(i);
		string path = a.getPath(i);

		ImageMediaAsset* asset = new ImageMediaAsset(path);
        asset->setAssetId(name); // short name from file [TODO: make sure that this name is not taken already!
		images.push_back(asset);
		
		ofLog(OF_LOG_NOTICE, "Loading IMAGE: id: " + asset->getAssetId() + " uri: " + asset->getAssetURI().toString() );
	}
	ofLog(OF_LOG_NOTICE, "---------------");
}


//--------------------------------------------------------------
void AssetManager::loadVideos()
{
    ofLog(OF_LOG_NOTICE, "Loading Videos:");
	ofLog(OF_LOG_NOTICE, "---------------");

	int nVideos = a.listDir("sources/videos/");
	for (int i = 0; i < nVideos; i++) {
		// create video sources
		
		string name = a.getName(i);
		string path = a.getPath(i);
		
		VideoMediaAsset* asset = new VideoMediaAsset(path);
        asset->setAssetId(name); // short name from file // short name from file [TODO: make sure that this name is not taken already!
		videos.push_back(asset);
		
		ofLog(OF_LOG_NOTICE, "Loading VIDEO: id: " + asset->getAssetId() + " uri: " + asset->getAssetURI().toString() );

		
	}
	ofLog(OF_LOG_NOTICE, "---------------" + ofToString(getNumVideoAssets()));
	
}

//--------------------------------------------------------------
void AssetManager::loadGrabbers()
{
	ofxXmlSettings XML;

	ofLog(OF_LOG_NOTICE, "Loading Grabbers:");
	ofLog(OF_LOG_NOTICE, "-----------------");
	
	if( XML.loadFile("sources/grabbers/grabbers.xml") ){
		
		XML.pushTag("grabbers");
		string tag = "grabber";
		
		int nGrabbers = XML.getNumTags(tag);
		
		for(int n = 0; n < nGrabbers; n++) {
			string name = XML.getAttribute(tag, "name", "unknown", n);
			int id = XML.getAttribute(tag, "id", -1, n);
			int width = XML.getAttribute(tag, "width", -1, n);
			int height = XML.getAttribute(tag, "height", -1, n);
			
			string logMessage = "GRABBER LOADED: " + name + 
			" id: " +  ofToString(id) + 
			" width: " + ofToString(width) + 
			" height: " + ofToString(height);
			
			GrabberMediaAsset* asset = new GrabberMediaAsset(name);
            asset->setAssetId(name); // short name from file // short name from file [TODO: make sure that this name is not taken already!
			grabbers.push_back(asset);
			
			ofLog(OF_LOG_NOTICE, logMessage+ " id: " + asset->getAssetId() + "uri: " + asset->getAssetURI().toString() );
		}
		
		XML.popTag();
		
	} else {
		ofLog(OF_LOG_ERROR, "Unable to load sources/grabbers/grabbers.xml.");
	}
	ofLog(OF_LOG_NOTICE, "---------------");
}

//--------------------------------------------------------------
void AssetManager::loadStreams()
{
	ofxXmlSettings XML;

	ofLog(OF_LOG_NOTICE, "Loading Streams:");
	ofLog(OF_LOG_NOTICE, "---------------");
	
	if( XML.loadFile("sources/streams/streams.xml") ){
		
		XML.pushTag("streams");
		string tag = "stream";
		
		int nStreams = XML.getNumTags(tag);
		
		for(int n = 0; n < nStreams; n++) {
			string name = XML.getAttribute(tag, "name", "unknown", n);
			string address = XML.getAttribute(tag, "address", "NULL", n);
			string username = XML.getAttribute(tag, "username", "NULL", n); 
			string password = XML.getAttribute(tag, "password", "NULL", n); 
			
			string logMessage = "STREAM LOADED: " + name + 
			" address: " +  address + 
			" username: " + username + 
			" password: " + password;
			
			// TODO NOT WORKING YET
			StreamMediaAsset* asset = new StreamMediaAsset(address);
            asset->setAssetId(name); // short name from file [TODO: make sure that this name is not taken already!
			streams.push_back(asset);
			
            
            ofLog(OF_LOG_NOTICE, logMessage+ " id: " + asset->getAssetId() + "uri: " + asset->getAssetURI().toString() );
			

			
		}
		
		XML.popTag();
		
		
		
	} else {
		ofLog(OF_LOG_ERROR, "Unable to load sources/streams/streams.xml.");
	}
	ofLog(OF_LOG_NOTICE, "---------------");
}



//--------------------------------------------------------------
void AssetManager::loadAssets()
{
	loadImages();
	loadVideos();
	loadGrabbers();
	loadStreams();
}

//--------------------------------------------------------------
int AssetManager::getNumImageAssets() {return images.size();}
//--------------------------------------------------------------
int AssetManager::getNumGrabberAssets() {return grabbers.size();}
//--------------------------------------------------------------
int AssetManager::getNumVideoAssets() {return videos.size();}
//--------------------------------------------------------------
int AssetManager::getNumStreamAssets() {return streams.size();}
//--------------------------------------------------------------


//--------------------------------------------------------------
bool AssetManager::hasId(string id) {
    for(int i  = 0; i < images.size(); i++) {
        if(id.compare(images[i]->getAssetId()) == 0) return true;
    }
    
    for(int i  = 0; i < videos.size(); i++) {
        if(id.compare(videos[i]->getAssetId()) == 0) return true;
    }

    for(int i  = 0; i < grabbers.size(); i++) {
        if(id.compare(grabbers[i]->getAssetId()) == 0) return true;
    }

    for(int i  = 0; i < streams.size(); i++) {
        if(id.compare(streams[i]->getAssetId()) == 0) return true;
    }

    return false;

}


//--------------------------------------------------------------
ImageMediaAsset* AssetManager::getImageAsset(string id) {
    for(int i  = 0; i < images.size(); i++) {
        if(id.compare(images[i]->getAssetId()) == 0) return images[i];
    }
    return NULL;
}

//--------------------------------------------------------------
VideoMediaAsset* AssetManager::getVideoAsset(string id) {
    for(int i  = 0; i < videos.size(); i++) {
        if(id.compare(videos[i]->getAssetId()) == 0) return videos[i];
    }
    return NULL;
}

//--------------------------------------------------------------
GrabberMediaAsset* AssetManager::getGrabberAsset(string id) {
    for(int i  = 0; i < grabbers.size(); i++) {
        if(id.compare(grabbers[i]->getAssetId()) == 0) return grabbers[i];
    }
    return NULL;
}

//--------------------------------------------------------------
StreamMediaAsset* AssetManager::getStreamAsset(string id) {
    for(int i  = 0; i < streams.size(); i++) {
        if(id.compare(streams[i]->getAssetId()) == 0) return streams[i];
    }
    return NULL;
}

//--------------------------------------------------------------
//--------------------------------------------------------------
//--------------------------------------------------------------
//--------------------------------------------------------------
//--------------------------------------------------------------