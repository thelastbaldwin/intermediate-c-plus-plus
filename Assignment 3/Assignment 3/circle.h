//
//  circle.h
//  Assignment 1
//
//  Created by Steve Minor on 1/12/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#ifndef __Assignment_1__circle__
#define __Assignment_1__circle__

#include <iostream>

class Circle
{
public:
	Circle(int radius,
		   int xCoord = 0, int yCoord = 0,
		   const char * name = NULL );
	Circle(Circle* c);
	~Circle();
	
	const int getXCoord() const;
	const int getYCoord() const;
	const int getRadius() const;
	const char * getName() const;
	
	void setXCoord(int c);
	void setYCoord(int c);
	void setRadius(int rad);
	
	Circle& operator+=(Circle&c);
	Circle& operator-=(Circle&c);
	Circle& operator+(Circle&c);
	Circle& operator-(Circle&c);
	Circle& operator++(); //prefix (++Circle)
	Circle operator++(int); //postfix (Circle++)
	Circle& operator--(); //prefix (--Circle)
	Circle operator--(int); //postfix (Circle++)
	
private:
	int mXCoord;
	int mYCoord;
	int mRadius;
	const char * mName;	// this stores the name of the circle
};

std::ostream& operator<<(std::ostream& os, const Circle& c);

#endif /* defined(__Assignment_1__circle__) */
