#include <iostream>
using namespace std;

int main() {
    double totalRetailValue = 0.0;

    while (true) {
        int productNumber;
        int quantity;

        cout << "Enter product number (1-5, or 0 to exit): ";
        cin >> productNumber;

        if (productNumber == 0) {
            break;
        }

        if (productNumber < 1 || productNumber > 5) {
            cout << "Invalid product number. Please enter a number between 1 and 5." << endl;
            continue;
        }

        cout << "Enter quantity sold: ";
        cin >> quantity;

        double retailPrice;

        switch (productNumber) {
            case 1:
                retailPrice = 200.75;
                break;
            case 2:
                retailPrice = 345.50;
                break;
            case 3:
                retailPrice = 775.75;
                break;
            case 4:
                retailPrice = 400.35;
                break;
            case 5:
                retailPrice = 1200.75;
                break;
        }

        totalRetailValue += retailPrice * quantity;
    }

    cout << "Total retail value of products sold: BDT " << totalRetailValue << endl;

    return 0;
}

