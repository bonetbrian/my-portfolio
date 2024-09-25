#include <iostream>
using namespace std;



class Term {
private:
    double coefficient;
    int exponent;

public:
    Term(double coeff = 0.0, int exp = 0); // Constructor

    // Overload comparison operators
    bool operator==(const Term& other) const;
    bool operator!=(const Term& other) const;

    // Overload arithmetic operators
    Term operator+(const Term& other) const;
    Term operator-(const Term& other) const;
    Term operator*(const Term& other) const;
};

Term::Term(double coeff, int exp) : coefficient(coeff), exponent(exp) {}

bool Term::operator==(const Term& other) const {
    return (coefficient == other.coefficient && exponent == other.exponent);
}

bool Term::operator!=(const Term& other) const {
    return !(*this == other);
}

Term Term::operator+(const Term& other) const {
    return Term(coefficient + other.coefficient, exponent);
}

Term Term::operator-(const Term& other) const {
    return Term(coefficient - other.coefficient, exponent);
}

Term Term::operator*(const Term& other) const {
    return Term(coefficient * other.coefficient, exponent + other.exponent);
}