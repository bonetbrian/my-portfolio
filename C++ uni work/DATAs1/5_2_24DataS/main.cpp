#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "LinkedSortedList.h" // Include your LinkedSortedList implementation

using namespace std;

class Date {
private:
    int day;
    int month;
    int year;
public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}
    friend ostream& operator<<(ostream& os, const Date& date);
};

ostream& operator<<(ostream& os, const Date& date) {
    os << setfill('0') << setw(2) << date.day << "/" << setw(2) << date.month << "/" << date.year;
    return os;
}

class Height {
private:
    
public:
       double value;
    Height(double h) : value(h) {}
    bool operator>(const Height& other) const { return value > other.value; }
    bool operator<(const Height& other) const { return value < other.value; }
};

// Define the operator<< for pair<Height, Date> outside the Height class
ostream& operator<<(ostream& os, const Height& height) {
    os << height.value << " meters";
    return os;
}

class PersonalBest {
private:
    string name;
    vector<pair<Date, Height>> personalBests;
public:
    PersonalBest(const string& n) : name(n) {}

    void addVault(const Date& date, const Height& height) {
        personalBests.push_back(std::make_pair(date, height));
    }

    void displayBestVaults() const {
        LinkedSortedList<pair<Height, Date>> sortedVaults;
        for (const auto& pb : personalBests) {
            sortedVaults.insertSorted(make_pair(pb.second, pb.first));
        }

        cout << "Best vaults for " << name << ":" << endl;
        while (!sortedVaults.isEmpty()) {
            auto vault = sortedVaults.getEntry(sortedVaults.getLength());
            cout << vault.second << ": " << vault.first << endl;
            sortedVaults.remove(sortedVaults.getLength());
        }
    }

};

int main() {
    string name;
    cout << "Enter the name of the pole vaulter: ";
    getline(cin, name);

    PersonalBest athlete(name);

    for (int i = 0; i < 3; ++i) {
        int day, month, year;
        double height;
        cout << "Enter the date (day month year) for vault " << i + 1 << ": ";
        cin >> day >> month >> year;
        cout << "Enter the vault height (between 2.0m and 5.0m): ";
        cin >> height;

        if (height < 2.0 || height > 5.0) {
            cout << "Invalid height. Please enter a height between 2.0m and 5.0m." << endl;
            --i;
            continue;
        }

        athlete.addVault(Date(day, month, year), Height(height));
    }

    athlete.displayBestVaults();

    return 0;
}





/*#include "BIG.h"

int main() {
    vector<VaultRecord> vaults;

    for (int i = 0; i < 3; ++i) {
        VaultRecord record;
        cout << "Enter pole vaulter's name: ";
        cin >> record.name;

        int day, month, year;
        cout << "Enter date of vault (DD MM YYYY): ";
        cin >> day >> month >> year;
        record.date.setDate(day, month, year);

        double height;
        do {
            cout << "Enter vault height (between 2.0 and 5.0 meters): ";
            cin >> height;
        } while (height < 2.0 || height > 5.0);
        record.height.setHeight(height);

        vaults.push_back(record);
    }

    // Sort vaults by height (best first)
    sort(vaults.begin(), vaults.end(), compareByHeight);

    // Display sorted vaults
    cout << "\nVaults Sorted by Height (Best First):\n";
    for (const auto& vault : vaults) {
        cout << "Name: " << vault.name << ", ";
        cout << "Date: ";
        vault.date.displayDate();
        cout << ", Height: " << vault.height.getHeight() << " meters\n";
    }

    return 0;
}*/
