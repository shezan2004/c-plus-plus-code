class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        vector<long long> lcmSubset(1 << n, 0);
        
        // Precompute lcm for each subset
        for (int mask = 1; mask < (1 << n); mask++) {
            long long l = 1;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    long long g = std::__gcd(l, (long long)coins[i]);
                    l = l / g * coins[i];
                    // overflow guard: if lcm grows huge, cap it
                    if (l > (long long)4e18) {
                        l = -1; // sentinel for "too large"
                        break;
                    }
                }
            }
            lcmSubset[mask] = l;
        }
        
        auto countLE = [&](long long x) -> long long {
            long long count = 0;
            for (int mask = 1; mask < (1 << n); mask++) {
                long long l = lcmSubset[mask];
                if (l <= 0) continue; // overflowed / invalid, contributes negligibly (skip)
                int bits = __builtin_popcount(mask);
                long long term = x / l;
                if (bits % 2 == 1) count += term;
                else count -= term;
            }
            return count;
        };
        
        int minCoin = *min_element(coins.begin(), coins.end());
        long long lo = 1, hi = (long long)minCoin * (long long)k;
        
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (countLE(mid) >= k) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        
        return lo;
    }
};