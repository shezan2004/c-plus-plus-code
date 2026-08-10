class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        // dp[i][j] stores the maximum score difference 
        // the current player can get from piles[i...j]
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Base case: 1 pile
        for (int i = 0; i < n; ++i) {
            dp[i][i] = piles[i];
        }
        
        // Fill the DP table for lengths from 2 to n
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
            }
        }
        
        // If Alice's total score advantage > 0, she wins
        return dp[0][n - 1] > 0;
    }
};