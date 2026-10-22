class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        long long best = LLONG_MAX;

        // Case 1: ascending rotation
        int k = nums[0];
        bool asc = true;
        for (int i = 0; i < n; i++) {
            if (nums[i] != (k + i) % n) { asc = false; break; }
        }
        if (asc) {
            long long left = (n - k) % n;
            long long right = (k == 0) ? 0 : k + 2;
            best = min(best, min(left, right));
        }

        // Case 2: descending rotation
        int c = nums[0];
        bool desc = true;
        for (int i = 0; i < n; i++) {
            if (nums[i] != (((c - i) % n) + n) % n) { desc = false; break; }
        }
        if (desc) {
            int kp = (c + 1) % n;
            long long a = 1 + (n - kp) % n;
            long long b = kp + 1;
            best = min(best, min(a, b));
        }

        return best == LLONG_MAX ? -1 : (int)best;
    }
};