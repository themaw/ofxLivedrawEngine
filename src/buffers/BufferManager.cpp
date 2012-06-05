
#include "BufferManager.h"

//--------------------------------------------------------------
BufferManager::BufferManager(AssetManager* manager) : ofxOscRouterNode("/buffers") {

    assetManager = manager;
    
    addOscNodeAlias("/b");
    addOscNodeAlias("/buff");
    addOscMethod("/new");
}

//--------------------------------------------------------------
BufferManager::~BufferManager() {
    
}

//--------------------------------------------------------------
void BufferManager::update() {
}

//--------------------------------------------------------------
void BufferManager::processOscMessage(string pattern, ofxOscMessage& m) {
    cout << "in buffer manager" << endl;
    
    if(isMatch(pattern,"/new")) {
        cout << "making new buffer" << endl;
        
        if(validateOscSignature("s(is?)?", m)) {
            int numArgs = m.getNumArgs();
            
            if(numArgs > 0) {
                string alias = m.getArgAsString(0);
                int    size = 1;
                ofVideoBufferType type = OFX_VIDEO_BUFFER_FIXED;
                
                if(numArgs > 1) size  = m.getArgAsInt32(1);
                if(numArgs > 2) {
                    string type = m.getArgAsString(2);
                    if(isMatch(type, "norm") || isMatch(type, "fixed") || isMatch(type, "default")) {
                        type = OFX_VIDEO_BUFFER_FIXED;
                    } else if(isMatch(type, "ring") || isMatch(type, "circ") || isMatch(type, "cirular")) {
                        type = OFX_VIDEO_BUFFER_CIRCULAR;
                    } else if(isMatch(type, "pass") || isMatch(type, "passthrough")) {
                        type = OFX_VIDEO_BUFFER_PASSTHROUGH;
                    } else {
                        ofLog(OF_LOG_WARNING,"Unknown buffer type, using default.");
                    }    
                }
                
                assetManager->addBuffer(alias, size, type);
                
            } else {
                cout << "unknown num args." << endl;
            }
        }
    }

}


//--------------------------------------------------------------
FrameBuffer* BufferManager::createNewBuffer(string alias) {
    FrameBuffer* buff = new FrameBuffer(alias); 
    buffers.add(buff);
    addOscChild(buff);
    return buff;
}

//--------------------------------------------------------------
FrameBuffer* BufferManager::createNewBuffer(string alias, int _bufferSize) {
    FrameBuffer* buff = new FrameBuffer(alias,_bufferSize); 
    buffers.add(buff);
    addOscChild(buff);
    return buff;
}

//--------------------------------------------------------------
FrameBuffer* BufferManager::createNewBuffer(string alias, int _bufferSize, ofVideoBufferType _type) {
    FrameBuffer* buff = new FrameBuffer(alias,_bufferSize,_type); 
    buffers.add(buff);
    addOscChild(buff);
    return buff;
}

//--------------------------------------------------------------
bool BufferManager::remove(MediaAsset* asset) {
    
    if(asset != NULL && asset->getAssetType() == MEDIA_ASSET_BUFFER) {
        FrameBuffer* buffer = asset->getBuffer();
        if( buffer!= NULL) {
            if(buffers.remove(buffer)) {
                asset->setBuffer(NULL); // clear buffer
                removeOscChild(buffer); // break osc link
                delete buffer;
            } else {
                cout << "ERROR deleting the buffer" << endl;
            }
        } else {
            cout << "null buffer." << endl;
        }
    } else {
        cout << "null asset." << endl;
    }
    
}


//--------------------------------------------------------------
//--------------------------------------------------------------
