class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        if (n < k) return 0;

        // isPal[i][j] = true if s[i..j] is a palindrome
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j]) {
                    if (j - i < 2) isPal[i][j] = true;
                    else isPal[i][j] = isPal[i + 1][j - 1];
                }
            }
        }

        // dp[i] = max substrings selectable from s[0..i-1]
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1]; // skip: don't end a substring at i-1
            for (int j = 0; j + k <= i; j++) {
                if (isPal[j][i - 1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n];
    }
};