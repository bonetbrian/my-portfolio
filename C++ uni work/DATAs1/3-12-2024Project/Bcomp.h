#include "Car.h"
#include "ArrayBag.h"
#include "BagInterface.h"

using namespace std;

void printUnion(int[], int[]);

int main() {

	int A[] = {1,2,3,4};
	int B[] = { 2,3,8};
	int U[] = { 1,2,3,4,5,6,7,8,9,10 };
	
	
	printUnion(A, U);
	printUnion(B, U);

	// then compare A and B in a final array.


}