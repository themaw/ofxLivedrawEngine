//
//  ofxSimpleSet.h
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 6/4/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#pragma once

#include "ofMain.h"
#include <set>
#include <vector>

template <typename T> class ofxSimpleSet {
public:
    ofxSimpleSet();
    virtual ~ofxSimpleSet();
    bool    contains(T item);
    bool    add(T item);
    bool    remove(T item);
    typename set<T>::iterator find(T item);
    typename set<T>::iterator begin();
    typename set<T>::iterator end();
    size_t size();
    vector<T> toArray();
    set<T>& getItems();
private:
    set<T> items;
    typename set<T>::iterator it;
};

template <class T> ofxSimpleSet<T>::ofxSimpleSet() {}
template <class T> ofxSimpleSet<T>::~ofxSimpleSet() {}
template <class T> bool ofxSimpleSet<T>::contains(T item){return find(item) != items.end();}
template <class T> bool ofxSimpleSet<T>::add(T item){return (items.insert(item)).second;}
template <class T> bool ofxSimpleSet<T>::remove(T item) {
    it = find(item);
    if(it != items.end()) {
        items.erase(it); // erase it
        return true;
    } else {
        return false;
    }
}
template <class T> typename set<T>::iterator ofxSimpleSet<T>::find(T item){return items.find(item);}
template <class T> typename set<T>::iterator ofxSimpleSet<T>::begin(){return items.begin();}
template <class T> typename set<T>::iterator ofxSimpleSet<T>::end(){return items.end();}

template <class T> size_t ofxSimpleSet<T>::size() { return items.size();}
template <class T> vector<T> ofxSimpleSet<T>::toArray() {
    vector<T> vec;
    for(it=items.begin(); it != items.end(); it++) vec.push_back(*it);
    return vec;
}
template <class T> set<T>& ofxSimpleSet<T>::getItems() {return items;}




// some defs
typedef ofxSimpleSet<int>    ofxSimpleIntSet;
typedef ofxSimpleSet<float>  ofxSimpleFloatSet;
typedef ofxSimpleSet<string> ofxSimpleStringSet;



