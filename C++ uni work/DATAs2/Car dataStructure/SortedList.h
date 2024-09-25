#ifndef SORTEDLIST_H
#define SORTEDLIST_H

#include "SimpleVector.h"

template <class T>
class SortedList : public SimpleVector<T> {
public:
    SortedList();
    SortedList(int size);
    SortedList(const SortedList& obj);
    void bubbleSort(); // Bubble sort algorithm to sort elements
};

template <class T>
SortedList<T>::SortedList() : SimpleVector<T>() {}

template <class T>
SortedList<T>::SortedList(int size) : SimpleVector<T>(size) {}

template <class T>
SortedList<T>::SortedList(const SortedList<T>& obj) : SimpleVector<T>(obj) {}

template <class T>
void SortedList<T>::bubbleSort() {
    int size = this->getSize();
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (this->aptr[j] > this->aptr[j + 1]) {
                T temp = this->aptr[j];
                this->aptr[j] = this->aptr[j + 1];
                this->aptr[j + 1] = temp;
            }
        }
    }
}

#endif