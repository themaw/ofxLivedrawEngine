#pragma once

#include <map>
#include <set>

#include "ofMain.h"
#include "ofxOsc.h"
#include "OscNodeListener.h"
#include "Poco/RegularExpression.h"
#include "Poco/String.h"

extern "C" {    
    #include "osc_match.h"
}

using namespace std;
using Poco::RegularExpression;
using Poco::toUpper;
using Poco::toLower;
using Poco::icompare;

class OscNodeListener {

public:
	
    OscNodeListener();
    OscNodeListener(string _nodeName);

	OscNodeListener(OscNodeListener* _oscParent, string _oscNodeName);
    
    virtual ~OscNodeListener();
    
    // the address here is the remaining bit of the address, as it is processed and pruned
    virtual void processOscMessage(string pattern, ofxOscMessage& m) = 0;
	
    void routeOscMessage(string pattern, ofxOscMessage& m);
    void setOscParent(OscNodeListener* _oscParent);
    
    // recursively locate the root node
    OscNodeListener* getOscRoot();
    
    void setOscNodeName(string _oscNodeName);    
    string getOscNodeName();
    OscNodeListener* getOscParent();
    // TODO: this doesn't seem very efficient ... must be a better way ...
    vector<OscNodeListener*> getOscSiblings();

    vector<OscNodeListener*> getOscChildren(); 
    void addOscChild(OscNodeListener* oscChild);
    bool removeOscChild(OscNodeListener* oscChild);
    bool hasOscCommand(string _command);
    void addOscCommand(string _command);
    bool removeOscCommand(string _command);
    bool isMatch(string s0, string s1);
    bool validateOscSignature(string signature, ofxOscMessage& m); 
    

protected:
	
    string oscNodeName;
    
    OscNodeListener* oscParent;
    vector<OscNodeListener*> oscChildren;
    vector<string> oscCommands;

};
