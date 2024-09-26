#include "SodaMachine.h"
#include <string>

SodaMachine::SodaMachine() {
	sodas = 0;
	machine = nullptr;
}
SodaMachine::SodaMachine(const SodaMachine& aMachine) {
	sodas = aMachine.getSize();
	machine = new Sodas * [getSize()];
	copyArray(aMachine.getArray(), aMachine.getSize());
}
SodaMachine::~SodaMachine() {
	for (int i = 0; i < getSize(); i++) 
		machine[i]->~Sodas();
		delete[] machine;
}
void SodaMachine::addSoda(string aName, double aPrice) {
	if (getSize() > 0) {
		Sodas** temp = machine;
		machine = new Sodas * [++sodas];
		copyArray(temp, getSize() - 1);
		delete[] temp;
	}
	else {
		machine = new Sodas * [++sodas];
	}
	machine[getSize() - 1] = new Sodas(aName, aPrice); //machine double pointer has a pointer in the array
}

void SodaMachine::sellSoda(const int index) {
	if (getSize() > 0 && index < getSize() && index>-1) {
		if (getSize() > 1) {
			machine[index]->~Sodas();
			Sodas** temp = machine;
			machine = new Sodas * [--sodas];
			copyArray(temp, getSize() + 1);
			delete[] temp;
		}
	}
	else {
		machine[0]->~Sodas();
		delete[]machine;
	}
}
int SodaMachine::getSize()const {
	return sodas;
}
Sodas** SodaMachine::getArray()const {
	return machine;
}
void SodaMachine::copyArray(Sodas** aMachine, const int size) {
	int limit = size < getSize() ? size : getSize();
	for (int i = 0; i < limit; i++)
		machine[i] = aMachine[i];

}
int SodaMachine::findSoda(string aName) const {
	if (getSize() > 0) {
		for (int i = 0; i < getSize(); i++) {
			if (machine[i]->getName().compare(aName) == 0)
				return i;
		}
	}
	return -1;
}
void SodaMachine::printMachine()const {
	printf("%-*s$%s\n", machine[0]->getNameSize(), "NAME", "PRICE");
	for (int i = 0; i < getSize(); i++) {
		machine[i]->printSoda();
		cout << endl;
	}
}