#include <iostream>
using namespace std;

int getNumEqual(const int x[], int n, int dValue) {
	int count = 0;
	if (n <= 0) {
		return 0;

	}
	else {
		if (x[n - 1] == dValue) {
			count = 1;
			return getNumEqual(x, n - 1, dValue) + count;
		}
	}
}

int main() {
	const int size = 10;
	int array[size] = { 1,2,3,4,5,6,7,8,9,12 };
	int value = 4;

	int count = getNumEqual(array, size, value);

	
	cout << "Number of occurence: " << value << " in array: " << count << endl;

	



	return 0;
}