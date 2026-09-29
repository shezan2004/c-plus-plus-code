class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if ((m + n - 1) % 2 != 0) return false;
        if (grid[0][0] == ')' || grid[m-1][n-1] == '(') return false;

        const int MAXB = 205;
        vector<vector<bitset<MAXB>>> dp(m, vector<bitset<MAXB>>(n));

        dp[0][0][1] = 1; // after '(' balance is 1

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;

                bitset<MAXB> cur;
                if (i > 0) cur |= dp[i-1][j];
                if (j > 0) cur |= dp[i][j-1];

                if (grid[i][j] == '(') {
                    cur <<= 1;
                } else {
                    cur >>= 1; // bit 0 (balance 0) falls off, so balance never goes negative
                }
                dp[i][j] = cur;
            }
        }
        return dp[m-1][n-1][0];
    }
};