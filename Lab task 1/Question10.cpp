#include <iostream>
using namespace std;

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

int main() {
    int choice;
    float temp;

    cout << "Temperature Conversion Program" << endl;
    cout << "1. Fahrenheit to Celsius" << endl;
    cout << "2. Celsius to Fahrenheit" << endl;
    cout << "Choose an option 1 or 2: ";
    cin >> choice;

    if (choice == 1) {
        cout << "Enter temperature in Fahrenheit: ";
        cin >>temp;
        cout << temp << " Fahrenheit is " << fahrenheitToCelsius(temp) << " Celsius." << endl;
    } else if (choice == 2) {
        cout << "Enter temperature in Celsius: ";
        cin >> temp;
        cout << temp << " Celsius is " << celsiusToFahrenheit(temp) << " Fahrenheit." << endl;
    } else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}
