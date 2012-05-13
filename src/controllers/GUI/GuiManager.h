/*
 *  GuiManager.h
 *  livedraw
 *
 *  Created by Christopher P. Baker on 3/5/11.
 *  Copyright 2011 Murmur Labs LLC. All rights reserved.
 *
 */

#pragma once

#include "ofMain.h"
#include "OscManager.h"
//#include "ofxGui.h"

//#include "MyCustomControllerObject.h"

class GuiManager {//: public OscNodeListener {
	
public:
	
	GuiManager();
    ~GuiManager();
    
    void setup();
    void update();
    void draw();
    

    void newButtonEvent(const void * sender, int & i);

private:    
   // ofxGui* gui;
    
    
   // MyCustomControllerObject* guiObj;
	

        
};
