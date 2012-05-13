#include "OscManager.h"


//--------------------------------------------------------------
OscManager::OscManager() : OscNodeListener(NULL, "/livedraw") {
    // root node is live draw.  this is the root node, thus parent == NULL
}

//--------------------------------------------------------------
OscManager::~OscManager() {
	// deconstructor
    // TODO: should close down listener?
}

//--------------------------------------------------------------
void OscManager::setup() {
    cout << "NOT IMPLEMENTED" << endl;
}
//--------------------------------------------------------------
void OscManager::setup(int port) {
	receiver.setup( port );
	ofLog(OF_LOG_NOTICE, "OscManager: Listening for osc messages on port " + ofToString(port));
}

//--------------------------------------------------------------
void OscManager::processOscMessage(string address, ofxOscMessage& m) {
    
    // processing it here, because there are no children ... ?
    // 
    
    cout << "GOT ONE FOR OSC MANAGER " << address << endl;
    
}

//--------------------------------------------------------------
void OscManager::update() {

	// check for waiting messages
	while( receiver.hasWaitingMessages() )
	{
		// get the next message
		ofxOscMessage m;
		receiver.getNextMessage( &m ); // fill the message
		string addr = m.getAddress(); // make a non const address copy
        routeOscMessage(addr, m); 
        
        
        
		/*
        
        // check for mouse moved message
		if ( m.getAddress() == "/mouse/position" )
		{
			// both the arguments are int32's
			mouseX = m.getArgAsInt32( 0 );
			mouseY = m.getArgAsInt32( 1 );
		}
		// check for mouse button message
		else if ( m.getAddress() == "/mouse/button" )
		{
			// the single argument is a string
			mouseButtonState = m.getArgAsString( 0 ) ;
		}
		else
		{
			// unrecognized message: display on the bottom of the screen
			string msg_string;
			msg_string = m.getAddress();
			msg_string += ": ";
			for ( int i=0; i<m.getNumArgs(); i++ )
			{
				// get the argument type
				msg_string += m.getArgTypeName( i );
				msg_string += ":";
				// display the argument - make sure we get the right type
				if( m.getArgType( i ) == OFXOSC_TYPE_INT32 )
					msg_string += ofToString( m.getArgAsInt32( i ) );
				else if( m.getArgType( i ) == OFXOSC_TYPE_FLOAT )
					msg_string += ofToString( m.getArgAsFloat( i ) );
				else if( m.getArgType( i ) == OFXOSC_TYPE_STRING )
					msg_string += m.getArgAsString( i );
				else
					msg_string += "unknown";
			}
			// add to the list of strings to display
			msg_strings[current_msg_string] = msg_string;
			timers[current_msg_string] = ofGetElapsedTimef() + 5.0f;
			current_msg_string = ( current_msg_string + 1 ) % NUM_MSG_STRINGS;
			// clear the next line
			msg_strings[current_msg_string] = "";
		}
         */
		
	}

}