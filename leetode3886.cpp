class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for (int k = 1; k <= n; k++) {
            if (n % k) continue;
            bool ok = true;
            int prevMax = 0; // values >= 1
            for (int l = 0; l < n && ok; l += k) {
                int r = l + k - 1;
                int d = 0, p = -1;
                for (int i = l; i < r; i++) {
                    if (nums[i] > nums[i + 1]) {
                        d++;
                        p = i;
                        if (d > 1) break;
                    }
                }
                if (d > 1) { ok = false; break; }
                int mn, mx;
                if (d == 0) {
                    mn = nums[l];
                    mx = nums[r];
                } else {
                    if (nums[r] > nums[l]) { ok = false; break; }
                    mn = nums[p + 1];
                    mx = nums[p];
                }
                if (mn < prevMax) { ok = false; break; }
                prevMax = mx;
            }
            if (ok) ans += k;
        }
        return (int)ans;
    }
};