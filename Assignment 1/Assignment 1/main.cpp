//
//  main.cpp
//  Assignment 1
//
//  Created by Steve Minor on 1/12/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#include "TestHarness.h"
#include "circle.h"
#include <stdlib.h>
#include <iostream>

//Assignment Code
//using namespace std;
//const int kMaxNameSize = 128;
//
//void CreateTwoCircles()
//{
//	char * name = new char [kMaxNameSize];
//	const char * kName1 = "Circle1";
//	const char * kName2 = "Circle2";
//	
//	strncpy_s( name, kMaxNameSize, kName1, _TRUNCATE );
//	Circle c1( 2, 1,1, name );
//	
//	strncpy_s( name, kMaxNameSize, kName2, _TRUNCATE );
//	Circle c2( 5, 1,1, name );
//	
//	cout << "c1 is " << c1 << endl; // Name printed: Circle1<%1-%-0%> cout << "c2 is " << c2 << endl; // Name printed: Circle2<%1-%-0%>
//	delete [] name;
//}
//
//void DoCircleAssignment( )
//{
//	char * name = new char [kMaxNameSize];
//	const char * kName1 = "Circle1";
//	const char * kName2 = "Circle2";
//	
//	strncpy_s( name, kMaxNameSize, kName1, _TRUNCATE );
//	Circle c1( 1, 0, 0, name );
//	cout << "c1 is " << c1 << endl;<%1-%-0%>
//	strncpy_s( name, sizeof( name ), kName2, _TRUNCATE );
//	Circle c2 ( 2, 1, 1);
//	
//	cout << "Before assignment, c2 is " << c2 << endl;<%1-%-0%>
//	c2 = c1;
//	
//	cout << "After assignment, c2 is " << c2 << endl;<%1-%-0%>
//	delete [] name;
//}
//
//void CircleTest()
//{
//	CreateTwoCircles( );
//	
//	DoCircleAssignment( );
//}

int main()
{
	// random number generator used in some tests
	srand(::time_t(NULL));
    
    TestResult tr;
    TestRegistry::runAllTests(tr);
	
	//CircleTest();
    
	// force console screen to hold
	char ch;
	std::cin >> ch;
    
    return 0;
}



