//
//  circle.cpp
//  Assignment 1
//
//  Created by Steve Minor on 1/12/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#include "circle.h"

Circle::Circle(int radius, int xCoord, int yCoord, const char * name):
	mRadius(radius),
	mXCoord(xCoord),
	mYCoord(yCoord),
	mName(name){};

Circle::Circle(Circle* c):
	mRadius(c->mRadius),
	mXCoord(c->mXCoord),
	mYCoord(c->mYCoord),
	mName(c->mName){};

Circle::~Circle(){};

const int Circle::getXCoord() const{
	return mXCoord;
}

const int Circle::getYCoord() const{
	return mYCoord;
}

const int Circle::getRadius() const{
	return mRadius;
}

const char * Circle::getName() const{
	return mName;
}

void Circle::setXCoord(int c){
	mXCoord = c;
}

void Circle::setYCoord(int c){
	mYCoord = c;
}

void Circle::setRadius(int rad){
	mRadius	= rad;
}

Circle& Circle::operator+=(Circle&c){
	this->mRadius += c.getRadius();
	return *this;
}

Circle& Circle::operator-=(Circle&c){
	this->mRadius -= c.getRadius();
	return *this;
}

Circle& Circle::operator+(Circle&c){
	this->mRadius += c.getRadius();
	return *this;
}

Circle& Circle::operator-(Circle&c){
	this->mRadius -= c.getRadius();
	return *this;
}

Circle& Circle::operator++(){
	this->mRadius++;
	return *this;
}

Circle Circle::operator++(int){
	Circle tmp(this);
	operator++();
	return tmp; //out of scope?
}

Circle& Circle::operator--(){
	this->mRadius--;
	return *this;
}

Circle Circle::operator--(int){
	Circle tmp(this);
	operator--();
	return tmp; //out of scope?
}

std::ostream& operator<<(std::ostream& os, const Circle& c){
	os << "name: " << c.getName() << ", radius: " << c.getRadius() << ", x: " << c.getXCoord()
		<< ", y: " << c.getYCoord();
	
	return os;
}
