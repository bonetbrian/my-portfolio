#include<iostream>
#include<string>
using namespace::std;
#include "Car.h"

Car::Car(int aYearModel, string aMake, int aSpeed) : yearModel(aYearModel), make(aMake), speed(aSpeed)
{}
Car::Car(const Car& obj) {
	setYearModel(obj.getYearModel());
	setMake(obj.getMake());
	setSpeed(obj.getSpeed());
}
Car::~Car() {
	cout << "Car destructor executing\n";
	system("pause");
}
void Car::setYearModel(int aYearMode) {
	yearModel = aYearMode;
}
void Car::setMake(string aMake) {
	make = aMake;
}
void Car::setSpeed(int aSpeed) {
	speed = aSpeed;
}
int Car::getYearModel() const {
	return yearModel;
}
string Car::getMake() const {
	return make;
}
int Car::getSpeed() const {
	return speed;
}

void Car::getBrake() {
	setSpeed(getSpeed() - 5);
	if (getSpeed() < 0)
		setSpeed(0);
}
void Car::getAccelerate() {
	setSpeed(getSpeed() + 5);
}




bool Car::operator>(const Car& right) const {
	bool flag = false;
	if (getSpeed() > right.getSpeed())
		flag = true;
	return flag;
}
bool Car::operator<(const Car& right) const {
	bool flag = false;
	if (getSpeed() < right.getSpeed())
		flag = true;
	return flag;
}

bool compareModel(const Car& a, const Car& b) {
	return a.getMake() < b.getMake();
}

istream& operator>>(istream& strm, Car& right) {
	cout << "Enter the car's year:";
	strm >> right.yearModel;
	cout << "Enter the car's make:";
	strm >> right.make;
	cout << "Enter the car's speed:";
	strm >> right.speed;
	return strm;
}
ostream& operator<<(ostream& strm, const Car& right) {
	strm << "Year:" << right.getYearModel() << endl;
	strm << "Make:" << right.getMake() << endl;
	strm << "Speed:" << right.getSpeed() << endl;
	return strm;
}
