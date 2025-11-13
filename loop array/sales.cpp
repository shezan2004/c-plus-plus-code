
#include <iostream>
#include <string>

using namespace std;

int main() {
    int numEmployees;
    cout << "Enter the number of employees: ";
    cin >> numEmployees;

    string names[numEmployees];
    double sales[numEmployees];

    // Input sales data for each employee
    for (int i = 0; i < numEmployees; ++i) {
        cout << "Enter the name of employee " << i + 1 << ": ";
        cin >> names[i];
        cout << "Enter the total sales for " << names[i] << ": $";
        cin >> sales[i];
    }

    // Calculate total sales for each employee and the company
    double totalCompanySales = 0;
    for (int i = 0; i < numEmployees; ++i) {
        totalCompanySales += sales[i];
    }

    // Output total sales for each employee and the company
    cout << "\nTotal sales for each employee:\n";
    for (int i = 0; i < numEmployees; ++i) {
        cout << names[i] << ": $" << sales[i] << endl;
    }
    cout << "\nTotal company sales: $" << totalCompanySales << endl;

    return 0;
}
