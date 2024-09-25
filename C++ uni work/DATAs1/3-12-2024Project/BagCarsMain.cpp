#include <iostream>
#include<string>
using namespace std;
#include "ArrayBag.h"
#include "Car.h"
int main()
{
	ArrayBag<Car> bagOfCars;
	Car myCars;
	int i;
	int n;
	cout << "Enter the number of car:";
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> myCars;
		bagOfCars.add(myCars);
	}
	cout << "Display the bag: \n";
	for (i = 0; i < n; i++)
	{
		cout << bagOfCars.getElement(i) << endl;
	}
	return 0;
}
/*Enter the number of car:3
Year: 2013
Make: BMW
Speed: 35
Year: 2023
Make: Toyota
Speed: 85
Year: 2017
Make: Porche
Speed: 20
Display the bag:
Year: 2013
Make: BMW
Speed: 35
Year: 2023
Make: Toyota
Speed: 85
Year: 2017
Make: Porche
Speed: 20
Press any key to continue . . .*/