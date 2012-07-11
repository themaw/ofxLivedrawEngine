/*
 *  Enabler.h
 *  utils
 *
 *  Created by Christopher P. Baker on 3/6/11.
 *  Copyright 2011 Murmur Labs LLC. All rights reserved.
 *
 */

#pragma once

class Enabler {
	
public:
	
	Enabler() { setEnabled(true); }
	Enabler(bool _enabled) { setEnabled(_enabled); }
	virtual ~Enabler() {};
	
	bool isEnabled() {
		return enabled;
	}
	
    void enable() {
        setEnabled(true);
    }

    void disable() {
        setEnabled(false);
    }

    
    void toggleEnabled() {
        enabled = !enabled;
        // call the events if needed
        if(enabled) {
            onEnabled();
        } else {
            onDisabled();
        }
    }
    
	void setEnabled(bool _enabled)
	{ 
		if(_enabled != enabled) {
			this->enabled = enabled;

			// call the events if needed
			if(_enabled) {
				onEnabled();
			} else {
				onDisabled();
			}
		
		}
		
	};
	
	// subclasses can get these messages
	virtual void onEnabled(){};
	virtual void onDisabled(){};
	
	
private:
	
	bool enabled;
	
};


