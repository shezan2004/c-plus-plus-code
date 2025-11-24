#include <bits/stdc++.h>
using namespace std;

// Item class with public data members
class Item {
public:
    int value;
    int weight;

    // Constructor
    Item(int v, int w){
        value =  v;
        weight = w;
    }
};

// Comparator function to sort items by value-to-weight ratio in descending order
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Function to calculate the maximum total value for the fractional knapsack problem
double fractionalKnapsack(Item arr[], int n, int W) {
    // Sort items based on value-to-weight ratio
    sort(arr, arr + n, compare);

    double totalValue = 0.0;  // Total value in the knapsack
    for (int i = 0; i < n; i++) {
        // If adding the whole item does not exceed capacity, add it
        if (arr[i].weight <= W) {
            totalValue += arr[i].value;
            W -= arr[i].weight;
        }
        // Otherwise, add a fraction of the item’s value
        else {
            totalValue += (double)arr[i].value * W / arr[i].weight;
            break;  // Knapsack is now full
        }
    }

    return totalValue;
}

int main() {
    int W = 50;  // Knapsack capacity
    Item arr[] = { {60, 10}, {100, 20}, {120, 30} };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum value in knapsack = " << fractionalKnapsack(arr, n, W) << endl;
    return 0;
}
