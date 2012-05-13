/*
 *  SourceManager.h
 *  livedraw
 *
 *  Created by Christopher P. Baker on 1/15/11.
 *  Copyright 2011 Murmur Labs LLC. All rights reserved.
 *
 */

#pragma once

#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "ofImage.h"

//#include "BaseMediaAsset.h"
#include "ImageMediaAsset.h"
#include "VideoMediaAsset.h"
#include "GrabberMediaAsset.h"
#include "StreamMediaAsset.h"
#include "SyphonMediaAsset.h"
#include "OscNodeListener.h"

/*
#include "GrabberSource.h"
#include "VideoSource.h"    
#include "ImageSource.h"
#include "StreamSource.h"
*/
 
class AssetManager : public OscNodeListener {
	
public:
	
	AssetManager();
	virtual ~AssetManager();

    void setup();
    void update();
    void processOscMessage(string pattern, ofxOscMessage& m);

    
    
	// this is for sources (videos)
	//void getSourceInstance(BaseMediaSource* source);
	
	// this is for shared sources (live video, streams, videos??) // if we loaded the video into memory
	//void getSourceShared(BaseMediaSource* source);
	
	//bool addSource(BaseMediaSource* source);
	//bool removeSource(BaseMediaSource* source);
	
    
    //ofVideoGrabber* grabber
    
	
	void loadAssets();
	
	void loadImages();
	void loadVideos();
	void loadGrabbers();
	void loadStreams();
	
	
	int getNumImageAssets();
	int getNumVideoAssets();
	int getNumGrabberAssets();
	int getNumStreamAssets();

	//  TODO: for file watchers	
	//	void onNewAsset(ImageMediaAsset* image);
	//	void onNewAsset(VideoMediaAsset* video);
	//	void onNewAsset(GrabberMediaAsset* grabber);
	//	void onNewAsset(StreamMediaAsset* stream);
    
	// TODO: this is strange.  we should be able to open this without having it passed in
	
    ofVideoGrabber* getGrabberSource(GrabberMediaAsset* grabberAsset);
    
    
    ImageMediaAsset* getImageAsset(string id);
    VideoMediaAsset* getVideoAsset(string id);
    GrabberMediaAsset* getGrabberAsset(string id);
    StreamMediaAsset* getStreamAsset(string id);
    
    bool hasId(string id);
    
private:
	
	vector<ImageMediaAsset*> images;
	vector<VideoMediaAsset*> videos ;
	vector<GrabberMediaAsset*> grabbers;
	vector<StreamMediaAsset*> streams;

	//vector<GrabberSource*> activeGrabberSources;
	//vector<GrabberSource*> activeStreamingSource;
	//vector<GrabberSource*> activeGrabberSource;
	//vector<GrabberSource*> activeGrabberSource;
	//vector<GrabberSource*> activeGrabberSource;
    
    ofDirectory a;
    
    
    
    
    
    

};
