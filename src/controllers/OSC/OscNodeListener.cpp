
#include "OscNodeListener.h"

//--------------------------------------------------------------
OscNodeListener::OscNodeListener() {
    oscParent = NULL;
    oscNodeName = "/";
}

//--------------------------------------------------------------
OscNodeListener::OscNodeListener(string _nodeName) {
    oscParent = NULL;
    oscNodeName = _nodeName;
}

//--------------------------------------------------------------
OscNodeListener::OscNodeListener(OscNodeListener* _oscParent, string _oscNodeName) {
    oscParent = _oscParent;
    oscNodeName = _oscNodeName;
}

//--------------------------------------------------------------
OscNodeListener::~OscNodeListener() {}

//--------------------------------------------------------------
void OscNodeListener::routeOscMessage(string pattern, ofxOscMessage& m) {
    
    
    ofLog(OF_LOG_VERBOSE, "OscNodeListener: " + getOscNodeName() + " processing : " +  m.getAddress());
    
    
    int pattrOffset,addrOffset,matchResult;
    
    char* _pattern = (char*)pattern.c_str();
    char* _thisAddress = (char*)oscNodeName.c_str();
    
    matchResult = osc_match(_pattern, _thisAddress, &pattrOffset, &addrOffset);
    
    //cout << m.getAddress() << "<<< " << endl;
    
    if(matchResult == 0) {
        ofLog(OF_LOG_VERBOSE, "OscNodeListener: No match for: " + m.getAddress());
        return;
    } else if(matchResult == OSC_MATCH_ADDRESS_COMPLETE) {
        pattern = pattern.substr(pattrOffset);
        
        if(hasOscCommand(pattern)) {// || children.size() <= 0) {
            ofLog(OF_LOG_VERBOSE, "\t\t\t" + getOscNodeName() + " had the command : " +  m.getAddress());
            processOscMessage(pattern, m);
        } else {
            for(int i = 0; i < oscChildren.size(); i++) { 
                oscChildren[i]->routeOscMessage(pattern, m);
            }
        }
        
        // otherwise, it gets ignored
        
    } else if(matchResult == OSC_MATCH_PATTERN_COMPLETE) {
        ofLog(OF_LOG_VERBOSE,"PATTERN COMPLETE ++ PROCESSING.");
        processOscMessage(pattern, m);
    } else if(matchResult == OSC_MATCH_ADDRESS_AND_PATTERN_COMPLETE) {
        ofLog(OF_LOG_VERBOSE,"ADDRESS AND PATTERN COMPLETE : PERFECT MATCH ++ PROCESSING");
        processOscMessage(pattern, m);
    } else {
        ofLog(OF_LOG_ERROR, "OscNodeListener: Unknown osc_match result.");
    }
    
    
}

//--------------------------------------------------------------
void OscNodeListener::setOscParent(OscNodeListener* _oscParent) {
    oscParent = _oscParent;
}

//--------------------------------------------------------------
OscNodeListener* OscNodeListener::getOscParent() {
    return oscParent;
}

// TODO: this doesn't seem very efficient ... must be a better way ...
//--------------------------------------------------------------
vector<OscNodeListener*> OscNodeListener::getOscSiblings() {
    
    vector<OscNodeListener*> oscSiblings;
    
    
    if(oscParent != NULL) {
        vector<OscNodeListener*> allOscChildrenFromParent = oscParent->getOscChildren();
        vector<OscNodeListener*>::iterator it;
        
        // iterator to vector element:
        it = find (allOscChildrenFromParent.begin(), allOscChildrenFromParent.end(), this);
        
        if(it != allOscChildrenFromParent.end()) {
            allOscChildrenFromParent.erase(it);
        }   
        
        oscSiblings = allOscChildrenFromParent;
        
        return oscSiblings;
        
    } else {
        return oscSiblings;
    }
}

//--------------------------------------------------------------
// recursively locate the root node
OscNodeListener* OscNodeListener::getOscRoot() {
    return oscParent != NULL ? oscParent->getOscRoot() : oscParent;
}

// currently broken
/*
 void getFullOscNodeAddress(string &fullAddress) {
 // if it hasn't been cached yet
 if(parent != NULL) {
 getFullOscNodeAddress(fullAddress);
 } else {
 // nothing
 }
 fullAddress = nodeName + fullAddress;
 }
 */

//--------------------------------------------------------------
void OscNodeListener::setOscNodeName(string _oscNodeName) {
    oscNodeName = _oscNodeName;
}

//--------------------------------------------------------------
string OscNodeListener::getOscNodeName() {
    return oscNodeName;
}

//--------------------------------------------------------------
vector<OscNodeListener*> OscNodeListener::getOscChildren() {
    return oscChildren;
}

//--------------------------------------------------------------
void OscNodeListener::OscNodeListener::addOscChild(OscNodeListener* oscChild) {
    
    // TODO: should this be auto sorted:: std::sort
    
    oscChild->setOscParent(this);
    oscChildren.push_back(oscChild);
}

//--------------------------------------------------------------
bool OscNodeListener::removeOscChild(OscNodeListener* oscChild) {
    vector<OscNodeListener*>::iterator it;
    
    // iterator to vector element:
    it = find (oscChildren.begin(), oscChildren.end(), oscChild);
    
    if(it != oscChildren.end()) {
        //it->setParent(NULL); // TODO: is this a problem?
        oscChildren.erase(it);
        return true;
    } else {
        return false;
    }
    
}

//--------------------------------------------------------------
bool OscNodeListener::hasOscCommand(string _command) {
    vector<string>::iterator it;
    
    // iterator to vector element:
    it = find (oscCommands.begin(), oscCommands.end(), _command);
    return it != oscCommands.end();
}

//--------------------------------------------------------------
void OscNodeListener::addOscCommand(string _command) {
    oscCommands.push_back(_command);
}

//--------------------------------------------------------------
bool OscNodeListener::removeOscCommand(string _command) {
    vector<string>::iterator it;
    
    // iterator to vector element:
    it = find (oscCommands.begin(), oscCommands.end(), _command);
    
    if(it != oscCommands.end()) {
        oscCommands.erase(it);
        return true;
    } else {
        return false;
    }    
}

//--------------------------------------------------------------
bool OscNodeListener::isMatch(string s0, string s1) {
    return icompare(s0,s1) == 0;
}

//--------------------------------------------------------------
bool OscNodeListener::validateOscSignature(string signature, ofxOscMessage& m) {
    
    string mSignature = "";
    // make the signature
    for(int i=0; i < m.getNumArgs(); i++) {
        mSignature+=m.getArgTypeName(i).at(0);
    }
    
    RegularExpression re(signature);
    bool match = re.match(mSignature);
    
    if(!match) {
        ofLog(OF_LOG_ERROR, "Signature: " + signature + " did not match mSignature= " + mSignature);
    }
    
    return match;
}