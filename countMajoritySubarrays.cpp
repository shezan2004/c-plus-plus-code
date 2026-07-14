#include <vector>

using namespace std;

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int result = 0;
        int prefix_sum = 0;
        
        // The prefix sum range is from -n to n. 
        // We use an offset of `n` to safely index negative numbers.
        vector<int> count(2 * n + 1, 0);
        
        // Base case: Before starting, prefix sum is 0.
        count[0 + n] = 1;
        
        // We also keep track of how many prefix sums are less than the current prefix sum.
        // As prefix_sum changes by +1 or -1, we can maintain this running total dynamically.
        int valid_prev_counts = 0;

        for (int x : nums) {
            if (x == target) {
                // Prefix sum increases by 1. 
                // All previous prefix sums equal to the OLD prefix_sum now become strictly smaller.
                valid_prev_counts += count[prefix_sum + n];
                prefix_sum++;
            } else {
                // Prefix sum decreases by 1.
                // Previous prefix sums equal to the NEW prefix_sum are no longer smaller.
                prefix_sum--;
                valid_prev_counts -= count[prefix_sum + n];
            }
            
            result += valid_prev_counts;
            count[prefix_sum + n]++;
        }
        
        return result;
    }
};