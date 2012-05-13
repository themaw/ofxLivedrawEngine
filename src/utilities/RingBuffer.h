/*
 *  RingBuffer.h
 *  livedraw
 *
 *  Created by Christopher P. Baker on 3/11/11.
 *  Copyright 2011 Murmur Labs LLC. All rights reserved.
 *
 */

// modified from bml

// TODO: another option http://goodliffe.blogspot.com/2008/11/c-stl-like-circular-buffer-part-11.html

#pragma once

#include "ofMain.h"

template<class T> class RingBuffer
{
	
private:
	T* buf;	// buffer
	int size; // buffer size
	T* emptyValue; // the default empty return value
	
	int head;
	int tail;
	int cnt;
	bool overrun;
	
	
public:
	
    RingBuffer(int _size, T* _emptyValue = NULL) {
		emptyValue = _emptyValue; // init the empty value
		size = _size; // init the size
		
		// init the buffer
        head = 0;
        tail = 0;
        cnt = 0;
        overrun = false;
		
		// allocate the ring buffer
		buf = new T[size];
		
	}
	
	virtual ~RingBuffer() {
		delete buf;
	}

    int getSize() {
        return size;
    }
    
	void clear() {
		head = 0;
		tail = 0;
		cnt = 0;
		overrun = false;
	}
	
	bool isOverrun() {
		return overrun;
	}
	
	void clearOverrun() {
		overrun = false;
	}
	
	bool isEmpty() {
		return cnt == 0;
	}
	
	int getNumAvailable() {
		return cnt;
	}
	
	int getNumEmpty() {
		return size - cnt;
	}
	
	void put(T val) {
		buf[head] = val;
		cnt++;
		head++;
		if (head >= size) head = 0;
		if (cnt > size) {
			overrun = true;
			cnt = size;
			tail = head;
		}
	}
	
	
	bool putatPosn(T val, int offset) {
		if (offset > 0 || offset <= -cnt) {
			ofLog(OF_LOG_ERROR, "offset greater than data available");
			return false;
		}
	
		if (head + offset < 0) {
			buf[size + (head + offset)] = val;
		} else {
			buf[head + offset] = val;
		}
		
		return true;
	}
	
	T get() {
		if (cnt == 0) {
			ofLog(OF_LOG_ERROR, "ring buffer empty");
			return emptyValue;
		}
		
		T val = buf[tail];
		tail++;
		if (tail >= size) tail = 0;
		cnt--;
		return val;
	}
	
	T peek(int offset) {
		if (cnt == 0 || offset < 0 || offset >= cnt) {
			ofLog(OF_LOG_ERROR, "offset greater than data available");
			return *emptyValue;
		}
		
		T val;
		
		if (tail + offset >= size) {
			val = buf[tail + offset - size];
		} else {
			val = buf[tail + offset];
		}
		
		return val;
	}
	
	
	T peekFirst() {
		return peek(0);
	}
	
	
	T peekLast() {
		return peek(MIN(size-1,cnt)); // get the lasst one that we can
	}
	
	
	
	bool resize(int _new_size) {
		
		if (_new_size < cnt) {
			// TODO, this may not be needed
			ofLog(OF_LOG_ERROR, "offset greater than data available");
			return false;
		}

		size = _new_size;
		T* newbuf = new T[size]; // allocate memory for the resized matrix
		memcpy(newbuf, buf, sizeof(newbuf));
		delete buf;	  // delete old pointer
		buf = newbuf; // copy new pointer
		
		
		// reset buffer state
		buf = newbuf;
		head = cnt; // TODO if we shrink things, this stuff will change
		tail = 0;
		
		return true;
	}
};





