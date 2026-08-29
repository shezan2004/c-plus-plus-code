class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> idx(n);
        for (int i = 0; i < n; i++) idx[i] = i;
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return nums[a] < nums[b];
        });
        
        vector<int> result(n);
        int start = 0;
        while (start < n) {
            int end = start;
            while (end + 1 < n && nums[idx[end+1]] - nums[idx[end]] <= limit) {
                end++;
            }
            // group from start to end (in sorted order indices idx[start..end])
            vector<int> groupIndices;
            vector<int> groupValues;
            for (int k = start; k <= end; k++) {
                groupIndices.push_back(idx[k]);
                groupValues.push_back(nums[idx[k]]);
            }
            sort(groupIndices.begin(), groupIndices.end());
            for (int k = 0; k < (int)groupIndices.size(); k++) {
                result[groupIndices[k]] = groupValues[k];
            }
            start = end + 1;
        }
        
        return result;
    }
};