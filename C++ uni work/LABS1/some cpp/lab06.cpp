/*
* CECS 2223, Computer Programming II Laboratory
* Fall 2023
* Date: September 27, 2023
* Topic: Lab 6 - Composition and Dynamic Memory
* File name: lab06.cpp
* This file declares a class named Course
* Complete the declaration as required.
* Name: Brian Bonet
*       Jose Rodriguez Colon
*/
#include "Catalog.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    Catalog catalog;

    string universityName;
    cout << "Enter the name of the university: ";
    getline(cin,universityName);
   // Consume newline character
    catalog.setUniversityName(universityName);

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add Course\n";
        cout << "2. Remove Course\n";
        cout << "3. Print Catalog\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string code, name;
            int credits;
            cout << "Enter Course Code: ";
            cin.ignore();
            getline(cin,code);
            cout << "Enter Course Name: ";
            getline(cin, name);
            cout << "Enter Credits: ";
            cin >> credits;
            catalog.addCourse(code, name, credits);
            break;
        }
        case 2: {
            string code;
            cout << "Enter Course Code to Remove: ";
            cin.ignore();
            getline(cin,code);
            int index = catalog.findCourse(code);
            if (index != -1) {
                catalog.deleteCourse(index);
                cout << "Course removed successfully.\n";
            }
            else {
                cout << "Course not found.\n";
            }
            break;
        }
        case 3: {
            catalog.printCatalog();
            break;
        }
        case 4: {
            cout << "Exiting program.\n";
            cout << "Program designed by: Brian Bonet & Jose Rodriguez Colon\n";
            break;
        }
        default: {
            cout << "Invalid choice. Please try again.\n";
            
        }
        }

    } while (choice != 4);

    return 0;
}
