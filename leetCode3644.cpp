class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int res = -1; // all bits set
        bool any = false;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                res &= nums[i];
                any = true;
            }
        }
        return any ? res : 0;
    }
};