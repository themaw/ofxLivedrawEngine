
#include "BufferManager.h"

//--------------------------------------------------------------
BufferManager::BufferManager() : ofxOscRouterNode("/buffers") {
    addOscNodeAlias("/b");
    addOscNodeAlias("/buff");
    addOscMethod("new");
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
}

//--------------------------------------------------------------
FrameBuffer* BufferManager::getNewVideoBuffer(int _bufferSize) {
    
}

//--------------------------------------------------------------
//--------------------------------------------------------------
//--------------------------------------------------------------
