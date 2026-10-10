class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        const int M = 100000;
        vector<long long> cnt(M + 2, 0);
        long long total = 0;
        for (int i = 0; i < n; i++) {
            int d = abs(nums1[i] - nums2[i]);
            cnt[d]++;
            total += d;
        }
        long long k = (long long)k1 + k2;
        if (total <= k) return 0;

        // Sweep from the top, flattening the largest values.
        for (int v = M; v >= 1 && k > 0; v--) {
            if (cnt[v] == 0) continue;
            if (k >= cnt[v]) {
                // Lower all elements at value v to v-1.
                k -= cnt[v];
                cnt[v - 1] += cnt[v];
                cnt[v] = 0;
            } else {
                // Partially lower: k elements go to v-1.
                cnt[v] -= k;
                cnt[v - 1] += k;
                k = 0;
            }
        }

        long long ans = 0;
        for (long long v = 1; v <= M; v++) {
            ans += cnt[v] * v * v;
        }
        return ans;
    }
};