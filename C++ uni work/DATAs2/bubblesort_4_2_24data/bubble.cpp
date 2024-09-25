#include <iostream>
using namespace std;

const int ni = 6;
int midget[ni] = { 25,30,20,80,40,60 };

void bubbleSort(int array[], int);
void display();

/** Sorts the items in an array into ascending order.
 @pre None.
 @post theArray is sorted into ascending order; n is unchanged.
 @param theArray The given array.
 @param n The size of theArray. */

void bubbleSort(int theArray[], int n)
{
	bool sorted = false; // False when swaps occur
	int pass = 1;
	while (!sorted && (pass < n))
	{
		// At this point, theArray[n+1-pass..n-1] is sorted
		// and all of its entries are > the entries in theArray[0..n-pass]
		sorted = true; // Assume sorted
		for (int index = 0; index < n - pass; index++)
		{
			// At this point, all entries in theArray[0..index-1]
			// are <= theArray[index]
			int nextIndex = index + 1;
			if (theArray[index] > theArray[nextIndex])
			{
				// Exchange entries
				std::swap(theArray[index], theArray[nextIndex]);
				sorted = false; // Signal exchange
			} // end if
		} // end for
		// Assertion: theArray[0..n-pass-1] < theArray[n-pass]
		pass++;
	} // end while
} // end bubbleSort

void upbubbleSort(int theArray[], int n)
{
	bool sorted = false; // False when swaps occur
	int pass = 1;
	while (!sorted && (pass < n))
	{
		// At this point, theArray[n+1-pass..n-1] is sorted
		// and all of its entries are > the entries in theArray[0..n-pass]
		sorted = true; // Assume sorted
		for (int index = 0; index < n - pass; index++)
		{
			// At this point, all entries in theArray[0..index-1]
			// are <= theArray[index]
			int nextIndex = index + 1;
			if (theArray[index] < theArray[nextIndex])
			{
				// Exchange entries
				std::swap(theArray[index], theArray[nextIndex]);
				sorted = false; // Signal exchange
			} // end if
		} // end for
		// Assertion: theArray[0..n-pass-1] < theArray[n-pass]
		pass++;
	} // end while
} // end bubbleSort

void display() {
	for (int n = 0; n < ni; n++) {
		cout << midget[n] << ",";

	}
	cout << endl;
	
}

int main() {

	cout << "we be sorting\n" << endl;
	bubbleSort(midget, ni);
	display();
	upbubbleSort(midget, ni);
	display();

	return 0;
}

