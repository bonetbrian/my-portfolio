/*
* CECS 2203, Computer Programming I Laboratory
* Spring 2023, Sec. 06
* Date: March 16, 2023
* Topic: Lab 1 - Selection Control Structures
* File name: lab01.cpp
*
* Instructions and problem statement:
* A college professor needs a solution to compute a student's final letter grade.
* Each student has scores for three 100-point exams. The rubric to be used is:
* -If the final grade is greater than 88, the student earns an A
* -If the final grade is greater than 78, but less than 89, the student earns a B
* -If the final grade is greater than or equal to 69, but less than 79, the student earns a C
* -If the final grade is greater than 58, but less than or equal to 68, the student earns a D
* -If the final grade is less than 59, the student is awarded an F
* The solution must first compute a student's final average, after obtaining all three scores.
* The final average will then be submitted to the rubric, and the final output will be the letter grade.
*
* Complete the program by writing the correct C++ statements.
*
* You should execute the program five times to make sure that all letter grades (A,B,C,D,F) are
* possible. Save a screenshot for each instance of the program's execution, and include them in your report.
*
* Name: Brian Bonet Medina, #119461
*/
// write the appropriate preprocessor directive
#include <iostream>

// write the appropriate using directive
using namespace std;

int main() {
	// Write the statement that declares the integer variables named
	// finalAverage, score1, score2, score3 and initializes them to 0 
	int finalAverage = 0, score1 = 0, score2 = 0, score3=0;
	// Write the statement that declares a character variable named
	// letterGrade and initializes it to X
	char letterGrade('X');

	// Prompt the user to enter the three test scores, storing the
	// values in the appropriate variables
	// Use the phrase "Enter the score for test #1: "
	// The change the number to 2 and 3 respectively 
	do
	{


		cout << "Enter the score for test #1: ";
		cin >> score1;
		cout << "Enter the score for test #2: ";
		cin >> score2;
		cout << "Enter the score for test #3: ";
		cin >> score3;
		cout << endl;

		// compute the final average and assign the value to the correct variable

		finalAverage = (score1 + score2 + score3) / 3;

		// Using an if / else if / else selection control structure
		// implement the rubric to obtain the correct value for the letter grade 
		// and store the value in the appropriate variable. Use only single conditions.
		if (finalAverage > 88)
			letterGrade = 'A';
		else if (finalAverage > 78)//corrected
			letterGrade = 'B';
		else if (finalAverage > 68)
			letterGrade = 'C';
		else if (finalAverage > 58)
			letterGrade = 'D';
		else if (finalAverage < 58)
			letterGrade = 'F';
		else;

		// print the following phrase, substituting the square brackets and 
		// the text within with the correct values:
		// "The student with test scores [score1], [score2], and [score3], 
		// scored a final average of [finalAverage] and earned a(n) [letterGrade]."
		cout << "The student with test scores " << score1 << ", " << score2 << ", " << "and " << score3 << endl
			<< "scored a final average of " << finalAverage << " and earned a(n) " << letterGrade << '.' << endl << endl;
		cout << "Do you wish to compute another average?\n" <<
			"Enter 0 to finish or any other number to continue.";
			cin >> finalAverage;
			cout << endl<<endl;
	} while (finalAverage != 0);


	// write a statement which prints the phrase
	// "Program developed by [YOUR NAME], ID#[YOUR ID NUMBER]"
	// where the square brackets and the text within is substituted with
	// your personal information.

	cout << "Program developed by Brian Bonet, ID# 119461" << endl;

	system("pause"); // for Visual Studio only
	return 0;
}