//
//  stack.h
//  Assignment 4
//
//  Created by Steve Minor on 2/17/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#ifndef __Assignment_4__stack__
#define __Assignment_4__stack__

#include <iostream>
#include <exception>

class stackEmptyException: public std::exception
{
	const char* what() const throw();
};

class stackFullException: public std::exception
{
	const char* what() const throw();
};

template <typename T>
class Stack{
public:
	Stack(unsigned int size):mSize(size), mCount(0){
		mStack = new T[mSize];
	};
	~Stack(){
		delete[] mStack;
	};
	void push(const T& element){
		if(mCount < mSize){
			for(int i = mCount + 1; i > 0; --i){
				mStack[i] = mStack[i-1];
			}
			mStack[0] = element;
			++mCount;
		}
		else{
			throw stackFullException();
		}
	};
	
	T& pop(){
		if(mCount != 0){
			return mStack[--mCount];
		}
		
		throw stackEmptyException();
	};
	
	bool isEmpty()const{
		if(size() > 0){
			return true;
		}
		return false;
	};
	
	int size() const{
		return mCount;
	};
	
private:
	unsigned int mSize, //size of array
	mCount; //number of items in array
	T* mStack;
};

#endif /* defined(__Assignment_4__stack__) */
