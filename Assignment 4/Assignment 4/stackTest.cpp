#include "TestHarness.h"
#include "stack.h"

TEST(intStackPushPopTest, Stack){
	Stack<int> intStack(10);
	
	intStack.push(1);
	intStack.push(2);
	intStack.push(3);
	intStack.push(4);
	intStack.push(5);
	intStack.push(6);
	
	CHECK_EQUAL(6, intStack.size());
	CHECK_EQUAL(1, intStack.pop());
	CHECK_EQUAL(2, intStack.pop());
	CHECK_EQUAL(3, intStack.pop());
	CHECK_EQUAL(4, intStack.pop());
	CHECK_EQUAL(5, intStack.pop());
	CHECK_EQUAL(6, intStack.pop());
	
	try{
		intStack.pop();
	}
	catch(std::exception& e){
		//when I catch my specific exception "e.what() is a private method." Why?
		CHECK_EQUAL(e.what(), "stack empty");
	}
	
	CHECK_EQUAL(0, intStack.size());
}

TEST(intStackPushTest, Stack){
	Stack<int> intStack(10);
	
	intStack.push(1);
	intStack.push(2);
	intStack.push(3);
	intStack.push(4);
	intStack.push(5);
	intStack.push(6);
	intStack.push(7);
	intStack.push(8);
	intStack.push(9);
	intStack.push(10);
	
	CHECK_EQUAL(10, intStack.size());
	
	intStack.push(11); //should not through error
	
//	before adding resize functionality
//	try{
//		intStack.push(11);
//	}
//	catch(std::exception& e){
//		//when I catch my specific exception "e.what() is a private method." Why?
//		CHECK_EQUAL(e.what(), "stack full");
//	}
}

TEST(intStackAssignmentTest, Stack){
	Stack<int> intStack(5);	
	intStack.push(1);
	intStack.push(2);
	intStack.push(3);
	intStack.push(4);
	intStack.push(5);
	
	Stack<int> intStackB(intStack); //copy constructor
	CHECK_EQUAL(intStackB.size(), 5);
	
	Stack<int> intStackC(3);
	intStackC = intStackB; //assignment operator
	intStackB.pop();
	CHECK_EQUAL(intStackC.size(), 5);	
}

TEST(mixedAssignmentTest, Stack){
	Stack<float> floatStack(10);
	floatStack.push(1.1);
	floatStack.push(2.2);
	floatStack.push(3.3);
	floatStack.push(4.4);
	floatStack.push(5.5);
	
	Stack<int> intStack(10);
	
	intStack = floatStack;
	CHECK_EQUAL(intStack.pop(), 1);
}