#include "TestHarness.h"
#include <iostream>
#include <string>

TEST(commaSplitTest, string){
	std::string studentString = "John Doe;1234,James Bond;7,Tracy Brown;177,Jack Smith;172,Jim Black,Tim White;88";
	CHECK_EQUAL(13, studentString.find(','));
	
	std::string firstStudent = studentString.substr(0, studentString.find(','));
	CHECK_EQUAL("John Doe;1234", firstStudent);
	
	std::cout << studentString << std::endl;
}