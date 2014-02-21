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
	
	Stack(const Stack<T>& other):mSize(other.mSize), mCount(other.mCount){
		mStack = new T[mSize];
		
		for(int i = 0; i < mCount; ++i){
			mStack[i] = other.mStack[i];
		}
	};
	
	~Stack(){
		delete[] mStack;
	};
	
	template <typename T2> friend class Stack; //private member access across different template assignment
	
	void push(const T& element){
		if(mCount < mSize){
			for(int i = mCount + 1; i > 0; --i){
				mStack[i] = mStack[i-1];
			}
			mStack[0] = element;
			++mCount;
		}
		else{
			//throw stackFullException();
			
			resize();
			for(int i = mCount + 1; i > 0; --i){
				mStack[i] = mStack[i-1];
			}
			mStack[0] = element;
			++mCount;
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
	
	
	Stack<T>& operator=(const Stack<T>& rhs){
		mSize = rhs.mSize;
		mCount = rhs.mCount;
		
		delete[] mStack;
		mStack = new T[mSize];
		
		for(int i = 0; i < mSize; ++i){
			mStack[i] = rhs.mStack[i];
		}
		
		return *this;
	}
	
	template <typename T2>
	Stack<T>& operator=(const Stack<T2>& rhs){
		mSize = rhs.mSize;
		mCount = rhs.mCount;
		
		delete[] mStack;
		mStack = new T[mSize];
		
		for(int i = 0; i < mSize; ++i){
			mStack[i] = rhs.mStack[i];
		}
		
		return *this;
	}
	
private:
	unsigned int mSize, //size of array
	mCount; //number of items in array
	T* mStack;
	
	void resize(){
		mSize *= 2;
		T temp[mSize];
		
		for(int i = 0, len = mSize/2; i < len; ++i){
			temp[i] = mStack[i];
		}
		
		delete[] mStack;
		mStack = new T[mSize];
		
		for(int i = 0; i < mSize; ++i){
			mStack[i] = temp[i];
		}
	}
};


#endif /* defined(__Assignment_4__stack__) */
