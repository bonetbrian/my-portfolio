/*
* CECS 2223, Computer Programming II Laboratory
* Fall 2023
* Date: September 27, 2023
* Topic: Lab 5 - Composition and Dynamic Memory
* File name: lab05.cpp
* This file implements a class named Catalog
* Complete the code as required.
* Name: Brian Bonet, ID#119461
* Name: Jose Rodriguez Colon, ID #127777
*
* To test your code, add at least 4 courses to the catalog, and remove at least 2.
* Start by selecting the option to print the catalog, then proceed to add courses,
* and finally remove courses. You should print the course list after every add or
* remove action.
*/
// preprocessor directives
#include "Catalog.h"
#include <string>


int menu();
bool execute(Catalog&, const int);
void personalInfo();

int main() {
	// declare a Catalog object name poli
	Catalog poli;
	int option;
	// Assign the string Polytechnic University of Puerto Rico as the name for poli
	poli.setUniversityName("Polytechnic University of Puerto Rico");
	// develop a while iteration control structure which uses the return value of the
	// execute method as sentinel. The execute method receive the reference to poli
	// and the return value of menu as parameters.
	// This must be a single line of code!
	// the sentinel of the while is the value of execute (return value of menu)
	while (execute(poli, (option = menu())));
		
	system("pause"); // For Visual Studio use only!
	return 0;
}

// The menu method presents the user with a list of options. They are:
// 1. View all courses in the catalog
// 2. Add a course to the catalog
// 3. Remove a course from the catalog
// 4. Exit the program
// Declare the local integer variable option and initialize if to 0
// This method DOES NOT validate the value received by the user,
// it only returns such value.
int menu() {
	int option = 0;
	cout << "Menu : " << endl
		<< "1. View all courses in catalog" << endl
		<< "2. Add a course to the catalog" << endl
		<< "3. remove a course from catalog" << endl
		<< "4. Exit the program" << endl
		<< "__________________________________"
		<< "\nEnter your choice: ";
	cin >> option;
	cout << endl;
	cout << "__________________________________\n";
	return option;
}

// The execute method implements a switch selection control structure to
// implement the menu option. It's parameters are a reference to a Catalog
// object and an integer representing the option selected by the user.
// The method returns false only when the option value is 4, true otherwise.
// The default case catches invalid option values and requires an error
// message to be printed.
bool execute(Catalog& catalog, const int option) {
	switch (option) {
	case 1:
		catalog.printCatalog();
		cout << endl;
		break;
	case 2: {
		string code, name;
		int credits;
		cin.ignore();
		cout << "Enter course code: ";
		getline(cin, code);
		cout << "Enter course name: ";
		getline(cin, name);
		cout << "Enter course credits: ";
		cin >> credits;
		cout << endl;
		cout << "Course added succesfully\n\n";
		catalog.addCourse(code, name, credits);
		cout << endl;
		break;
	}
	case 3: {
		string code;
		cin.ignore();
		cout << "Enter course code to remove: ";
		getline(cin, code);
		int index = catalog.findCourse(code);
		if (index != -1) {
			catalog.deleteCourse(index);
			cout << "\n\nCourse removed successfully.\n" << endl;
		}
		else {
			cout << "Course not found.\n" << endl;
		}
		break;
	}
	case 4: {
		personalInfo();//Call the personal Info method
		return false;// Exit the program after displaying info
	}
	

	  default: 
		  cout << "Invalid option. Please try again.\n" << endl;


	}
	return true;
	
}

// The personalInfo method prints the phrase
// Program developed by [name of student 1] and [name of student 2]. 
// make sure to add an empty line after the phrase is printed. this method will 
// return false if the value of the parameter is false opiton, make sure it prints out an Error message
// do not declare a boolean variable, only use true or false
void personalInfo() {
	cout << "\nExiting the proram.\n";
	cout << "Program Developed by:\n Brian Bonet Medina and Jose Rodriguez Colon \n\n";
}