#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int Knapsack(int W, const vector<int>& weights, const vector<int>& values, vector<vector<int> >& dp) {
    int n = weights.size();
    
    for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][W];
}

vector<int> FindSelectedItems(const vector<vector<int> >& dp, const vector<int>& weights, int W) {
    vector<int> selectedItems;
    int n = weights.size();
    int w = W;

    for (int i = n; i > 0 && w > 0; --i) {
        if (dp[i][w] != dp[i - 1][w]) {
            selectedItems.push_back(i - 1);
            w -= weights[i - 1];
        }
    }

    return selectedItems;
}

void PrintTable(const vector<vector<int> >& dp, int W) {
    cout << "DP Table (Profit):\n";
    int n = dp.size() - 1;

    cout << setw(5) << " ";
    for (int w = 0; w <= W; ++w) {
        cout << setw(5) << w;
    }
    cout << endl;

    for (int i = 0; i <= n; ++i) {
        cout << setw(5) << i;
        for (int w = 0; w <= W; ++w) {
            cout << setw(5) << dp[i][w];
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int weightsArr[] = {7, 5, 2, 5, 3};
    int valuesArr[] = {700, 600, 240, 250, 1050};
    vector<int> weights(weightsArr, weightsArr + 5);
    vector<int> values(valuesArr, valuesArr + 5);
    int maxWeight = 12;

    vector<vector<int> > dp(weights.size() + 1, vector<int>(maxWeight + 1, 0));

    int maxProfit = Knapsack(maxWeight, weights, values, dp);

    PrintTable(dp, maxWeight);

    vector<int> selectedItems = FindSelectedItems(dp, weights, maxWeight);

    cout << "Maximum Profit: " << maxProfit << "\n";
    cout << "Selected Items (0-based index): ";
    for (size_t i = 0; i < selectedItems.size(); ++i) {
        cout << selectedItems[i] << (i == selectedItems.size() - 1 ? "\n" : ", ");
    }

    cout << "\nSelected Products:\n";
    cout << setw(10) << "Item" << setw(10) << "Weight" << setw(10) << "Value" << endl;
    for (size_t i = 0; i < selectedItems.size(); ++i) {
        int idx = selectedItems[i];
        cout << setw(10) << (idx + 1) << setw(10) << weights[idx] << setw(10) << values[idx] << endl;
    }

    return 0;
}
