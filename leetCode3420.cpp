class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> P(n + 1, 0);
        for (int i = 0; i < n; i++) P[i + 1] = P[i] + nums[i];

        struct Seg { long long val; int s, e; };
        deque<Seg> dq;
        long long cost = 0, ans = 0;
        int r = n - 1;

        for (int l = n - 1; l >= 0; l--) {
            int end = l;
            while (!dq.empty() && dq.front().val <= nums[l]) {
                Seg &g = dq.front();
                cost -= g.val * (g.e - g.s + 1) - (P[g.e + 1] - P[g.s]);
                end = g.e;
                dq.pop_front();
            }
            dq.push_front({(long long)nums[l], l, end});
            cost += (long long)nums[l] * (end - l + 1) - (P[end + 1] - P[l]);

            while (cost > k) {
                Seg &b = dq.back();
                cost -= b.val - nums[r];
                b.e--;
                if (b.e < b.s) dq.pop_back();
                r--;
            }
            ans += r - l + 1;
        }
        return ans;
    }
};