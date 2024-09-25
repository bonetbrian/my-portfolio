#include<iostream>
#include "LinkedBag.cpp"
using namespace std;

int main() {
    LinkedBag<int> myList;

    // Agregar elementos a myList
    myList.add(34);
    myList.add(68);
    myList.add(18);
    myList.add(39);
    myList.add(27);
    myList.add(89);
    myList.add(12);

    // Imprimir myList antes de la división
    cout << "Lista original:\n";
    myList.display();
    cout << endl;

    // Definir el valor de anEntry
    int anEntry = 18;

    // Dividir la lista en myList y otherList
    LinkedBag<int> otherList = myList.divideAt(anEntry);

    // Imprimir myList después de la división
    cout << "Lista original después de dividir en " << anEntry << ":\n";
    myList.display();
    cout << endl;

    // Imprimir otherList
    cout << "Lista otherList después de dividir en " << anEntry << ":\n";
    otherList.display();
    cout << endl;

    // Verificar si el valor de anEntry existe en myList
    if (myList.contains(anEntry)) {
        cout << "El elemento " << anEntry << " está dentro de la lista original\n";
    }
    else {
        cout << "El elemento " << anEntry << " no se encuentra dentro de la lista original\n";
    }

    // Definir otro valor de anEntry
    anEntry = 90;

    // Dividir la lista en myList y otherList para anEntry = 90
    otherList = myList.divideAt(anEntry);

    // Imprimir myList después de la división para anEntry = 90
    cout << "\nLista original después de dividir en " << anEntry << ":\n";
    myList.display();
    cout << endl;

    // Imprimir otherList para anEntry = 90
    cout << "Lista otherList después de dividir en " << anEntry << ":\n";
    otherList.display();
    cout << endl;

    // Verificar si el valor de anEntry existe en myList para anEntry = 90
    if (myList.contains(anEntry)) {
        cout << "El elemento " << anEntry << " está dentro de la lista original\n";
    }
    else {
        cout << "El elemento " << anEntry << " no se encuentra dentro de la lista original\n";
    }

    return 0;
}
