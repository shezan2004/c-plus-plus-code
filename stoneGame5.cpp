#include <vector>

class Solution {
public:
    bool winnerSquareGame(int n) {
        // dp[i] represents whether the current player can win with i stones left
        std::vector<bool> dp(n + 1, false);
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                // If removing j^2 stones leaves the opponent in a losing state, 
                // the current player can win.
                if (!dp[i - j * j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[n];
    }
};