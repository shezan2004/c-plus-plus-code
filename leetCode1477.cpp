#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minSumOfLengths(std::vector<int>& arr, int target) {
        int n = arr.size();
        // min_len[i] stores the minimum length of a sub-array with sum = target in the range [0, i]
        std::vector<int> min_len(n, INT_MAX);
        
        int sum = 0;
        int left = 0;
        int result = INT_MAX;
        int min_so_far = INT_MAX;

        for (int right = 0; right < n; ++right) {
            sum += arr[right];
            
            // Shrink the window from the left if the sum exceeds the target
            while (sum > target) {
                sum -= arr[left];
                left++;
            }
            
            // If we found a sub-array with the exact target sum
            if (sum == target) {
                int curr_len = right - left + 1;
                
                // If there is a valid non-overlapping sub-array to the left
                if (left > 0 && min_len[left - 1] != INT_MAX) {
                    result = std::min(result, curr_len + min_len[left - 1]);
                }
                
                // Update the minimum length found so far up to the current index
                min_so_far = std::min(min_so_far, curr_len);
            }
            
            min_len[right] = min_so_far;
        }

        return result == INT_MAX ? -1 : result;
    }
};