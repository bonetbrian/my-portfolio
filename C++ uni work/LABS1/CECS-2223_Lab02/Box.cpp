/*
* CECS 2223, Computer Programming II Laboratory
* Fall 2023, Sec. 09
* Date: August 23, 2023
* Topic: Parameterized Constructors and Class Variables
* File name: Box.cpp
* Name: Brian Bonet Medina, ID#119461
* This file defines the Box class
*/
// do we need any preprocessor directives?
#include "Box.h"
// initialize the class variable to 0
int Box::boxCount = 0;
// Define the default constructor; assign -1 to all fields
// and increments the value of the class variable
Box::Box() : height(-1), width(-1), length(-1) {
	boxCount++;
}
// The parameterized constructors assign the parameter's value 
// to the fields only if the value is valid. Use the ternary, or
// conditional, operator for the assignment operation, using 0
// as the value to be assigned when the condition is false. The  
// parameters represent the values for the fields in the height, 
// width, and length order. For example, the constructor with one
// parameter receives the value for height, and the one with two
// parameters receives the values for height and width. 
// Recall that all constructors must invrement the class variable
Box::Box(int h){
	height = (h > 0 ? h :0);
	width = 0;
	length = 0;
	boxCount++;
}
Box::Box(int h, int w){
	height = (h > 0 ? h: 0);
	width = (w > 0 ? w : 0);
	length = 0;
	boxCount++;
}
Box::Box(int h, int w, int l){
	height = (h > 0 ? h : 0);
	width = (w > 0 ? w : 0);
	length = (l > 0 ? l : 0);
	boxCount++;
}


// The copy constructor assigns the attribute values of the parameter 
// to the new object and increments the value of the class variable.
Box::Box(const Box& aBox){
	height = aBox.getHeight();
	width = aBox.getWidth();
	length = aBox.getLength();
	boxCount++;
}

// The destructor does not include any code, it is defined
Box::~Box() { }

// The set methods DO NOT prompt the user for values or include
// any cout or printf statements. Make sure that the values 
// received as parameters are valid. Use the ternary, or
// conditional, operator for the assignment operation, using the
// current value of the field as the option when the condition 
// is false. The setter methods have no return value.
void Box::setHeight(int h) {
	height = (h > 0 ? h : 0);
}
void Box::setWidth(int w) {
	width = (w > 0 ? w : 0);
}
void Box ::setLength(int l) {
	length = (l > 0 ? l : 0);
}
// define the get methods, they should all be constant
int Box::getHeight()const {
	return height;
}
int Box::getWidth()const {
	return width;
}
int Box::getLength()const {
	return length;
}
int Box::getVolume()const {
	return height * width * length;
}
int Box::getBoxCount()const {
	return boxCount;
}
// The printBox method uses printf to output values formatted
// to be displayed in a table at 8 spaces per column aligned to
// the left of the column. The values to be displayed are: height, 
// width, length, and volume. All values must be printed in the
// same line. 
void Box::printBox() const {
	printf("%-8d%-8d%-8d%-8d\n", getHeight(), getWidth(), getLength(),getVolume());
}