// Created by Frank M. Carrano and Tim Henry.
// Copyright (c) 2013 __Pearson Education__. All rights reserved.
/** ADT queue: Link-based implementation.
Listing 14-3.
@file LinkedQueue.h */
#ifndef _LINKED_QUEUE
#define _LINKED_QUEUE
#include<iostream>
#include <cassert>
using namespace::std;
#include "QueueInterface.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"
template<class ItemType>
class LinkedQueue : public QueueInterface<ItemType>
{
private:
	// The queue is implemented as a chain of linked nodes that has
	// two external pointers, a head pointer for front of the queue and
	// a tail pointer for the back of the queue.
	Node<ItemType>* backPtr;
	Node<ItemType>* frontPtr;
public:
	LinkedQueue();
	LinkedQueue(const LinkedQueue& aQueue);
	~LinkedQueue();
	bool isEmpty() const;
	bool enqueue(const ItemType& newEntry);
	bool dequeue();
	void display() const;

	/** @throw PrecondViolatedExcep if the queue is empty */
	ItemType peekFront() const throw(PrecondViolatedExcep);
}; // end LinkedQueue
//#include "LinkedQueue.cpp"
// Created by Frank M. Carrano and Tim Henry.
// Copyright (c) 2013 __Pearson Education__. All rights reserved.
// PARITALLY COMPLETE.
/** @file LinkedQueue.cpp */
//#include "LinkedQueue.h"
template<class ItemType>
LinkedQueue<ItemType>::LinkedQueue() :backPtr(nullptr), frontPtr(nullptr) {}
template<class ItemType>
LinkedQueue<ItemType>::LinkedQueue(const LinkedQueue& aQueue)
{
	Node<ItemType>* origChainPtr = aQueue.frontPtr;
	if (origChainPtr == nullptr)
	{
		frontPtr = nullptr;
		backPtr = nullptr;
	}
	else
	{
		// Copy first node
		// Original queue is empty
		frontPtr = new Node<ItemType>();
		frontPtr->setItem(origChainPtr->getItem());
		// Advance original-chain pointer
		origChainPtr = origChainPtr->getNext();
		// Copy remaining nodes
		Node<ItemType>* newChainPtr = frontPtr; // Points to last node in new chain
		while (origChainPtr != nullptr)
		{
			// Get next item from original chain
			ItemType nextItem = origChainPtr->getItem();
			// Create a new node containing the next item
			Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
			// Link new node to end of new chain
			newChainPtr->setNext(newNodePtr);
			// Advance pointers
			newChainPtr = newChainPtr->getNext();
			origChainPtr = origChainPtr->getNext();
		} // end while
		newChainPtr->setNext(nullptr); // Flag end of chain
		backPtr = newChainPtr;
	} // end if
} // end copy constructor
template<class ItemType>
LinkedQueue<ItemType>::~LinkedQueue()
{
	if (frontPtr != nullptr)
	{
		Node<ItemType>* curPtr = frontPtr; // Start with front end of queue
		while (curPtr != backPtr)
		{
			Node<ItemType>* tempPtr = curPtr->getNext();
			delete curPtr;
			curPtr = tempPtr;
			tempPtr = nullptr;
		} // end while
		delete curPtr; // Delete last node
		curPtr = nullptr;
		frontPtr = nullptr;
		backPtr = nullptr;
	} // end if
} // end destructor
template<class ItemType>
bool LinkedQueue<ItemType>::isEmpty() const {
	if (backPtr == nullptr && frontPtr == nullptr)
		return true;
	else
		return false;
}
template<class ItemType>
/** @throw PrecondViolatedExcep if the queue is empty */
ItemType LinkedQueue<ItemType>::peekFront() const throw(PrecondViolatedExcep) {
	if (!isEmpty()) {
		return frontPtr->getItem();
	}
	else
	{
		string message = "peekFront() called with an empty list or ";
		message = message + "invalid position.";
		throw(PrecondViolatedExcep(message));
	} // end if
}
template<class ItemType>
bool LinkedQueue<ItemType>::enqueue(const ItemType& newEntry)
{
	Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
	// Insert the new node
	if (isEmpty())
		frontPtr = newNodePtr; // Insertion into empty queue
	else
		backPtr->setNext(newNodePtr); // Insertion into nonempty queue
	backPtr = newNodePtr; // New node is at back
	return true;
} // end enqueue
template<class ItemType>
bool LinkedQueue<ItemType>::dequeue()
{
	bool result = false;
	if (!isEmpty())
	{
		// Queue is not empty; delete front
		Node<ItemType>* nodeToDeletePtr = frontPtr;
		if (frontPtr == backPtr)
		{ // Special case: one node in queue
			frontPtr = nullptr;
			backPtr = nullptr;
		}
		else
			frontPtr = frontPtr->getNext();
		// Return deleted node to system
		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
		nodeToDeletePtr = nullptr;
		result = true;
	} // end if
	return result;
} // end dequeue
template<class ItemType>
void LinkedQueue<ItemType>::display() const
{
	Node<ItemType>* curPtr = frontPtr;
	while (curPtr != backPtr)
	{
		cout << curPtr->getItem() << " "; // Display items on same line curPtr
		curPtr = curPtr->getNext();
	} // end while
	cout << backPtr->getItem() << " "; // Display last item
	cout << endl; // Terminate output with an end of line
} // end display

#endif