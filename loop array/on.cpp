#include <iostream>

using namespace std;

int main() {
    double usd_to_bdt = 110.83;
    double euro_to_bdt = 120.28;
    double cad_to_bdt = 81.14;
    double aud_to_bdt = 72.11;

    char choice;

    do {
        cout << "Choose currency to convert to BDT:" << endl;
        cout << "1. US Dollar (USD)" << endl;
        cout << "2. Euro (EUR)" << endl;
        cout << "3. Canadian Dollar (CAD)" << endl;
        cout << "4. Australian Dollar (AUD)" << endl;

        int currencyChoice;
        cout << "Enter your choice (1-4): ";
        cin >> currencyChoice;

        double amount;
        cout << "Enter the amount in the selected currency: ";
        cin >> amount;

        double convertedAmount;

        switch (currencyChoice) {
            case 1:

                convertedAmount = amount * usd_to_bdt;
                break;
            case 2:
                convertedAmount = amount * euro_to_bdt;
                break;
            case 3:
                convertedAmount = amount * cad_to_bdt;
                break;
            case 4:
                convertedAmount = amount * aud_to_bdt;
                break;
            default:
                cout << "Invalid choice!" << endl;
                continue;
        }


        cout << "Converted amount in BDT: " << convertedAmount << " BDT" << endl;

        cout << "Do you want to convert another currency? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Program terminated. Goodbye!" << endl;

    return 0;
}
