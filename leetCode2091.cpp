class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0; // i = index of min, j = index of max
        
        for (int k = 0; k < n; k++) {
            if (nums[k] < nums[i]) i = k;
            if (nums[k] > nums[j]) j = k;
        }
        
        int front = max(i, j) + 1;              // remove both from front
        int back = n - min(i, j);                // remove both from back
        int mixed = min(i + 1 + (n - j), j + 1 + (n - i)); // one from each side
        
        return min({front, back, mixed});
    }
};