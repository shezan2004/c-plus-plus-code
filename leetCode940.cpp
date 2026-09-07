class Solution {
public:
    int distinctSubseqII(string s) {
        long long MOD = 1e9 + 7;
        int n = s.length();
        vector<long long> dp(n + 1, 0);
        dp[0] = 1; // Empty subsequence
        vector<int> last(26, -1);

        for (int i = 0; i < n; ++i) {
            int x = s[i] - 'a';
            dp[i + 1] = (2 * dp[i]) % MOD;
            if (last[x] != -1) {
                dp[i + 1] = (dp[i + 1] - dp[last[x]] + MOD) % MOD;
            }
            last[x] = i;
        }

        // Subtract 1 to exclude the empty subsequence
        return (dp[n] - 1 + MOD) % MOD;
    }
};