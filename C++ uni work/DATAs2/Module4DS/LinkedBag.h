/*

#include <iostream>
#include "LinkedBag.h"

using namespace std;

template<class ItemType>
LinkedBag<ItemType> LinkedBag<ItemType>::divideAt(const ItemType& anEntry) {
    LinkedBag<ItemType> otherList; // Creamos una nueva LinkedBag para almacenar los elementos después de anEntry

    Node<ItemType>* previousPtr = nullptr;
    Node<ItemType>* currentPtr = headPtr;

    // Buscamos el nodo que contiene el valor anEntry
    while (currentPtr != nullptr && currentPtr->getItem() != anEntry) {
        previousPtr = currentPtr;
        currentPtr = currentPtr->getNext();
    }

    if (currentPtr != nullptr) {
        // Si encontramos el nodo con el valor anEntry, dividimos la lista
        if (previousPtr != nullptr) {
            previousPtr->setNext(nullptr); // Dividimos la lista estableciendo el siguiente nodo del nodo anterior a nullptr
        } else {
            headPtr = nullptr; // Si el nodo encontrado es el primer nodo, establecemos headPtr a nullptr
        }

        otherList.headPtr = currentPtr; // Establecemos el headPtr de otherList al nodo actual
        otherList.itemCount = itemCount - 1; // Actualizamos el recuento de elementos en otherList

        itemCount = 1; // Actualizamos el recuento de elementos en la lista actual

        return otherList;
    } else {
        // Si no encontramos el valor anEntry, devolvemos una lista vacía
        return LinkedBag<ItemType>();
    }
}

int main() {
    // Definimos las dos listas
    LinkedBag<int> myList;
    LinkedBag<int> otherList;

    // Agregamos elementos a la lista
    myList.add(34);
    myList.add(68);
    myList.add(18);
    myList.add(39);
    myList.add(27);
    myList.add(89);
    myList.add(12);

    // Definimos el valor de anEntry
    int anEntry = 18;

    // Dividimos la lista en base a anEntry
    otherList = myList.divideAt(anEntry);

    // Imprimimos el contenido de ambas listas
    cout << "Contenido de myList después de dividir en " << anEntry << ": ";
    myList.display();
    cout << endl;

    cout << "Contenido de otherList después de dividir en " << anEntry << ": ";
    otherList.display();
    cout << endl;

    // Definimos un nuevo valor de anEntry
    anEntry = 90;

    // Intentamos dividir la lista en base a anEntry (que no está en la lista)
    otherList = myList.divideAt(anEntry);

    // Imprimimos el contenido de ambas listas
    cout << "Contenido de myList después de dividir en " << anEntry << ": ";
    myList.display();
    cout << endl;

    cout << "Contenido de otherList después de dividir en " << anEntry << ": ";
    otherList.display();
    cout << endl;

    return 0;
}


*/