class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int pmin = INT_MAX;
        for (auto& it : items) pmin = min(pmin, it[1]);

        vector<int> dp(budget + 1, 0);

        // 0/1 knapsack: first copy of item i gives value 1 + number of free copies
        for (int i = 0; i < n; i++) {
            int v = 1;
            for (int j = 0; j < n; j++) {
                if (j != i && items[j][0] % items[i][0] == 0) v++;
            }
            int p = items[i][1];
            for (int b = budget; b >= p; b--) {
                dp[b] = max(dp[b], dp[b - p] + v);
            }
        }

        // unbounded: extra copies of the cheapest item, value 1 each
        for (int b = pmin; b <= budget; b++) {
            dp[b] = max(dp[b], dp[b - pmin] + 1);
        }

        return dp[budget];
    }
};