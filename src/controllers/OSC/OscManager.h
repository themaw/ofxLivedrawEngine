#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "OscNodeListener.h"

class OscManager : public OscNodeListener {
	
public:
	
	OscManager();
	virtual ~OscManager();

    void setup();
	void setup(int port);
	void update();
        
    void processOscMessage(string address, ofxOscMessage& m);
	
	
private:
		
	ofxOscReceiver	receiver;
	
};

