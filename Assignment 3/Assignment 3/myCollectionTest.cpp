#include "myCollection.h"
#include "TestHarness.h"

#include <sstream>

TEST(myCollectionInt, myCollection){
	
	std::stringstream ss;
	myCollection<int> intCollection;
	intCollection.add(5);
	intCollection.add(4);
	intCollection.add(3);
	intCollection.add(2);
	intCollection.add(1);
	
	intCollection.printAll(ss);
	CHECK_EQUAL(ss.str(), "54321");
}