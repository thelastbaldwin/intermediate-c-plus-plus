#include "TestHarness.h"
#include <iostream>
#include <string>
#include <regex>

//TEST(hwRegexTest, string){
//	std::string studentString = "John Doe;1234,James Bond;7,Tracy Brown;177,Jack Smith;172,Jim Black,Tim White;88";
//	
//	std::regex studentRegex("J.*"); //matches students with or without id's
//	
////	method 1
////	std::sregex_iterator it(studentString.begin(), studentString.end(), studentRegex);
////	std::sregex_iterator it_end;
////	while(it != it_end) {
////		std::smatch match = *it;
////		std::cout << match.str() << std::endl;
////		++it;
////	}
//	
////	method 2
//	std::smatch sm;	
//}

//TEST(regexTests, regex){
//	// c++ regex seems particularly unforgiving, or I just suck at it
//	// simple tests follow 
//	std::string s = "John Doe";
//	std::regex e("([a-zA-Z ])+");
//	CHECK(std::regex_match(s, e));
//	
//	std::smatch sm;
//	std::regex_match(s, sm, e);
//	CHECK_EQUAL(2, sm.size()); //John Doe and e?
//	
//	std::smatch::iterator it = sm.begin();
//	std::smatch::iterator it_end = sm.end();
//	while(it != it_end){
//		std::cout << *it << std::endl;
//		++it;
//	}
//}

//TEST(regexExample, regex){
//	//http://www.cplusplus.com/reference/regex/regex_match/
//	CHECK(std::regex_match ("subject", std::regex("(sub)(.*)")));
//	
//	std::string s ("subject");
//	std::regex e ("(sub)(.*)");
//	CHECK(std::regex_match (s,e))	
//	CHECK(std::regex_match ( s.begin(), s.end(), e ))
//	
//	std::cmatch cm;    // same as std::match_results<const char*> cm;
//	std::regex_match ("subject",cm,e);
//	CHECK_EQUAL(3, cm.size());
//	
//	std::smatch sm;    // same as std::match_results<string::const_iterator> sm;
//	std::regex_match (s,sm,e);
//	CHECK_EQUAL(3, sm.size());
//	
//	std::regex_match ( s.cbegin(), s.cend(), sm, e);
//	CHECK_EQUAL(3, sm.size());
//	
//	// using explicit flags:
//	CHECK(std::regex_match ( "subject", cm, e, std::regex_constants::match_default ));

//	std::cout << "the matches were: ";
//	for (unsigned i=0; i<sm.size(); ++i) {
//		std::cout << "[" << sm[i] << "] ";
//	}
//}