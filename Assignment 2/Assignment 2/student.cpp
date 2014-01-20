//
//  student.cpp
//  Assignment 2
//
//  Created by Steve Minor on 1/20/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#include "student.h"
#include <string>


class Student{
	std::string name;
	int id;
public:
	Student(std::string _name, int _id = 0);
	
	std::string getName();
	int getId();
};