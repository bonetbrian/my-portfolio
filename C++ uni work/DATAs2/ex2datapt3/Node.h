//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** @file Node.h
    Listing 4-1 */
#ifndef _NODE
#define _NODE

template<class ItemType>
class Node
{
private:
    ItemType        item; // A data item
    Node<ItemType>* next; // Pointer to next node
    Node<ItemType>* previous;//Pointer to previous node

public:
    Node();
    Node(const ItemType& anItem);
    Node(const ItemType& anItem, Node<ItemType>* nextNodePtr, Node<ItemType>* prevNodePtr);
    void setItem(const ItemType& anItem);
    void setNext(Node<ItemType>* nextNodePtr);
    ItemType getItem() const;
    Node<ItemType>* getNext() const;
    Node<ItemType>* getPrevious() const;
    void setPrevious(Node<ItemType>* prevNodePtr);
}; // end Node

//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** @file Node.cpp
    Listing 4-2 */
#include "Node.h"
#include <cstddef>

template<class ItemType>
Node<ItemType>::Node() : next(nullptr), previous(nullptr)
{
} // end default constructor

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item(anItem), next(nullptr), previous(nullptr)
{
} // end constructor

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr, Node<ItemType>* prevNodePtr) :
    item(anItem), next(nextNodePtr), previous(prevNodePtr)
{
} // end constructor

template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem)
{
    item = anItem;
} // end setItem

template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr)
{
    next = nextNodePtr;
} // end setNext

template<class ItemType>
ItemType Node<ItemType>::getItem() const
{
    return item;
} // end getItem

template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const
{
    return next;
} // end getNext

template<class ItemType>
Node<ItemType>* Node<ItemType>::getPrevious() const
{
    return previous;
}

template<class ItemType>
void Node<ItemType>::setPrevious(Node<ItemType>* prevNodePtr)
{
    previous = prevNodePtr;
}

#endif