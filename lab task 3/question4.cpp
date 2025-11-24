#include <iostream>
using namespace std;

int main() {
    const int maxItems = 10;
    const int maxDays = 10;
    int salesQuantity[maxDays][maxItems];
    float salesUnitPrice[maxDays][maxItems];
    float totalSales[maxDays] = {0};
    int totalQuantity = 0;
    int validEntries = 0;

    cout << "Enter the sales unit price and sales quantity for each item over " << maxDays << " days.\n";
    cout << "All values must be between 0 and 1000 for price and between 0 and 100 for quantity.\n";

    for (int day = 0; day < maxDays; day++) {
        cout << "\nDay " << (day + 1) << ":\n";
        for (int item = 0; item < maxItems; item++) {
            float price;
            int quantity;

            cout << "Item " << (item + 1) << " - Unit Price: ";
            cin >> price;
            if (price < 0 || price > 1000) {
                cout << "Invalid price. Please enter a value between 0 and 1000.\n";
                item--; 
                continue;
            }

            cout << "Item " << (item + 1) << " - Quantity (0 to 100): ";
            cin >> quantity;
            if (quantity < 0 || quantity > 100) {
                cout << "Invalid quantity. Please enter a value between 0 and 100.\n";
                item--; 
                continue;
            }

            salesUnitPrice[day][item] = price;
            salesQuantity[day][item] = quantity;
            totalSales[day] += price * quantity;
            totalQuantity += quantity;
            validEntries++;
        }
    }

    cout << "\nTotal Sales for each day:\n";
    for (int day = 0; day < maxDays; day++) {
        cout << "Day " << (day + 1) << ": " << totalSales[day] << endl;
    }

    float averageQuantity;
    if (validEntries > 0) {
        averageQuantity = (float)totalQuantity / validEntries;
    } else {
        averageQuantity = 0;
    }

    cout << "\nAverage Sales Quantity: " << averageQuantity << endl;

    return 0;
}
