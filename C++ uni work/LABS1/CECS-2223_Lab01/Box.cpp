/*
* CECS 2223, Computer Programming II Laboratory
* Fall 2023, Sec. 09
* Date: August 15, 2023
* Topic: OOD Review
* File name: Box.cpp
* Name: [Brian Bonet], ID#119461]
* This file defines the Box class
*/
// do we need any preprocessor directives?
#include "Box.h";
// define the default constructor; assign 0 to all fields
Box::Box() {
	length = 0;
	width = 0;
	height = 0;
}
// The set methods DO NOT prompt the user for values
// or include any cout or printf statements.
// Make sure that the values received as parameters
// are valid.
void Box::setLength(int aLength) {
			length = aLength;
}
void Box::setHeight(int aHeight) {
			height = aHeight;
}
void Box::setWidth(int aWidth) {
	width = aWidth;
}
// define the get methods, they should all be constant
int Box::getLength() const {
		return length;
}
int Box::getWidth() const {
	return width;
}
int Box::getHeight() const {
	return height;
}
int Box::getArea() const {
	return 2*(length * height)+2*(length*width)+2*(width*height);
}
int Box::getVolume() const {
	return length * width * height;
}

// The printBox method uses printf to output values formatted
// to be displayed in a table, 8 spaces per column.
// The values to be displayed are: height, width, length,
// area, and volume. All values must be 
// printed in the same line.
void Box::printBox() {
	printf("%i\t%i\t%i\t%i\t%i.\n",
		getHeight(), getWidth(), getLength(), getArea(), getVolume());
}