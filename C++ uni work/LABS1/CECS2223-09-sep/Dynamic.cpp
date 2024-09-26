#include "SodaMachine.h"

int main(){
	SodaMachine sodas;
	string name = "";
	double price = 0;

	for (int i = 0; i < 3; i++) {
		cout << "Enter then name for soda #" << i + 1 << ": ";
		getline(cin, price);
		cin >> name;
		cout << "Enter the price for " << name << ": ";
		cin >> price;
		sodas.addSoda(name, price);
		cout << endl;
	}
	sodas.printMachine();
	cout << "Enter the name of the soda to be removed: ";
	cin >> name;
	sodas.sellSoda(sodas.findSoda(name));
	sodas.printMachine();

	system("pause");
	return 0;
}