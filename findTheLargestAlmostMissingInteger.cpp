class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> count;
        
        // Traverse all subarrays of size k
        for (int i = 0; i <= n - k; ++i) {
            unordered_set<int> unique_in_window;
            for (int j = i; j < i + k; ++j) {
                unique_in_window.insert(nums[j]);
            }
            // Increment the count for each unique element found in this window
            for (int num : unique_in_window) {
                count[num]++;
            }
        }
        
        int max_val = -1;
        for (auto& pair : count) {
            if (pair.second == 1) {
                max_val = max(max_val, pair.first);
            }
        }
        
        return max_val;
    }
};