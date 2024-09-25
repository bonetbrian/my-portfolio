#pragma once

#include<iostream>
#include<string>
#include"LowestList.h"
using namespace::std;

class Car {
	friend ostream& operator<<(ostream& strm, const Car& right);
	friend istream& operator>>(istream& strm, Car& right);

private:
	int yearModel;
	string make;
	int speed;
public:

	Car(int aYearModel = 2013, string aMake = "BMW", int aSpeed = 65);
	Car(const Car& obj);
	~Car();
	void setYearModel(int aYearModel);
	void setMake(string aMake);
	void setSpeed(int aSpeed);
	int getYearModel() const;
	string getMake() const;
	int getSpeed() const;
	void getAccelerate();
	void getBrake();
	
	bool operator>(const Car& right) const;
	bool operator<(const Car& right) const;
	

};