#include <vector>
#include <numeric>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
    int memo[101][201];
    int suffixSum[101];
    int n;

    int solve(int i, int M) {
        if (i >= n) return 0;
        // If the player can take all remaining piles, take them all.
        if (i + 2 * M >= n) {
            return suffixSum[i];
        }
        if (memo[i][M] != -1) {
            return memo[i][M];
        }

        int maxStones = 0;
        // Try taking X piles, where 1 <= X <= 2M
        for (int X = 1; X <= 2 * M; ++X) {
            int currentStones = suffixSum[i] - solve(i + X, max(M, X));
            maxStones = max(maxStones, currentStones);
        }

        return memo[i][M] = maxStones;
    }

public:
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(memo, -1, sizeof(memo));
        
        // Compute suffix sums
        suffixSum[n] = 0;
        for (int i = n - 1; i >= 0; --i) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        return solve(0, 1);
    }
};