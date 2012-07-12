//
//  ImageAsset.h
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 7/6/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#pragma once

#include "BaseMediaAsset.h"
#include "DiskBasedAsset.h"
#include "FrameSourceAsset.h"

class ImageAsset : public virtual BaseMediaAsset,
                   public virtual DiskBasedAsset,
                   public virtual FrameSourceAsset 
{
public:
    ImageAsset(const string& _name, string _filename) : DiskBasedAsset(_filename) {
        assetType = MEDIA_ASSET_IMAGE;
        name      = _name;
            
        // go directly to the frame source file
        frame = ofPtr<ofImage>(new ofImage());
        frame->loadImage(filename);
    }
    
    virtual ~ImageAsset() {}

    void processOscMessage(const string& pattern, const ofxOscMessage& m) {
        cout << "processing image asset " << getName() << endl;
    }
    
    bool dispose() {
        detachFromAllSinks();
        cout << "disposing of image " << getName() << endl;
    }

    bool isFrameNew() {
        return false; // we loaded it once.
    }
    
    ofPixelsRef getPixelsRef() {
        return frame->getPixelsRef();
    }
    
    void open()   {
        // Not applicable.
    }
    
    void close() {
        // Not applicable.
    }
    
    bool isLoaded() {
        return true;
    }
    
protected:
//    string filename;
    
};
