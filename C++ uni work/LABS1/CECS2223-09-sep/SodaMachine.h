#pragma once
#include "Sodas.h"
#include <string>

class SodaMachine {
private:
	int sodas; //thesize of the array
	Sodas** machine; //the sodas array

public:
	SodaMachine();
	SodaMachine(const SodaMachine&);
	~SodaMachine();
	int getSize()const;
	Sodas** getArray() const;
	void addSoda(string, double);
	void copyArray(Sodas**,const int);
	void sellSoda(const int);
	int findSoda(string)const;
	void printMachine()const;
};