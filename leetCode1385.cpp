class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        multiset<int> lo, hi;
        long long sLo = 0, sHi = 0;

        auto rebalance = [&]() {
            int total = lo.size() + hi.size();
            int want = (total + 1) / 2;
            while ((int)lo.size() > want) {
                auto it = prev(lo.end());
                sLo -= *it; sHi += *it;
                hi.insert(*it);
                lo.erase(it);
            }
            while ((int)lo.size() < want) {
                auto it = hi.begin();
                sHi -= *it; sLo += *it;
                lo.insert(*it);
                hi.erase(it);
            }
        };
        auto add = [&](int v) {
            if (lo.empty() || v <= *lo.rbegin()) { lo.insert(v); sLo += v; }
            else { hi.insert(v); sHi += v; }
            rebalance();
        };
        auto remove = [&](int v) {
            if (!lo.empty() && v <= *lo.rbegin()) {
                lo.erase(lo.find(v)); sLo -= v;
            } else {
                hi.erase(hi.find(v)); sHi -= v;
            }
            rebalance();
        };

        int m = n - x + 1;
        vector<long long> cost(m);
        for (int i = 0; i < n; i++) {
            add(nums[i]);
            if (i >= x) remove(nums[i - x]);
            if (i >= x - 1) {
                long long med = *lo.rbegin();
                cost[i - x + 1] = med * (long long)lo.size() - sLo
                                + sHi - med * (long long)hi.size();
            }
        }

        const long long INF = LLONG_MAX / 4;
        vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, INF));
        for (int i = 0; i <= n; i++) dp[0][i] = 0;
        for (int j = 1; j <= k; j++) {
            for (int i = j * x; i <= n; i++) {
                dp[j][i] = dp[j][i - 1];
                if (dp[j - 1][i - x] < INF)
                    dp[j][i] = min(dp[j][i], dp[j - 1][i - x] + cost[i - x]);
            }
        }
        return dp[k][n];
    }
};