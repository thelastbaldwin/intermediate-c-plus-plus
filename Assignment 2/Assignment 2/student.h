//
//  student.h
//  Assignment 2
//
//  Created by Steve Minor on 1/20/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#ifndef __Assignment_2__student__
#define __Assignment_2__student__

#include <iostream>
#include <string>
#include <sstream> //convert from string to int
#include <vector>
#include <algorithm> //std::sort

//nice to have: add to namespace

class Student{
	std::string name;
	int id;
public:
	Student(std::string _name, int _id = 0);
	std::string getName() const;
	int getId() const;
};

std::string getNextStudent(const std::string& s);
std::string extractName(const std::string& s);
int extractId(const std::string& s);
bool studentCompare(const Student& a, const Student& b);

std::vector<Student> parseStudents(const std::string& studentList);
std::vector < std::vector< Student> > vecVecStudents (const std::vector<Student> studentList);


#endif /* defined(__Assignment_2__student__) */