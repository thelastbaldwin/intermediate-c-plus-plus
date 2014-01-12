#include <sstream>
#include "circle.h"
#include "TestHarness.h"

TEST(defaultInitTest, circle){
	Circle c(1);
	CHECK_EQUAL(1, c.getRadius());
	CHECK_EQUAL(0, c.getXCoord());
	CHECK_EQUAL(0, c.getYCoord());
	CHECK_EQUAL(NULL, c.getName());
}

TEST(initTest, circle){
	Circle c(1, 2, 3, "circly");
	CHECK_EQUAL(1, c.getRadius());
	CHECK_EQUAL(2, c.getXCoord());
	CHECK_EQUAL(3, c.getYCoord());
	CHECK_EQUAL("circly", c.getName());
}

TEST(streamOperatorTest, circle){
	std::stringstream ss;
	Circle c(1, 2, 3, "circly");	
	ss << c;
	CHECK_EQUAL("name: circly, radius: 1, x: 2, y: 3", ss.str());
}

TEST(operatorPlusEqualTest, circle){
	Circle c(1, 2, 3, "circly");
	Circle c2(2, 3, 4, "circler");
	c+=c2;
	CHECK_EQUAL(3, c.getRadius());
}

TEST(addTest, circle){
	Circle c(1, 2, 3, "circly");
	Circle c2(2, 3, 4, "circler");
	Circle c3 = c + c2;
	CHECK_EQUAL(3, c3.getRadius());
}

TEST(minusTest, circle){
	Circle c(1, 2, 3, "circly");
	Circle c2(2, 3, 4, "circler");
	Circle c3 = c - c2;
	CHECK_EQUAL(-1, c3.getRadius());
}

TEST(prefixAddTest, circle){
	Circle c(1, 2, 3, "circly");
	++c;
	CHECK_EQUAL(2, c.getRadius());
}

TEST(postFixAddTest, circle){
	Circle c(1, 2, 3, "circly");
	Circle c2 = c++;
	CHECK_EQUAL(2, c.getRadius());
	CHECK_EQUAL(1, c2.getRadius());
}

TEST(prefixSubTest, circle){
	Circle c(1, 2, 3, "circly");
	--c;
	CHECK_EQUAL(0, c.getRadius());
}

TEST(postFixSubTest, circle){
	Circle c(1, 2, 3, "circly");
	Circle c2 = c--;
	CHECK_EQUAL(0, c.getRadius());
	CHECK_EQUAL(1, c2.getRadius());
}