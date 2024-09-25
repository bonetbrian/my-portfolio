
#ifndef LOWESTLIST_H
#define LOWESTLIST_H
#include <iostream>
using namespace std;
#include"SimpleVector.h"
#include"Car.h"

template <class T>
class LowestList : public SimpleVector<T> {
	/*template <class T>
	friend ostream& operator<<(ostream& strm, const LowestList<T> right);
	template <class T>
	friend istream& operator>>(istream& strm, LowestList<T>& right);*/
public:
	LowestList();
	LowestList(int size);
	LowestList(const LowestList& obj);
	T getLowest() const;

};



template <class T>
LowestList<T>::LowestList() :SimpleVector<T>() {
}

template <class T>
void sortList(bool(*comparisonFunction)(const T& a, const T& b)) {
	for (int i = 0; i < this->getSize() - 1; i++) {
		for (int j = 0; j < this->getSize() - i - 1; j++) {
			if (comparisonFunction(this->ptr[j], this ->
				
				
				
				ptr[j + 1])) {
				T temp = this->aptr[j];
				this->ptr[j] = this->ptr[j + 1];
				this->ptr[j + 1] = temp;
			}
		}
	}
}


template <class T>
LowestList<T>::LowestList(int size) : SimpleVector<T>(size) {

}
template <class T>
LowestList<T>::LowestList(const LowestList<T>& obj) : SimpleVector<T>(obj.getSize())
{
	for (int count = 0; count < this->getSize(); count++)
		this->operator[](count) = obj[count];

}

template <class T>
T LowestList<T>::getLowest() const {
	T lowest;
	lowest = SimpleVector<T>::getElementAt(0);
	for (int count = 1; count < this->getSize(); count++) {
		if (SimpleVector<T>::getElementAt(count) < lowest) {
			lowest = SimpleVector<T>::getElementAt(count);
		}
	}
	return lowest;
}
/*template <class T>
ostream& operator<<(ostream& strm, const LowestList<T>& right) {
	strm << "Display the list contents" << endl;
	for (int i = 0; i < right.getSize(); i++) {
		strm << "Data[" << i + 1 << "]=";
		strm << right.getElementAt(i) << endl;
	}
	strm << "The lowest element:" << right.getLowest() << endl;
	return strm;
}


template <class T>
istream& operator>>(istream& strm, LowestList<T>& right) {
	cout << "Enter the values of the list:" << endl;
	for (int i = 0; i < right.getSize(); i++) {
		cout << "Data[" << i + 1 << "]:";
		strm >> right.aptr[i];
	}//end for
	return strm;
}*/
#endif