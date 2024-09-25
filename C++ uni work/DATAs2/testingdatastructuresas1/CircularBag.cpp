

#include "LinkedBag.h" // Assuming LinkedBag base code is provided

template<class ItemType>
class CircularBag : public LinkedBag<ItemType> {
private:
    Node<ItemType>* tailPtr; // Pointer to the last node

public:
    CircularBag(); // Constructor

    void add(const ItemType& item); // Add a node at the end of the list
    void remove(); // Remove a node from the beginning of the list
};

template<class ItemType>
CircularBag<ItemType>::CircularBag() : tailPtr(nullptr) {}

template<class ItemType>
void CircularBag<ItemType>::add(const ItemType& item) {
    Node<ItemType>* newNodePtr = new Node<ItemType>(item);
    if (LinkedBag<ItemType>::isEmpty()) {
        this->headPtr = newNodePtr;
        tailPtr = newNodePtr;
        tailPtr->setNext(newNodePtr);
    }
    else {
        tailPtr->setNext(newNodePtr);
        tailPtr = newNodePtr;
        tailPtr->setNext(this->headPtr);
    }
    this->itemCount++;
}

template<class ItemType>
void CircularBag<ItemType>::remove() {
    if (!LinkedBag<ItemType>::isEmpty()) {
        Node<ItemType>* nodeToDelete = this->headPtr;
        this->headPtr = this->headPtr->getNext();
        delete nodeToDelete;
        this->itemCount--;
    }
}

