
#include "BufferManager.h"

//--------------------------------------------------------------
BufferManager::BufferManager() : OscNodeListener("/buffers") {
    addOscCommand("new");
}

//--------------------------------------------------------------
BufferManager::~BufferManager() {
    
}

//--------------------------------------------------------------
void BufferManager::update() {
}

//--------------------------------------------------------------
void processOscMessage(string pattern, ofxOscMessage& m) {
    
}


//--------------------------------------------------------------
ofxVideoBuffer* getNewVideoBuffer(int _bufferSize) {
    
}

//--------------------------------------------------------------
//--------------------------------------------------------------
//--------------------------------------------------------------
