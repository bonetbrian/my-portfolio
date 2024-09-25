#include <iostream>
#include "LinkedList.h"

using namespace std;

// Function prototypes
void displayMenu();
void displayList(const LinkedList<int>& list);
void displayListReverse(const LinkedList<int>& list);

int main() {
    LinkedList<int> list;
    int option;
    int position, value;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
        case 1:
            cout << "Enter value to add: ";
            cin >> value;
            list.insert(1, value);
            break;
        case 2:
            if (!list.isEmpty()) {
                cout << "Enter position to remove: ";
                cin >> position;
                list.remove(position);
            }
            else {
                cout << "List is empty." << endl;
            }
            break;
        case 3:
            cout << "List from beginning to end: ";
            displayListReverse(list);
            break;
        case 4:
            cout << "List from end to beginning: ";
            displayList(list);
            break;
        case 5:
            cout << "Quitting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (option != 5);

    return 0;
}

void displayMenu() {
    cout << "\nOptions Menu:" << endl;
    cout << "1. Add" << endl;
    cout << "2. Remove" << endl;
    cout << "3. Display the list from beginning to end" << endl;
    cout << "4. Display the list from end to beginning" << endl;
    cout << "5. Quit the program" << endl;
}

void displayList(const LinkedList<int>& list) {
    for(int i = 1; i <= list.getLength(); ++i) {
        cout << list.getEntry(i) << " ";
    }
    cout << endl;
}

void displayListReverse(const LinkedList<int>& list) {
    for(int i = list.getLength(); i >= 1; --i) {
        cout << list.getEntry(i) << " ";
    }
    cout << endl;
}