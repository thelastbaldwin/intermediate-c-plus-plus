//
//  student.cpp
//  Assignment 2
//
//  Created by Steve Minor on 1/20/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#include "student.h"

Student::Student(std::string _name, int _id):
	name(_name),
	id(_id)
	{ if (id == 0){
		std::cout <<  "Student " << name <<  " did not have an ID" << std:: endl;
		}
	};

std::string Student::getName(){ return name; }
int Student::getId(){ return id; }

std::string getNextStudent(const std::string& s){
	static size_t currentIndex = 0;
	std::string currentStudent;
	
	if(currentIndex < s.size()){
		size_t commaPos = s.find(',', currentIndex);
		if(commaPos == s.npos){
			currentStudent = s.substr(currentIndex, s.size());
			currentIndex = s.size();
		}else{
			currentStudent = s.substr(currentIndex, commaPos-currentIndex);
			currentIndex = commaPos + 1;
		}
	}
	if(currentStudent.empty()){
		currentIndex = 0;
	}
	return currentStudent;
}

std::string extractName(const std::string& s){
	std::string name;
	
	size_t semiColPos = s.find(';');
	
	if(semiColPos != -1){
		name = s.substr(0, semiColPos);
	}else{
		name = s;
	}
	
	return name;
}

int extractId(const std::string & s){
	//return 0 if no id	
	int id = 0;
	std::string idString;
	std::stringstream ss;
	size_t semiColPos = s.find(';');
	
	if(semiColPos != -1){
		ss << s.substr(semiColPos + 1, s.size()  - semiColPos);
		ss >> id;
	}	
	return id;
}


std::vector<Student> parseStudents(const std::string& studentList){
	std::vector<Student> students;
	
	std::string currentStudent = getNextStudent(studentList);
	std::string studentName;
	int studentId;
	
	while(!currentStudent.empty()){

		studentName = extractName(currentStudent);
		studentId = extractId(currentStudent);
		
		if(studentId){
			students.push_back(Student(studentName, studentId));
		}else{
			students.push_back(Student(studentName));
		}
		currentStudent = getNextStudent(studentList);
	}

	return students;
}

