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

template <typename T>
class Stack{
public:
	Stack(unsigned int size):mSize(size), mCount(0){
		mStack = new T[mSize];
	};
	~Stack(){
		delete[] mStack;
	};
	void Push(const T& element);
	T Pop();
	bool isEmpty()const;
	int size() const;
private:
	unsigned int mSize, mCount;
	T* mStack;
};

#endif /* defined(__Assignment_4__stack__) */
