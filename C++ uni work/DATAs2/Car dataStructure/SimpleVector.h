
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>
#include <new> 
#include <cstdlib> 
using namespace std;

template <class T>
class SimpleVector
{
	template <class T>
	friend ostream &operator<<(ostream &strm, const SimpleVector<T> &right);

	template <class T>
	friend istream &operator>>(istream &strm, SimpleVector<T> &right);

protected:
	T *aptr; 
	int arraySize; 
	void memError() const; 
	void subError() const; 

public:

	SimpleVector();
	SimpleVector(int s);
	SimpleVector(const SimpleVector &obj);
	~SimpleVector();
	void setElementAt(T value, int subscript);
	T getElementAt(int subscript) const;
	int getSize() const;
	T &operator[](const int &subscript);
	T operator[](int subscript) const;
};

template <class T>
SimpleVector<T>::SimpleVector()
{
	aptr = 0; 
	arraySize = 0;
}


template <class T>
SimpleVector<T>::SimpleVector(int s)
{
	arraySize = s;
	try
	{
		aptr = new T[s];
	}
	catch (bad_alloc)
	{
		memError();
	}
}



template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
	arraySize = obj.arraySize;
	aptr = new T[arraySize];
	if (aptr == 0)
		memError();
	for (int count = 0; count < arraySize; count++)
		* (aptr + count) = *(obj.aptr + count);
}


template <class T>
SimpleVector<T>::~SimpleVector()
{
	if (getSize() > 0)
		delete[] aptr;
}

template <class T>
int SimpleVector<T>::getSize() const
{
	return arraySize;
}

template <class T>
void SimpleVector<T>::memError() const
{
	cout << "ERROR:Cannot allocate memory.\n";
	exit(EXIT_FAILURE);
}

template <class T>
void SimpleVector<T>::subError() const
{
	cout << "ERROR: Subscript out of range.\n";
	exit(EXIT_FAILURE);
}


template <class T>
T SimpleVector<T>::getElementAt(int subscript) const
{
	if (subscript < 0 || subscript >= getSize())
		subError();
	return aptr[subscript];
}

template <class T>
T &SimpleVector<T>::operator[](const int &subscript)
{
	if (subscript < 0 || subscript >= getSize())
		subError();
	return aptr[subscript];
}

template <class T>
T SimpleVector<T>::operator[](int subscript) const{
	if (subscript < 0 || subscript >= getSize())
		subError();
	return aptr[subscript];
}
template <class T>
void SimpleVector<T>::setElementAt(T value, int subscript){
	aptr[subscript] = value;
}


	template <class T>
	 istream &operator>>(istream &strm, SimpleVector<T> &right){
		cout << "Enter the size of the list:";
		strm >> right.arraySize;
	
		cout << "Enter the values of the list:"<<endl;
		for (int i = 0; i < right.getSize(); i++){
			cout << "Data[" << i+1 << "]:";
			strm >> right.aptr[i];
		}//end for
		return strm;
	}

	template <class T>
 ostream &operator<<(ostream &strm, const SimpleVector<T> &right){
		cout << "Display the list contents:"<<endl;
		for (int i = 0; i < right.getSize(); i++){
			cout << "Data[" << i + 1 << "]=" ;
			strm << right.aptr[i] << endl;
		}//end for
		return strm;
	}

#endif