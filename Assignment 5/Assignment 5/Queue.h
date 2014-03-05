//
//  Queue.h
//  Assignment 5
//
//  Created by Steve Minor on 3/2/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#ifndef __Assignment_5__Queue__
#define __Assignment_5__Queue__

#include <iostream>
#include <deque>

template<typename Container>
class Queue{
private:
	typedef typename Container::value_type Element;
	Container myQueue; //how to initalize to template type?
public:
	Element pop(){};
	void push(const Element& e);
};

template<>
class Queue<std::deque<int>>{
private:
	std::deque<int> myQueue;
public:
	Queue(){std::cout << "in the specialized constructor";};
	int pop(){
		int lastElement = myQueue.back();
		myQueue.pop_back();
		return lastElement;
	};
	
	void push(const int& i){
		myQueue.push_front(i);
	};
};

#endif /* defined(__Assignment_5__Queue__) */
