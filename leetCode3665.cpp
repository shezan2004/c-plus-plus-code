class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();
        vector<vector<long long>> R(m + 2, vector<long long>(n + 2, 0));
        vector<vector<long long>> D(m + 2, vector<long long>(n + 2, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    long long total = (i == 0 && j == 0) ? 1 : (R[i][j] + D[i][j]) % MOD;
                    if (i == m - 1 && j == n - 1) return (int)total;
                    if (total == 0) continue;
                    if (j + 1 < n) R[i][j + 1] = (R[i][j + 1] + total) % MOD;
                    if (i + 1 < m) D[i + 1][j] = (D[i + 1][j] + total) % MOD;
                } else {
                    // arrived moving right -> deflected down
                    if (i + 1 < m) D[i + 1][j] = (D[i + 1][j] + R[i][j]) % MOD;
                    // arrived moving down -> deflected right
                    if (j + 1 < n) R[i][j + 1] = (R[i][j + 1] + D[i][j]) % MOD;
                }
            }
        }
        return 0;
    }
};