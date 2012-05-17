
#include "FrameBufferPlayer.h"


//--------------------------------------------------------------
FrameBufferPlayer::FrameBufferPlayer() : ofxVideoBufferPlayer(), ofxOscRouterNode("/player") {
    
    addOscMethod("/buffer");
    
    addOscMethod("/start");
    addOscMethod("/stop");
    addOscMethod("/pause");
    
    addOscMethod("/loopmode");

    addOscMethod("/looppoints");
    addOscMethod("/looppointstart");
    addOscMethod("/looppointend");
    
    addOscMethod("/looppointsn");
    addOscMethod("/looppointstartn");
    addOscMethod("/looppointendn");
    
    addOscMethod("/frame");
    addOscMethod("/framen");    
    
    addOscMethod("/speed");
}


//--------------------------------------------------------------
FrameBufferPlayer::~FrameBufferPlayer() {}

//--------------------------------------------------------------
void FrameBufferPlayer::processOscMessage(string address, ofxOscMessage& m) {
    cout << "player got a meessssaaaage!!!!" << endl;
    
    if(isMatch(address,"/buffer")) {
        if(validateOscSignature("[s][sfi]?", m)) {
            string assetId = m.getArgAsString(0);
            bool useDisk = getArgAsBoolean(m,1);

            if(hasParentLayer()) {
                //AssetManager* am = parentLayer->getAssetManager();
                    
                
                
                
            } else {
                ofLog(OF_LOG_ERROR, "FrameBufferPlayer::processOscMessage() - player has no parent layer!");
            }
        }
    } else if(isMatch(address, "/start")) { 
        start();
    } else if(isMatch(address, "/stop")) {
        stop();
    } else if(isMatch(address, "/pause")) {
        if(validateOscSignature("[sfi]", m)) {
            setPaused(getArgAsBoolean(m,0));
        }
    } else if(isMatch(address, "/loopmode")) {
        if(validateOscSignature("s", m)) {
            string loopMode = m.getArgAsString(0);
            if(isMatch(loopMode,"NONE")) {
                setLoopType(OF_LOOP_NONE);
            } else if(isMatch(loopMode,"LOOP")) {
                setLoopType(OF_LOOP_NORMAL);
            } else if(isMatch(loopMode,"PALINDROME")) {
                setLoopType(OF_LOOP_PALINDROME);
            } else {
                ofLog(OF_LOG_WARNING, "FrameBufferPlayer: Unknown loop mode: " + loopMode);
            }
        }
    } else if(isMatch(address, "/looppoints")) {
        if(validateOscSignature("[fi][fi]", m)) {
            setLoopPoints(m.getArgAsFloat(0),m.getArgAsFloat(1));
        }
    } else if(isMatch(address, "/looppointstart")) {
        if(validateOscSignature("[fi]", m)) {
            setLoopPointStart(m.getArgAsFloat(0));
        }
    } else if(isMatch(address, "/looppointend")) {
        if(validateOscSignature("[fi]", m)) {
            setLoopPointStart(m.getArgAsFloat(0));
        }
    } else if(isMatch(address, "/looppointsn")) {
        if(validateOscSignature("[fi][fi]", m)) {
            setLoopPointsNorm(m.getArgAsFloat(0),m.getArgAsFloat(1));
        }
    } else if(isMatch(address, "/looppointstartn")) {
        if(validateOscSignature("[fi]", m)) {
            setLoopPointStartNorm(m.getArgAsFloat(0));
        }
    } else if(isMatch(address, "/looppointendn")) {
        if(validateOscSignature("[fi]", m)) {
            setLoopPointStartNorm(m.getArgAsFloat(0));
        }
    } else if(isMatch(address, "/frame")) {
        if(validateOscSignature("[fi]", m)) {
            setFrame(m.getArgAsFloat(0));
        }
    } else if(isMatch(address, "/framen")) {
        if(validateOscSignature("[fi]", m)) {
            setFrameNorm(m.getArgAsFloat(0));
        }
    } else if(isMatch(address, "/speed")) {
        if(validateOscSignature("[fi]", m)) {
            setSpeed(m.getArgAsFloat(0));
        }
    } else {
        // unknown command
    }
}

//--------------------------------------------------------------
CanvasLayer* FrameBufferPlayer::getParentLayer() {
    return parentLayer;
}

//--------------------------------------------------------------
void FrameBufferPlayer::setParentLayer(CanvasLayer* layer) {
    parentLayer = layer;    
}

//--------------------------------------------------------------
bool FrameBufferPlayer::hasParentLayer() {
    return parentLayer != NULL;
}

