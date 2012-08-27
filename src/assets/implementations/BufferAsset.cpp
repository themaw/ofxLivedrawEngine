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

#include "BufferAsset.h"

//--------------------------------------------------------------
BufferAsset::BufferAsset(AssetManagerInterface* man, const string& _name, int size, ofxVideoBufferType t) : BaseMediaAsset(man), PlayableAsset(man)
{
    canSink = true;
    
    assetType = MEDIA_ASSET_BUFFER;
    
    addAlias(_name);
    
    buffer = ofPtr<ofxVideoBuffer>(new ofxVideoBuffer(size,t));
    
    addOscMethod("type");    
    addOscMethod("size"); 
    addOscMethod("clear");
    addOscMethod("framerate");
    
    cacheSource = NULL;
    
}

//--------------------------------------------------------------
BufferAsset::~BufferAsset() {}

//--------------------------------------------------------------
void BufferAsset::update() {
    buffer->update(); // update the buffer

    ofxVideoSinkInterface::update(); // update the sink (newness checks)
}

//--------------------------------------------------------------
bool BufferAsset::dispose() {
    PlayableAsset::dispose();

    detachFromSources();
    return true;
}

//--------------------------------------------------------------
void BufferAsset::processOscCommand(const string& command, const ofxOscMessage& m) {
    if(isMatch(command,"record")) {
        if(validateOscSignature("[sfi]",m)) {
            setSinking(getArgAsBoolean(m,0));
        }
    } else if(isMatch(command,"sink")) {
        if(validateOscSignature("[s]",m)) {
            sink(getArgAsStringUnchecked(m,0));
        }
    } else if(isMatch(command,"unsink")) {
        unsink();
    } else if(isMatch(command,"type")) {
        if(validateOscSignature("[s]",m)) {
            string type = getArgAsStringUnchecked(m,0);
            if(isMatch(type, "norm") || isMatch(type, "fixed") || isMatch(type, "default")) {
                buffer->setBufferType(OFX_VIDEO_BUFFER_FIXED);
            } else if(isMatch(type, "ring") || isMatch(type, "circ") || isMatch(type, "circular")) {
                buffer->setBufferType(OFX_VIDEO_BUFFER_CIRCULAR);
            } else if(isMatch(type, "pass") || isMatch(type, "passthrough")) {
                buffer->setBufferType(OFX_VIDEO_BUFFER_PASSTHROUGH);
            } else {
                ofLog(OF_LOG_WARNING,"Unknown buffer type, using default.");
            }    
        }
    } else if(isMatch(command, "size")) {
        if(validateOscSignature("[i]",m)) {
            int size = getArgAsIntUnchecked(m,0);
            if(size > -1) buffer->setSize(size);
        }
    } else if(isMatch(command, "clear")) {
        buffer->clear();
    } else if(isMatch(command, "framerate")) {
        if(validateOscSignature("[fi]",m)) {
            float frameRate = getArgAsFloatUnchecked(m,0);
            if(frameRate > -1) buffer->setFrameRate(frameRate);
        }
    } else if(isMatch(command, "dump")) {
        ofLogNotice("BufferAsset") << buffer->toString();
    }
}

//--------------------------------------------------------------
void BufferAsset::loadMovie(const string& filename) {
    buffer->loadMovieAsync(filename);
}

//--------------------------------------------------------------
bool BufferAsset::isLoaded() const {
    return buffer->isLoaded();
}

//--------------------------------------------------------------
bool BufferAsset::isLoading() const {
    return buffer->isLoading();
}

//--------------------------------------------------------------
bool BufferAsset::frameReceived(ofxSharedVideoFrame frame) {
    if(isSinking()) {
        buffer->bufferFrame(frame);
    }
}

//--------------------------------------------------------------
bool BufferAsset::isCacheBuffer() const {
    return cacheSource != NULL;
}

//--------------------------------------------------------------
CacheableAsset* BufferAsset::getCacheSource() {
    return cacheSource;
}

//--------------------------------------------------------------
void BufferAsset::unlinkCacheSource() {
    return cacheSource = NULL;
}

//--------------------------------------------------------------
ofPtr<ofxVideoBuffer> BufferAsset::getBuffer() {
    return buffer;
}

//--------------------------------------------------------------
void BufferAsset::sink(const string& asset) {
    if(assetManager != NULL) {
        ofxVideoSourceInterface* src = assetManager->getSourceAsset(asset);
        if(src != NULL) {
            if(!hasSource(src)) {
                unsink(); // release any current ones
                src->attachToSink(this);
            } else {
                ofLogError("BufferAsset") << "sink: " << asset << " was already attached.  Ignoring.";
            }
        } else {
            ofLogError("BufferAsset") << "sink: " << asset << " was not a valid source.";
        }
    } else {
        ofLogError("BufferAsset") << "sink: AssetManager was NULL.";
    }
    
}

//--------------------------------------------------------------
void BufferAsset::unsink() {
    detachFromSources();
}

