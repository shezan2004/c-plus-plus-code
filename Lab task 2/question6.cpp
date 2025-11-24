#include <iostream>
using namespace std;

bool isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    }
    return false;
}

int main() {
    int startYear, endYear;
    
    cout << "Enter the starting year: ";
    cin >> startYear;
    cout << "Enter the ending year: ";
    cin >> endYear;

    if (startYear > endYear) {
        cout << "Starting year should be less than or equal to ending year." << endl;
        return 0;
    }

    bool foundLeapYear = false;
    cout << "Leap years between " << startYear << " and " << endYear << " are:" << endl;

    for (int i = startYear; i <= endYear; i++) {
        if (isLeapYear(i)) {
            cout << i << " ";
            foundLeapYear = true;
        }
    }

    if (!foundLeapYear) {
        cout << "There are no leap years between " << startYear << " and " << endYear << "." << endl;
    } else {
        cout << endl;
    }

    return 0;
}
