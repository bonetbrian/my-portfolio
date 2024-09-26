/*
* CECS 2203, Computer Programming I Lab
* Spring 2023, Sec. 06
* Date: May 4, 2023
* Topic: Lab 7 - Arrays
* File name: lab07.cpp
*
* Star Wars!
* To celebrate May the 4th we will simulate a war between the dark forces of
* the Empire and the Rebel Alliance. You will create two arrays, one with
* fighter ships from the Empire and the other with fighter ships from the
* Rebel Alliance. Each array contains 11 ships, whose firepower will be in the
* range of 1 to 1,000. A call to the battle method will simulate the battle
* and print the winner.
* May the 4th be with you!
*
* Name: Brian Bonet Medina, #119461
*/
// write the appropriate include statement
#include <iostream>
// write the appropriate using statement
using namespace std;
// declare a method named setFirepower which receives an integer array and a
// constant integer value as parameters and has no return value.
void setFirepower(int[], const int);
// declare a method named battle which receives 2 constant integer arrays, 
// 2 constant integer values, and 2 constant strings as parameters and returns
// a string value.
string battle(const int[], const int, const string, const int[], const int, const string);
// declare a method named displayFleet which receives a boolean value, a constant
// integer array, a constant integer value, and a constant string as parameters
// and has no return value.
void displayFleet(bool, const int[], const int, const string);

// declare a method named displayWinner which receives a constant string as parameter 
// and has no return value.
void displayWinner(const string);

void personalInfo(); // method prototype

int main() {
	// Write the statement that declares the constant integer variable SHIPS and
	// and initializes it to 11. 
	const int SHIPS = 15;

	// Write the statement that declares an integer array named galacticEmpire and 
	// initializes all elements to 0. Use the constant SHIPS as the size of the array.
	int galacticEmpire[SHIPS] = { 0 };
	// call the displayFleet method to print the values of the galacticEmpire fleet
	displayFleet(true, galacticEmpire, SHIPS, "Galactic Empire");
	// call the setFirepower to set the strength of the galacticEmpire fleet
	setFirepower(galacticEmpire, SHIPS);
	// call the displayFleet method to print the values of the galacticEmpire fleet
	displayFleet(false, galacticEmpire, SHIPS, "Galactic Empire");
	// Write the statement that declares an integer array named rebelAlliance and 
	// initializes all elements to 0. Use the constant SHIPS as the size of the array.
	int rebelAlliance[SHIPS] = { 0 };
	// call the displayFleet method to print the values of the rebelAlliance fleet
	displayFleet(true, rebelAlliance, SHIPS, "rebelAlliance");
	// call the setFirepower to set the strength of the rebelAlliance fleet
	setFirepower(rebelAlliance, SHIPS);
	// call the displayFleet method to print the values of the rebelAlliance fleet
	displayFleet(false, rebelAlliance, SHIPS, "rebelAlliance");
	cout << "\t***** BATTLE! *****\n\n";
	// call the displayWinner using the return value of the battle method as argument.
	displayWinner(battle(galacticEmpire,SHIPS,"Galactic Empire",rebelAlliance,SHIPS,"Rebel Alliance"));
	// Write the statement that calls the personalInfo method
	personalInfo();
	system("pause"); // for Visual Studio only
	return 0;
}
// Method definitions

// The setFirepower which receives an integer array and its size as parameters 
// and has no return value. It assigns a random value in the range of 1 to 1,000
// to every element of the array. Declare a static unsigned integer variable named
// blasterBolt and initialize it to the return value of a call to the time method. 
// Make sure to cast the return value of the time method to the data type of blasterBolt!
// Call the srand method using the value of blasterBolt as argument to seed the pseudo
// random number generator. Develop a for iteration control structure which assigns
// a random value to each element of the array. After all values have been assigned, 
// increment the value of blasterBolt.
void setFirepower(int fleet[], const int size)
{
	static unsigned int blasterBolt = static_cast<unsigned int>(time(NULL));
	srand(blasterBolt);
	for(int i = 0; i < size; i++)
	{
		fleet[i] = rand() % 5000 + 3;

	}
	blasterBolt++;
}

// The battle method simulates a battle. It receives 2 integer arrays, their respective
// sizes, and their names as parameters and returns a string value. The battle is a 
// comparison of the firepower for each battle ship, the one with the highest firepower
// wins. Declare an integer variable named result and initialize it to 0. Using a for
// iteration control structure, compare the firepower of the elements in each index of
// the arrays. If the value in the first array is higher than the same element in the
// second array increment the value of result. If the value in the first array is less
// than the comparable element of the second array decrement the value of result. If both
// values are the same, the value of reulst doesn't change. To implement this logic use 
// a set of selection control structures nested within the for loop. Once all values have been
// compared, the value of result determines the winner. If the value of result is positive,
// retrun the string with the name of the first array. If the value of result is negative,
// retrun the string with the name of the second array. If the value of result is 0, return the 
// string "TIE". 
string battle(const int fleet1[], const int size1, const string name1, const int fleet2[], const int size2, const string name2)
{
	int result = 0;
	for (int i = 0; i < size1 && i < size2; i++) {
		if (fleet1[i] > fleet2[i]) {
			result++;
		}
		else if (fleet1[i] < fleet2[i]) {
			result--;
		}
	}
	if (result > 0) {
		return name1;

	}
	else if (result < 0) {
		return name2;
	}
	else {
		return "TIE";
	}
}

// The displayFleet method receives a boolean value, an integer array, its size, and a string
// as parameters and has no return value. It prints a phrase selected by the boolean value, followed
// by the firepower for each ship in the fleet. If the boolean value is true, the phrase to be 
// printed is "After initialization, the firepower for the [name] fleet is: \n", where [name] is 
// the value of the string parameter. If the boolean value is false, the phrase to be printed is
// "After setFirepower, the firepower for the [name] fleet is: \n". Then print the damage for each 
// ship in the array using the format "Fighter ship #[number]: [firepower]\n", where [number] starts 
// at 1, and [firepower] is the value in the element of the array.
// Make sure to add a blank line after the values are printed.
void displayFleet(bool initial, const int fleet[], const int size, const string name) {
	if (initial) {
		cout << "After initialization, the firepower for the " << name << " fleet is: \n";
	}
	else{
		cout << "After setFirepower, the firepower for the " << name << " fleet is : \n";

	}
	for (int i = 0; i < size; i++) {
		cout << "Fighter " << i + 1 << ": " << fleet[i] << endl;
	}
	cout << endl;
	
}


// The displayWinner method receives a string as parameter and has no return value.
// It prints the winner of the battle using the phrase "[name] is the winner!", where [name]
// is the value of the string parameter. If the value of the parameter is "TIE", the phrase to
// be printed is "The battle resulted in a tie!"
// Make sure to add a blank line after the phrase is printed.
void displayWinner(const string winner) {
	cout << winner << "is the winner!\n";
}


// The personalInfo method has no parameters or return value. It prints the phrase
// "Program developed by [YOUR NAME], ID#[YOUR ID NUMBER]", where the square brackets 
// and the text within is substituted with your personal information. Make sure to add
// a blank line after the phrase is printed.
void personalInfo() {
	cout << "Program developed by Brian Bonet Medina, ID#119461";
}