//
//  main.cpp
//  Assignment 2
//
//  Created by Steve Minor on 1/18/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#include <iostream>
#include "TestHarness.h"

int main()
{
	// random number generator used in some tests
	srand(::time_t(NULL));
    
    TestResult tr;
    TestRegistry::runAllTests(tr);
	
    
	// force console screen to hold
	char ch;
	std::cin >> ch;
    
    return 0;
}
