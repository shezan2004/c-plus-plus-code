#include<iostream>
using namespace std;

int main() {
    const int items = 5;
    const int days = 7;
    float unitPrice[days][items];
    int salesQuantity[days][items];
    int initialQuantity[items] = {100, 200, 150, 50, 300}; 
    float totalRevenue = 0;

    float basePrices[items] = {10.0, 15.0, 20.0, 25.0, 30.0};

    cout << "Enter the sales quantity for each item over 7 days.\n";

    for (int day = 0; day < days; day++) {
        float dailyRevenue = 0; 
        cout << "\nDay " << (day + 1) << ":\n";
        for (int item = 0; item < items; item++) {
            unitPrice[day][item] = basePrices[item]; 

            cout << "Item " << (item + 1) << " - Unit Price (Base Price: " << basePrices[item] << "): ";
            cin >> unitPrice[day][item];

            cout << "Item " << (item + 1) << " - Quantity Sold: ";
            cin >> salesQuantity[day][item];

            if (salesQuantity[day][item] > initialQuantity[item]) {
                cout << "Error: Not enough stock for Item " << (item + 1) << ". Available quantity: " << initialQuantity[item] << ". Please enter a valid quantity.\n";
                return 1; 
            }

            dailyRevenue += unitPrice[day][item] * salesQuantity[day][item];
            initialQuantity[item] -= salesQuantity[day][item]; 
        }
        totalRevenue += dailyRevenue;
        cout << "Revenue for Day " << (day + 1) << ": " << dailyRevenue << endl;
    }

    float averageDailyRevenue = totalRevenue / days;
    cout << "\nTotal Revenue for the week: " << totalRevenue << endl;
    cout << "Average Daily Revenue: " << averageDailyRevenue << endl;

    return 0;
}
