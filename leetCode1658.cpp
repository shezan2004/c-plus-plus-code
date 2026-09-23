class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        long long target = total - x;

        if (target < 0) return -1;      // x is larger than the whole array sum
        if (target == 0) return n;      // must remove everything

        int best = -1;
        long long sum = 0;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            sum += nums[right];
            while (sum > target) {
                sum -= nums[left++];
            }
            if (sum == target) {
                best = max(best, right - left + 1);
            }
        }

        return best == -1 ? -1 : n - best;
    }
};