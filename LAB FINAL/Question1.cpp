#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int knapsack(int W, int weights[], int values[], int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "Knapsack DP Table:\n";
    for (const auto& row : dp) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }

    return dp[n][W];
}

int lcs(const string& s1, const string& s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << "\nLCS DP Table:\n";
    for (const auto& row : dp) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }

    return dp[m][n];
}

int main() {
    int weights[] = {3, 1, 2, 4, 5, 6};
    int values[] = {120, 150, 50, 120, 70, 80};
    int n = sizeof(weights) / sizeof(weights[0]);
    int W = 18;

  
    int maxTasteValue = knapsack(W, weights, values, n);
    cout << "\nMaximum taste value Manikrisna can achieve: " << maxTasteValue << "\n";

    
    string name1 = "Manikrisna";
    string name2 = "Maharishi";

    int lcsLength = lcs(name1, name2);
    cout << "\nLength of Longest Common Subsequence (LCS) between '" << name1 << "' and '" << name2 << "': " << lcsLength << "\n";

    return 0;
}
