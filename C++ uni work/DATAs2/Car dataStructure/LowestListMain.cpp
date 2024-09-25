#include<iostream>
#include<string>
#include"SortedList.h"
#include"Car.h"
using namespace std;

int main()
{
	int n;

	cout << "Enter the size of the list of integers:";
	cin >> n;
	LowestList<int> myListOfIntegers(n);
	cin >> myListOfIntegers;
	cout << myListOfIntegers;

	cout << "\nEnter the size of the list of characters:";
	cin >> n;
	LowestList<char> myListOfChar(n);
	cin >> myListOfChar;
	cout << myListOfChar;

	cout << "\nEnter the size of the list of Objects of Car:";
	cin >> n;
	LowestList<Car> myListOfCars(n);
	cin >> myListOfCars;
	cout << myListOfCars;
	system("pause");
	return 0;
}