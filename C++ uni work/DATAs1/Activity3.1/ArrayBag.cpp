//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 _Pearson Education_. All rights reserved.

/** Implementation file for the class ArrayBag.
 @file ArrayBag.cpp */

#include "ArrayBag.h"
#include <cstddef>
#include <bitset>


#ifndef _ARRAY_BAG
#define _ARRAY_BAG

#include "BagInterface.h"
#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;

template<class ItemType>
class ArrayBag : public BagInterface<ItemType>
{
private:
    static const int DEFAULT_CAPACITY = 6; // Small size to test for a full bag
    ItemType items[DEFAULT_CAPACITY];      // Array of bag items
    int itemCount;                         // Current count of bag items 
    int maxItems;                          // Max capacity of the bag

    // Returns either the index of the element in the array items that
    // contains the given target or -1, if the array does not contain 
    // the target.
    int getIndexOf(const ItemType& target) const;

public:
    ArrayBag();
    int getCurrentSize() const;
    bool isEmpty() const;
    bool add(const ItemType& newEntry);
    bool remove(const ItemType& anEntry);
    void clear();
    bool contains(const ItemType& anEntry) const;
    int getFrequencyOf(const ItemType& anEntry) const;
    vector<ItemType> toVector() const;
    void display()const;
    ItemType getElement(int)const;
    ArrayBag<ItemType>getSet();
    ArrayBag<ItemType>getBitString();
    ArrayBag<ItemType>getUnion(const ArrayBag<ItemType>& antoherBag);
    ArrayBag<ItemType>getIntersection(const ArrayBag<ItemType>& anotherBag);
    ArrayBag<ItemType>getSymmetricDiff(const ArrayBag<ItemType>& anotherBag);
    ArrayBag<ItemType>getComplement(const ArrayBag<ItemType>& anotherBag);
    ArrayBag<ItemType>& operator=(const ArrayBag<ItemType>& anotherBag);




    friend ostream& operator<<(ostream& outStream, const ArrayBag<ItemType>& outputArrayBag) {
        for (int i = 0; i < outputArrayBag.itemCount; ++i) {
            outStream << outputArrayBag.items[i] << " ";
        }
        return outStream;
    }
    friend istream& operator>>(istream& inputStream, ArrayBag<ItemType>& inputArrayBag) {
        ItemType newItem;
        while (inputStream >> newItem) {
            inputArrayBag.add(newItem);
        }
        return inputStream;
    }




};


#endif
template<class ItemType>
ArrayBag<ItemType>::ArrayBag() : itemCount(0), maxItems(DEFAULT_CAPACITY)
{
}  // end default constructor

template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
    return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
    return itemCount == 0;
}  // end isEmpty

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry)
{
    bool hasRoomToAdd = (itemCount < maxItems);
    if (hasRoomToAdd)
    {
        items[itemCount] = newEntry;
        itemCount++;
    }  // end if

    return hasRoomToAdd;
}  // end add

/*
// STUB
 template<class ItemType>
 bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
 {
    return false; // STUB
 }  // end remove
*/

template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
{
    int locatedIndex = getIndexOf(anEntry);
    bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
    if (canRemoveItem)
    {
        itemCount--;
        items[locatedIndex] = items[itemCount];
    }  // end if

    return canRemoveItem;
}  // end remove

/*
 // STUB
 template<class ItemType>
 void ArrayBag<ItemType>::clear()
 {
    // STUB
 }  // end clear
*/

template<class ItemType>
void ArrayBag<ItemType>::clear()
{
    itemCount = 0;
}  // end clear

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
    int frequency = 0;
    int curIndex = 0;       // Current array index
    while (curIndex < itemCount)
    {
        if (items[curIndex] == anEntry)
        {
            frequency++;
        }  // end if

        curIndex++;          // Increment to next entry
    }  // end while

    return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
    return getIndexOf(anEntry) > -1;
}  // end contains

/* ALTERNATE 1: First version
template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& target) const
{
   return getFrequencyOf(target) > 0;
}  // end contains

// ALTERNATE 2: Second version
template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
   bool found = false;
   int curIndex = 0;        // Current array index
   while (!found && (curIndex < itemCount))
   {
      if (anEntry == items[curIndex])
      {
         found = true;
      } // end if

      curIndex++;           // Increment to next entry
   }  // end while

   return found;
}  // end contains
*/

template<class ItemType>
vector<ItemType> ArrayBag<ItemType>::toVector() const
{
    vector<ItemType> bagContents;
    for (int i = 0; i < itemCount; i++)
        bagContents.push_back(items[i]);

    return bagContents;
}  // end toVector

// private
template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const
{
    bool found = false;
    int result = -1;
    int searchIndex = 0;

    // If the bag is empty, itemCount is zero, so loop is skipped
    while (!found && (searchIndex < itemCount))
    {
        if (items[searchIndex] == target)
        {
            found = true;
            result = searchIndex;
        }
        else
        {
            searchIndex++;
        }  // end if
    }  // end while

    return result;
}  // end getIndexOf

template<class ItemType>
void ArrayBag<ItemType>::display() const {
    for (int count = 0; count < getCurrentSize(); count++) {
        cout << items[count] << ",";
    }
    cout << endl;
}

template<class ItemType>
ItemType ArrayBag<ItemType>::getElement(int index) const {
    return items[index];
}



template<class ItemType>
ArrayBag<ItemType> ArrayBag<ItemType>::getSet() {
    ArrayBag<ItemType> setBag;
    ItemType newItem;
    char choice;
    do {
        cout << "Enter an item: ";
        cin >> newItem;
        setBag.add(newItem);
        cout << "Do you want to add another item? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    return setBag;
}

template<class ItemType>
ArrayBag<ItemType> ArrayBag<ItemType>::getBitString() {
    ArrayBag<ItemType> bitStringBag;
   
    for (int i = 0; i < itemCount; i++) {
        bitset<32> bitString(items[i]);
        bitStringBag.add(bitString);
    }
    return bitStringBag;
}

template<class ItemType>
ArrayBag<ItemType> ArrayBag<ItemType>::getUnion(const ArrayBag<ItemType>& anotherBag) {
    ArrayBag<ItemType> unionBag = *this;
    for (int i = 0; i < anotherBag.itemCount; i++) {
        if (!unionBag.contains(anotherBag.items[i])) {
            unionBag.add(anotherBag.items[i]);
        }
    }
    return unionBag;
}

template<class ItemType>
ArrayBag<ItemType> ArrayBag<ItemType>::getIntersection(const ArrayBag<ItemType>& anotherBag) {
    ArrayBag<ItemType> intersectionBag;
    for (int i = 0; i < itemCount; i++) {
        if (anotherBag.contains(items[i])) {
            intersectionBag.add(items[i]);
        }
    }
    return intersectionBag;
}

template<class ItemType>
ArrayBag<ItemType> ArrayBag<ItemType>::getSymmetricDiff(const ArrayBag<ItemType>& anotherBag) {
    ArrayBag<ItemType> symmetricDiffBag;
    for (int i = 0; i < itemCount; i++) {
        if (!anotherBag.contains(items[i])) {
            symmetricDiffBag.add(items[i]);
        }
    }
    for (int i = 0; i < anotherBag.itemCount; i++) {
        if (!this->contains(anotherBag.items[i])) {
            symmetricDiffBag.add(anotherBag.items[i]);
        }
    }
    return symmetricDiffBag;
}

template<class ItemType>
ArrayBag<ItemType> ArrayBag<ItemType>::getComplement(const ArrayBag<ItemType>& anotherBag) {
    ArrayBag<ItemType> complementBag;
    for (int i = 0; i < anotherBag.itemCount; i++) {
        if (!this->contains(anotherBag.items[i])) {
            complementBag.add(anotherBag.items[i]);
        }
    }
    return complementBag;
}

template<class ItemType>
ArrayBag<ItemType>& ArrayBag<ItemType>::operator=(const ArrayBag<ItemType>& anotherBag) {
    if (this != &anotherBag) {
        itemCount = anotherBag.itemCount;
        maxItems = anotherBag.maxItems;
        for (int i = 0; i < itemCount; i++) {
            items[i] = anotherBag.items[i];
        }
    }
    return *this;
}