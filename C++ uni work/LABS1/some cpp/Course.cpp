/*
* CECS 2223, Computer Programming II Laboratory
* Fall 2023
* Date: September 27, 2023
* Topic: Lab 5 - Composition and Dynamic Memory
* File name: Course.cpp
* This file defines a class named Course
* Complete the declaration as required.
* Name: Brian Bonet
*       Jose Rodriguez Colon
*/
#include "Course.h"
#include <string>
// initialize class variables using the side of the header string
size_t Course::codeSize = 5; // The size of CODE + 1
size_t Course::nameSize = 5; // The size of NAME + 1

void Course::setCodeSize(string aCode, bool reduce) {
	if (reduce) {
		codeSize = aCode.size() + 1 > 5 ? aCode.size() + 1 : 5;
	}
	else {
		if (aCode.size() + 1 > getCodeSize())
			codeSize = aCode.size() + 1;
	}
}

void Course::setNameSize(string aName, bool reduce) {
	if (reduce) {
		nameSize = aName.size() + 1 > 5 ? aName.size() + 1 : 5;
	}
	else {
		if (aName.size() + 1 > getNameSize())
			nameSize = aName.size() + 1;
	}
}

Course::Course() {
	courseCode = "";
	courseName = "";
	credits = -1;
	setCodeSize(courseCode, true); // Call setCodeSize to initialize codeSize
	setNameSize(courseName, true); // Call setNameSize to initialize nameSize
}

Course::Course(string code, string name, int credits) {
	courseCode = code;
	setCodeSize(code, false);
	courseName = name;
	setNameSize(name, false);
	this->credits = credits > -1 ? credits : -1;
}

Course::Course(const Course& aCourse) {
	courseCode = aCourse.getCourseCode();
	courseName = aCourse.getCourseName();
	credits = aCourse.getCourseCredits();
}

Course::~Course() {
	cout << "\n\tThe Course object with code " << getCourseCode() << " has been destroyed.\n\n";
}

void Course::setCourseCode(string code) {
	courseCode = code;
}
void Course::setCourseName(string name) {
	courseName = name;
}
void Course::setCourseCredits(int credits) {
	// validates the parameter to be 0 or greater
	if (credits > -1)
		this->credits = credits;
}
string Course::getCourseCode() const {
	return courseCode;
}
string Course::getCourseName() const {
	return courseName;
}
int Course::getCourseCredits() const {
	return credits;
}
size_t Course::getCodeSize() const {
	return codeSize;
}
size_t Course::getNameSize() const {
	return nameSize;
}
void Course::displayCourse() const {
	// prints the course data ready for a table
	// the order is course code, course name, credits, and the size of the 
	// course and name fields is variable
	printf("%-*s%-*s%i\n", getCodeSize(), getCourseCode().c_str(), getNameSize(), getCourseName().c_str(), getCourseCredits());
}
bool Course::operator>(const Course& other) const {
	return getCourseCode() > other.getCourseCode();
}