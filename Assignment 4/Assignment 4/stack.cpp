//
//  stack.cpp
//  Assignment 4
//
//  Created by Steve Minor on 2/17/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#include "stack.h"

const char* stackEmptyException::what() const throw(){
	return "stack empty";
}

const char* stackFullException::what() const throw(){
	return "stack full";
}
