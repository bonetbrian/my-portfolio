/*
* CECS 2223, Computer Programming II Laboratory
* Fall 2023, Sec. 09
* Date: August 30, 2023
* Topic: Lab 3
* File name: Grades.h
* Brian Bonet Medina, 119461
*/
#pragma once
#include <iostream>
using namespace std;

class Grades {
public:
	static const int TESTS = 3;

	Grades();					//default
	Grades(const int* scores);  //copy 
	~Grades();                  //destructor

	void getScores(int);
	int setScore(int);
	int getAverage() const;
	char getGrade(int) const;
	void printGrades(int) const;
	
private:

	int* scores;

};