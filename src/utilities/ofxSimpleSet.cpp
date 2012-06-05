//
//  ofxSimpleSet.cpp
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 6/4/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#include "ofxSimpleSet.h"


//template <class T> ofxSimpleSet<T>::ofxSimpleSet() {}
//template <class T> ofxSimpleSet<T>::~ofxSimpleSet() {}


template <class T> bool ofxSimpleSet<T>::contains(T item) {
    return find(item) != items.end();
}

template <class T> bool ofxSimpleSet<T>::add(T item) {
    return (items.insert(item)).second; // first is a iter to the item, second is if it was new
}

template <class T> bool ofxSimpleSet<T>::remove(T item) {
    it = find(item);
    if(it != items.end()) {
        items.erase(it); // erase it
        return true;
    } else {
        // do nothing, cause there's nothing to do
        return false;
    }
}

template <class T> typename set<T>::iterator ofxSimpleSet<T>::find(T item) {
    return items.find(item);
}