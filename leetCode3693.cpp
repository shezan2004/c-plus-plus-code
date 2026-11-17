class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= 3 && k <= j; k++) {
                dp[j] = min(dp[j], dp[j - k] + k * k);
            }
            dp[j] += costs[j - 1]; // costs is 1-indexed in the problem
        }
        return dp[n];
    }
};