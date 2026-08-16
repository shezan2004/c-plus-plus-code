class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int totalXor = 0;
        int maxVal = 0;
        for (int x : nums) {
            totalXor ^= x;
            maxVal = max(maxVal, x);
        }

        // If the total XOR is already non-zero, take the whole array.
        if (totalXor != 0) {
            return nums.size();
        }

        // If maxVal is 0, all elements are 0, so no non-zero XOR subsequence exists.
        if (maxVal == 0) {
            return 0;
        }

        // Otherwise, removing one element is enough to make the XOR non-zero.
        return nums.size() - 1;
    }
};