#include "TestHarness.h"
#include "student.h"

TEST(commaSplitTest, string){
	std::string studentString = "John Doe;1234,James Bond;7,Tracy Brown;177,Jack Smith;172,Jim Black,Tim White;88";
	CHECK_EQUAL(13, studentString.find(','));
	
	std::string firstStudent = studentString.substr(0, studentString.find(',', 13));
	CHECK_EQUAL("John Doe;1234", firstStudent);
	
	CHECK_EQUAL(80, studentString.size());
	
	CHECK_EQUAL(-1, studentString.find('&'));	
}

TEST(extractIDTest, string){
	std::string currentStudent = "John Doe;1234";
	size_t semicolonPos = currentStudent.find(';');	
	CHECK_EQUAL("1234", currentStudent.substr(semicolonPos+1, currentStudent.size()));
}

TEST(getNextStudentTest, student){
	std::string studentString = "John Doe;1234,James Bond;7,Tracy Brown;177,Jack Smith;172,Jim Black,Tim White;88";
	std::string currentStudent = getNextStudent(studentString);
	CHECK_EQUAL("John Doe;1234", currentStudent);
	currentStudent = getNextStudent(studentString);
	CHECK_EQUAL("James Bond;7", currentStudent);
	currentStudent = getNextStudent(studentString);
	CHECK_EQUAL("Tracy Brown;177", currentStudent);
	currentStudent = getNextStudent(studentString);
	CHECK_EQUAL("Jack Smith;172", currentStudent);
	currentStudent = getNextStudent(studentString);
	CHECK_EQUAL("Jim Black", currentStudent);
	currentStudent = getNextStudent(studentString);
	CHECK_EQUAL("Tim White;88", currentStudent);
	currentStudent = getNextStudent(studentString);
	CHECK_EQUAL("", currentStudent);
}

TEST(extractNameTest, student){
	std::string currentName = extractName("John Doe;1234");
	CHECK_EQUAL("John Doe", currentName);
	currentName = extractName("James Bond;7");
	CHECK_EQUAL("James Bond", currentName);
	currentName = extractName("Tracy Brown;177");
	CHECK_EQUAL("Tracy Brown", currentName);
	currentName = extractName("Jack Smith;172");
	CHECK_EQUAL("Jack Smith", currentName);
	currentName = extractName("Jim Black");
	CHECK_EQUAL("Jim Black", currentName);
	currentName = extractName("Tim White;88");
	CHECK_EQUAL("Tim White", currentName);
	currentName = extractName("");
	CHECK_EQUAL("", currentName);
}

TEST(extractIdTest, student){
	std::string currentName = "John Doe;1234";
	int currentId = extractId(currentName);
	CHECK_EQUAL(1234, currentId);
	currentName = "James Bond;7";
	currentId = extractId(currentName);
	CHECK_EQUAL(7, currentId);
	currentName = "Jack Smith;172";
	currentId = extractId(currentName);
	CHECK_EQUAL(172, currentId);
	currentName = "Jim Black";
	currentId = extractId(currentName);
	CHECK_EQUAL(0, currentId);
	currentName = "Tim White;88";
	currentId = extractId(currentName);
	CHECK_EQUAL(88, currentId);
}

TEST(sortParseStudentsTest, student){
	std::string studentString = "John Doe;1234,James Bond;7,Tracy Brown;177,Jack Smith;172,Jim Black,Tim White;88";
	std::vector<Student> students = parseStudents(studentString);

	CHECK_EQUAL(students[0].getName(), "Jack Smith");
	CHECK_EQUAL(students[1].getName(), "James Bond");
	CHECK_EQUAL(students[2].getName(), "Jim Black");
	CHECK_EQUAL(students[3].getName(), "John Doe");
	CHECK_EQUAL(students[4].getName(), "Tim White");
	CHECK_EQUAL(students[5].getName(), "Tracy Brown");
}

TEST(stringToInt, string){
	// sanity check for converting from string to int
	std::stringstream ss;
	std::string stringInt = "55";
	
	int intFromString = 0;
	
	ss << stringInt;
	ss >> intFromString;
	
	CHECK_EQUAL(55, intFromString);
}

TEST(toLowerTest, string){
	std::string abcd = "ABCD";
	std::transform(abcd.begin(), abcd.end(), abcd.begin(), ::tolower);
	CHECK_EQUAL(abcd, "abcd");	
}

TEST(basicStringCompare, string){
	std::string bob = "bob";
	std::string charles = "charles";
	std::string pete = "pete";
	CHECK(pete > bob);
	CHECK(pete > charles);
	CHECK(charles > bob);
}