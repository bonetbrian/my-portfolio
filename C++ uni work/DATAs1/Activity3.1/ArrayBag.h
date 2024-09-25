//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 _Pearson Education_. All rights reserved.

/** Header file for an array-based implementation of the ADT bag.
 @file ArrayBag.h */

/*
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
// end ArrayBag*/