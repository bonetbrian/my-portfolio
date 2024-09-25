#include<iostream>
#include<string>

using namespace std;
#include "Linkedlist.h"

int main() {

	LinkedList <string> myArray;

	myArray.insert(1, "Mayo");
	myArray.insert(2, "Papitas");
	myArray.insert(3, "Galletas");
	myArray.insert(4, "Sodas");
	cout << "Imprime el contenido de la lista original\n";
	for (int index = 1; index <= myArray.getLength(); index++) {
		cout << myArray.getEntry(index) << endl;
	}//end for
	cout << endl;

	myArray.insert(2, "Gomitas");
	cout << "Anade las Gomitas en el indice 2\n";
	for (int index = 1; index <= myArray.getLength(); index++) {
		cout << myArray.getEntry(index) << endl;
	}//end for

	cout << "\n";
	myArray.remove(3);
	cout << "Elimie el elemento de la posicion 3\n";
	for (int index = 1; index <= myArray.getLength(); index++) {
		cout << myArray.getEntry(index) << endl;
	}//end for

	myArray.insert(2, "Chocolate");
	cout << "Anade Chocolate en posicion 2\n";
	for (int index = 1; index <= myArray.getLength(); index++) {
		cout << myArray.getEntry(index) << endl;
	}//end for
	system("pause");
}
