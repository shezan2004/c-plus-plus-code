#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        // dp[i] represents the maximum score difference (current player's score - optimal next player's score)
        // starting from stone i to the end.
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; --i) {
            int takeSum = 0;
            dp[i] = -1e9; // Initialize with a very small number
            
            // A player can take 1, 2, or 3 stones
            for (int k = 1; k <= 3 && i + k <= n; ++k) {
                takeSum += stoneValue[i + k - 1];
                dp[i] = max(dp[i], takeSum - dp[i + k]);
            }
        }

        if (dp[0] > 0) {
            return "Alice";
        } else if (dp[0] < 0) {
            return "Bob";
        } else {
            return "Tie";
        }
    }
};