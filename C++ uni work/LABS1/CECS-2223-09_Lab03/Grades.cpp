/*
* CECS 2223, Computer Programming II Laboratory
* Fall 2023, Sec. 09
* Date: August 30, 2023
* Topic: Lab 3
* File name: Grades.cpp
* Brian Bonet Medina, 119461
*/
#include "Grades.h"

Grades::Grades() {					//default
	scores = new int[TESTS]{ 0 };
}

Grades::Grades(const int* scores) {	//copy
	this->scores = new int[TESTS];
	for (int i = 0; i < TESTS; i++) {
		this->scores[i] = scores[i];
	}
}

Grades::~Grades() { //deconstructor
}

void Grades::getScores(int student) {	//getScore method

	for (int i = 0; i < TESTS; i++) {
		do {
			cout << "Enter the scores for student #" << student << ", test #" << i+1 << ": ";
			cin >> scores[i];
		} while (scores[i] < 0 || scores[i]>100);
	}
	
}

char Grades::getGrade(int score) const {	//getGrades assigns per value
	
	if (score < 59) {
		return 'F';
	}
	if (score < 69) {
		return 'D';
	}
	if (score < 79) {
		return 'C';
	}
	if (score < 89) {
		return 'B';
	}
	else {
		return 'A';
	}
}

int Grades::getAverage() const { // gets average of 3 tests
	int total = 0;
	for (int i = 0; i < TESTS; i++) {
		total += scores[i];
	}
	return total / TESTS;
}
 

int Grades::setScore(int index)  {
	return scores[index];
}


void Grades::printGrades(int studentNumber)const{ // prints with all the values and grade score

	int avscore = getAverage();
	char grade = getGrade(avscore);

	printf("\n Student # %i ,with test scores %i, %i, and %i, scored a final average of %d and earned a(n) %c.\n\n",
		studentNumber, scores[0], scores[1], scores[2], avscore,grade);
}

