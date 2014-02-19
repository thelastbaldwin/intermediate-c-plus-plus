#include "TestHarness.h"
#include "stack.h"

TEST(intStackPushPopTest, stack){
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
		CHECK_EQUAL(e.what(), "stack empty");
	}
	
	CHECK_EQUAL(0, intStack.size());
}

TEST(intStackPushTest, stack){
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
		
	try{
		intStack.push(11);
	}
	catch(std::exception& e){
		CHECK_EQUAL(e.what(), "stack full");
	}
}