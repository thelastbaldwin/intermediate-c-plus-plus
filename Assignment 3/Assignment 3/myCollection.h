//
//  myCollection.h
//  Assignment 3
//
//  Created by Steve Minor on 2/6/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#ifndef __Assignment_3__myCollection__
#define __Assignment_3__myCollection__

#include <iostream>
#include <vector>

template <typename T>
T fact(T n){
	return (n < 2 ? 1 : n * fact(n-1));
};

// the parameterized type n requires that the < , - , and * operators
// are overloaded. The < operator must perform a comparision against an int and the
// - operator must be able to subtract an int as well. Additionally, n requires a
// copy constructor since the argument is passed by value.

template < typename T>
class myCollection{
public:
	int count() const{
		return int(mCollection.size()); //returns size_t without cast
	};
	bool isEmpty() const{
		return mCollection.empty();
	};
	
	void add (const T& t){
		mCollection.push_back(t);
	};
	const T get (int index) const{
		return mCollection[index];
	};
	
	// Because the printAll and printReverseOrder statements require using the << operator
	// this must be overloaded in the template class
	
	void printAll(std::ostream& os){
		for(typename std::vector<T>::const_iterator it = mCollection.begin(); it != mCollection.end(); ++it){
			os << *it; 
		}
	};
	void printReverseOrder(std::ostream& os){
		for(typename std::vector<T>::const_reverse_iterator it = mCollection.rbegin(); it != mCollection.rend(); ++it){
			os << *it;
		}
	};
private:
	std::vector<T> mCollection;
};

#endif /* defined(__Assignment_3__myCollection__) */
