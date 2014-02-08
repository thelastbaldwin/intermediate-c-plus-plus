#include "myCollection.h"
#include "TestHarness.h"
#include "circle.h"

#include <sstream>
#include <string>

TEST(myCollectionInt, myCollection){
	
	std::stringstream ss;
	myCollection<int> intCollection;
	
	CHECK(intCollection.isEmpty());
	
	intCollection.add(5);
	intCollection.add(4);
	intCollection.add(3);
	intCollection.add(2);
	intCollection.add(1);
	
	intCollection.printAll(ss);
	CHECK_EQUAL(ss.str(), "54321");
	
	ss.str("");
	intCollection.printReverseOrder(ss);
	CHECK_EQUAL(ss.str(), "12345");
	
	CHECK(!intCollection.isEmpty());
	CHECK_EQUAL(intCollection.count(), 5);
}

TEST(myCollectionString, myCollection){
	std::stringstream ss;
	myCollection<std::string> stringCollection;
	
	CHECK(stringCollection.isEmpty());
	
	stringCollection.add("a");
	stringCollection.add("A");
	stringCollection.add("b");
	stringCollection.add("B");
	stringCollection.add("c");
	stringCollection.add("C");
	stringCollection.add("d");
	stringCollection.add("D");
	
	stringCollection.printAll(ss);
	CHECK_EQUAL(ss.str(), "aAbBcCdD");
	
	ss.str("");
	stringCollection.printReverseOrder(ss);
	CHECK_EQUAL(ss.str(), "DdCcBbAa");
	
	CHECK(!stringCollection.isEmpty());
	CHECK_EQUAL(stringCollection.count(), 8);
}

TEST(myCollectioncircle, myCollection){
	std::stringstream ss;
	myCollection<Circle> circleCollection;
		
	CHECK(circleCollection.isEmpty());
	
	Circle c1(5, 2, 4, "c1");
	Circle c2(4, 2, 4, "c2");
	Circle c3(3, 2, 4, "c3");
	Circle c4(2, 2, 4, "c4");
	
	circleCollection.add(c1);
	circleCollection.add(c2);
	circleCollection.add(c3);
	circleCollection.add(c4);
	
	CHECK_EQUAL(circleCollection.count(), 4);
	circleCollection.printAll(ss);
	CHECK_EQUAL("name: c1, radius: 5, x: 2, y: 4name: c2, radius: 4, x: 2, y: 4name: c3, radius: 3, x: 2, y: 4name: c4, radius: 2, x: 2, y: 4", ss.str());
	ss.str("");
	circleCollection.printReverseOrder(ss);
	CHECK_EQUAL("name: c4, radius: 2, x: 2, y: 4name: c3, radius: 3, x: 2, y: 4name: c2, radius: 4, x: 2, y: 4name: c1, radius: 5, x: 2, y: 4", ss.str());
}