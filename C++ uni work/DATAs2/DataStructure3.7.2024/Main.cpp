#include <iostream>
using namespace std;

int sumArry(int [], int );

int main() {
	int myArray[] = { 1,2,3,4 };
	int n = sizeof(myArray) / sizeof(myArray[0]);

	int sum = sumArry(myArray, n);

	cout << "sum of all elements: " << sum << endl;

	return 0;
}


int sumArry(int array[], int n) {
	{

		if (n <= 0) {
			return 0;
		}
		return array[n - 1] + sumArry(array, n - 1);
	}
}