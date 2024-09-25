//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** ADT list: Link-based implementation.
    Listing 9-2.
    @file LinkedList.h */

#ifndef _LINKED_LIST
#define _LINKED_LIST

#include "ListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class LinkedList : public ListInterface<ItemType>
{
private:
    Node<ItemType>* headPtr; // Pointer to first node in the chain;
    // (contains the first entry in the list)
    int itemCount;           // Current count of list items 

    // Locates a specified node in this linked list.
    // @pre  position is the number of the desired node;
    //       position >= 1 and position <= itemCount.
    // @post  The node is found and a pointer to it is returned.
    // @param position  The number of the node to locate.
    // @return  A pointer to the node at the given position.
    Node<ItemType>* getNodeAt(int position) const;

    // Adds a given node at a given position within the subchain pointed to by subChainPtr.
    // Returns a pointer to the augmented subchain.
    Node<ItemType>* insertNode(int newPosition, Node<ItemType>* newNodePtr, Node<ItemType>* subChainPtr);
    Node<ItemType>* tailPtr;



public:
    LinkedList();
    LinkedList(const LinkedList<ItemType>& aList);
    virtual ~LinkedList();

    bool isEmpty() const;
    int getLength() const;
    bool insert(int newPosition, const ItemType& newEntry);
    bool remove(int position);
    void display() const;
    void clear();
   
    
    bool insertAtBeginning(const ItemType& newEntry);
    bool insertAtEnd(const ItemType& newEntry);
    bool removeFirst();
    bool removeLast();

    
    
    

    /** @throw PrecondViolatedExcep if position < 1 or
                                       position > getLength(). */
    ItemType getEntry(int position) const throw(PrecondViolatedExcep);

    /** @throw PrecondViolatedExcep if position < 1 or
                                       position > getLength(). */
    void setEntry(int position, const ItemType& newEntry)
        throw(PrecondViolatedExcep);
}; // end LinkedList

// The copy constructor and the method setEntry are left as exercises.
// ===================================================================

//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Implementation file for the class LinkedList.
 @file LinkedList.cpp */

 // Header file
#include <cassert>

template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0)
{
}  // end default constructor

template<class ItemType>
inline LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList)
{
        Node<ItemType>* origChainPtr = aList.headPtr; // Apuntador al inicio de la lista original

        // Si la lista original no está vacía
        if (origChainPtr != nullptr) {
            // Copia el primer nodo
            headPtr = new Node<ItemType>(origChainPtr->getItem());
            itemCount++;

            // Apuntadores auxiliares para recorrer la lista original y la nueva lista
            Node<ItemType>* newChainPtr = headPtr;

            // Copia el resto de la lista original
            while (origChainPtr->getNext() != nullptr) {
                origChainPtr = origChainPtr->getNext(); // Avanza en la lista original

                // Crea un nuevo nodo en la nueva lista y copia el item
                Node<ItemType>* newNodePtr = new Node<ItemType>(origChainPtr->getItem());
                newChainPtr->setNext(newNodePtr); // Conecta el nuevo nodo al final de la nueva lista
                newChainPtr = newChainPtr->getNext(); // Avanza en la nueva lista
                itemCount++; // Incrementa el contador de elementos
            }
        }
}


template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
    clear();
}  // end destructor

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
    return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedList<ItemType>::getLength() const
{
    return itemCount;
}  // end getLength

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
    bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
    if (ableToInsert)
    {
        // Create a new node containing the new entry
        Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
        headPtr = insertNode(newPosition, newNodePtr, headPtr);
    }  // end if

    return ableToInsert;
}  // end insert

template<class ItemType>
bool LinkedList<ItemType>::remove(int position)
{
    bool ableToRemove = (position >= 1) && (position <= itemCount);
    if (ableToRemove)
    {
        Node<ItemType>* curPtr = nullptr;
        if (position == 1)
        {
            // Remove the first node in the list
            curPtr = headPtr; // Save pointer to node
            if (headPtr == tailPtr) {
                // If there's only one node in the list
                headPtr = nullptr;
                tailPtr = nullptr;
            }
            else {
                headPtr = headPtr->getNext(); // Update head pointer
                headPtr->setPrevious(nullptr); // Set previous pointer of the new head to null
            }
        }
        else if (position == itemCount) // remove last node
        {
            curPtr = tailPtr;
            tailPtr = tailPtr->getPrevious(); // Update tail pointer
            tailPtr->setNext(nullptr); // Set next pointer of the new tail to null
        }
        else
        {
            // Find node that is before the one to delete
            Node<ItemType>* prevPtr = getNodeAt(position - 1);

            // Point to node to delete
            curPtr = prevPtr->getNext();

            // Disconnect indicated node from chain by connecting the
            // prior node with the one after
            prevPtr->setNext(curPtr->getNext());
            curPtr->getNext()->setPrevious(prevPtr); // Update previous pointer of the next node
        }

        // Return node to system
        curPtr->setNext(nullptr);
        curPtr->setPrevious(nullptr);
        delete curPtr;
        curPtr = nullptr;

        itemCount--;  // Decrease count of entries
    }  // end if

    return ableToRemove;
}  // end remove


template<class ItemType>
void LinkedList<ItemType>::clear()
{
    while (!isEmpty())
        remove(1);
}  // end clear

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const throw(PrecondViolatedExcep)
{
    // Enforce precondition
    bool ableToGet = (position >= 1) && (position <= itemCount);
    if (ableToGet)
    {
        Node<ItemType>* nodePtr = getNodeAt(position);
        return nodePtr->getItem();
    }
    else
    {
        string message = "getEntry() called with an empty list or ";
        message = message + "invalid position.";
        throw(PrecondViolatedExcep(message));
    }  // end if
}  // end getEntry

template<class ItemType>
inline void LinkedList<ItemType>::setEntry(int position, const ItemType& newEntry) throw(PrecondViolatedExcep)
{
}

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const
{
    // Debugging check of precondition
    assert((position >= 1) && (position <= itemCount));

    // Count from the beginning of the chain
    Node<ItemType>* curPtr = headPtr;
    for (int skip = 1; skip < position; skip++)
        curPtr = curPtr->getNext();

    return curPtr;
}  // end getNodeAt

// RECURSIVE
template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::insertNode(int position, Node<ItemType>* newNodePtr,
    Node<ItemType>* subChainPtr)
{
    if (position == 1)
    {
        // Insert new node at beginning of subchain
        newNodePtr->setNext(subChainPtr);
        subChainPtr = newNodePtr;
        itemCount++;  // Increase count of entries
    }
    else
    {
        Node<ItemType>* afterPtr = insertNode(position - 1, newNodePtr, subChainPtr->getNext());
        subChainPtr->setNext(afterPtr);
    }  // end if

    return subChainPtr;
}  // end insertNode
template<class ItemType>
void LinkedList<ItemType>::display() const {
    Node<ItemType>* currentPtr = headPtr; // Apuntador al inicio de la lista

    // Itera sobre la lista y muestra cada elemento
    while (currentPtr != nullptr) {
        cout << currentPtr->getItem() << " "; // Muestra el elemento actual
        currentPtr = currentPtr->getNext(); // Avanza al siguiente nodo
    }
    cout << endl;
}
template<class ItemType>
bool LinkedList<ItemType>::insertAtBeginning(const ItemType& newEntry)
{
    Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
    if (isEmpty()) {
        headPtr = newNodePtr;
        tailPtr = newNodePtr;
    }
    else {
        newNodePtr->setNext(headPtr);
        headPtr->setPrevious(newNodePtr);
        headPtr = newNodePtr;
    }
    itemCount++;
    return true;
}

template<class ItemType>
bool LinkedList<ItemType>::insertAtEnd(const ItemType& newEntry)
{
    Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
    if (isEmpty()) {
        headPtr = newNodePtr;
        tailPtr = newNodePtr;
    }
    else {
        tailPtr->setNext(newNodePtr);
        newNodePtr->setPrevious(tailPtr);
        tailPtr = newNodePtr;
    }
    itemCount++;
    return true;
}

template<class ItemType>
bool LinkedList<ItemType>::removeFirst()
{
    if (isEmpty()) {
        return false;
    }
    else {
        Node<ItemType>* nodeToDelete = headPtr;
        if (headPtr == tailPtr) {
            headPtr = nullptr;
            tailPtr = nullptr;
        }
        else {
            headPtr = headPtr->getNext();
            headPtr->setPrevious(nullptr);
        }
        delete nodeToDelete;
        itemCount--;
        return true;
    }
}

template<class ItemType>
bool LinkedList<ItemType>::removeLast()
{
    if (isEmpty()) {
        return false;
    }
    else {
        Node<ItemType>* nodeToDelete = tailPtr;
        if (headPtr == tailPtr) {
            headPtr = nullptr;
            tailPtr = nullptr;
        }
        else {
            tailPtr = tailPtr->getPrevious();
            tailPtr->setNext(nullptr);
        }
        delete nodeToDelete;
        itemCount--;
        return true;
    }
}

/*template<class ItemType>
void LinkedList<ItemType>::displayListReverse() const {
    Node<ItemType>* currentPtr = tailPtr; // Start from the tail of the list

    // Iterates over the list in reverse order and displays each element
    while (currentPtr != nullptr) {
        cout << currentPtr->getItem() << " "; // Displays the current item
        currentPtr = currentPtr->getPrevious(); // Moves to the previous node
    }
    cout << endl;
}*/

//  End of implementation file.

#endif 
