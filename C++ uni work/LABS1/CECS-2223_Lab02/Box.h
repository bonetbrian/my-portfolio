/*
* CECS 2223, Computer Programming II Laboratory
* Fall 2023, Sec. 09
* Date: August 23, 2023
* Topic: Parameterized Constructors and Class Variables
* File name: Box.h
* This file declares a class named Box
* This file requires no changes
*/
#pragma once
#include <iostream>
using namespace std;

class Box {
private:
	static int boxCount;
	int height;
	int width;
	int length;
public:
	Box();					//default
	Box(int);				//1 parameter 
	Box(int, int);			//2 parameter
	Box(int, int, int);		//3 parameter
	Box(const Box&);		//copy
	~Box();					//desturctor

	// setter and getters
	void setHeight(int);
	void setWidth(int);
	void setLength(int);
	int getHeight() const;
	int getWidth() const;
	int getLength() const;
	int getVolume() const;
	int getBoxCount() const;

	// pirnt method
	void printBox() const;
};
