#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Student {
private:
    string gender;
    int heightFeet;
    int heightInches;
    int weight;
    int age;
    

public:
    double bmi;
    double bfp;

    // Constructors
    Student() : heightFeet(0), heightInches(0), weight(0), age(0), bmi(0), bfp(0) {}
    Student(const string& g, int feet, int inches, int w, int a) : gender(g), heightFeet(feet), heightInches(inches), weight(w), age(a) {
        calculateBMI();
        calculateBFP();
    }

    // Getter and setter methods
    string getGender() const { return gender; }
    void setGender(const string& g) { gender = g; }
    // Similarly, add getter and setter methods for other member variables

    // Calculation methods
    void calculateBMI() {
        int totalHeightInches = heightFeet * 12 + heightInches;
        bmi = (weight * 703.0) / (totalHeightInches * totalHeightInches);
    }

    void calculateBFP() {
        if (gender == "Male") {
            bfp = 1.20 * bmi + 0.23 * age - 16.2;
            printBodyStatus(bfp, 24); // Print body status for males
        }
        else if (gender == "Female") {
            bfp = 1.20 * bmi + 0.23 * age - 5.4;
            printBodyStatus(bfp, 36); // Print body status for females
        }
    }

    void printBodyStatus(double bfp, int threshold) {
        if (bfp < threshold) {
            cout << "Healthy body" << endl;
        }
        else {
            cout << "Unhealthy body" << endl;
        }
    }

    // Overloaded insertion and extraction operators
    friend ostream& operator<<(ostream& os, const Student& student);
    friend istream& operator>>(istream& is, Student& student);

    // Overloaded relational operators based on BFP
    bool operator<(const Student& other) const {
        return bfp < other.bfp;
    }

    bool operator>(const Student& other) const {
        return bfp > other.bfp;
    }

    // Assignment operator
    Student& operator=(const Student& other) {
        if (this != &other) {
            gender = other.gender;
            heightFeet = other.heightFeet;
            heightInches = other.heightInches;
            weight = other.weight;
            age = other.age;
            bmi = other.bmi;
            bfp = other.bfp;
        }
        return *this;
    }
};

// Overloaded insertion operator
ostream& operator<<(ostream& os, const Student& student) {
    os << "Gender: " << student.gender << ", Height: " << student.heightFeet << "'" << student.heightInches << "\", Weight: " << student.weight
        << " lbs, Age: " << student.age << ", BMI: " << student.bmi << ", BFP: " << student.bfp << "%";
    return os;
}

// Overloaded extraction operator
istream& operator>>(istream& is, Student& student) {
    is >> student.gender >> student.heightFeet >> student.heightInches >> student.weight >> student.age;
    student.calculateBMI();
    student.calculateBFP();
    return is;
}

// Function to display an item
void displayStudent(Student& student) {
    cout << student << endl;
}
