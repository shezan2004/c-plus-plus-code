#include <vector>

class Solution {
public:
    long long countMajoritySubarrays(std::vector<int>& nums, int target) {
        int n = nums.size();
        
        // Prefix sums can range from -n to n, so we use an array of size 2*n + 1
        // with an offset of n to handle negative indices.
        std::vector<int> counts(2 * n + 1, 0);
        int offset = n;
        
        int prefix_sum = 0;
        counts[prefix_sum + offset] = 1; // Base case: empty prefix before index 0
        
        long long smaller_count = 0;
        long long ans = 0;
        
        for (int x : nums) {
            if (x == target) {
                // Prefix sum increases: elements equal to the old prefix sum 
                // are now strictly smaller than the new prefix sum.
                smaller_count += counts[prefix_sum + offset];
                prefix_sum += 1;
            } else {
                // Prefix sum decreases: elements equal to the new prefix sum
                // are no longer strictly smaller than it.
                prefix_sum -= 1;
                smaller_count -= counts[prefix_sum + offset];
            }
            
            ans += smaller_count;
            counts[prefix_sum + offset]++;
        }
        
        return ans;
    }
};