#include "Catalog.h"
#include <iostream>
using namespace std;

int main() {
    Catalog catalog;

    string universityName;
    cout << "Enter the name of the university: ";
    cin >> universityName;
    cin.ignore(); // Consume newline character
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
            cin >> code;
            cout << "Enter Course Name: ";
            cin >> name;
            cout << "Enter Credits: ";
            cin >> credits;
            catalog.addCourse(code, name, credits);
            break;
        }
        case 2: {
            string code;
            cout << "Enter Course Code to Remove: ";
            cin >> code;
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
            break;
        }
        default: {
            cout << "Invalid choice. Please try again.\n";
            break;
        }
        }

    } while (choice != 4);

    return 0;
}
