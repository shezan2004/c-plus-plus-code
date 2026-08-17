class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + stoneValue[i];

        vector<vector<long long>> dp(n, vector<long long>(n, 0));

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                long long total = prefix[j + 1] - prefix[i];

                long long best = 0;
                for (int k = i; k < j; k++) {
                    long long leftSum = prefix[k + 1] - prefix[i];
                    long long rightSum = total - leftSum;
                    long long score;
                    if (leftSum < rightSum) {
                        score = leftSum + dp[i][k];
                    } else if (leftSum > rightSum) {
                        score = rightSum + dp[k + 1][j];
                    } else {
                        score = leftSum + max(dp[i][k], dp[k + 1][j]);
                    }
                    if (score > best) best = score;
                }
                dp[i][j] = best;
            }
        }

        return (int) dp[0][n - 1];
    }
};