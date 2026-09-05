#include <vector>

class Solution {
public:
    int uniqueXorTriplets(std::vector<int>& nums) {
        std::vector<bool> ans(2048, false);
        std::vector<bool> seen_pairs(2048, false);
        std::vector<int> pair_list;
        
        // 1. Every individual element is a valid XOR triplet value
        for (int x : nums) {
            ans[x] = true;
        }
        
        int n = nums.size();
        for (int k = 0; k < n; ++k) {
            // 2. Form triplets with i < j < k
            for (int p : pair_list) {
                ans[p ^ nums[k]] = true;
            }
            
            // 3. Register all pairs (i, k) for future triplets
            for (int i = 0; i < k; ++i) {
                int pair_xor = nums[i] ^ nums[k];
                if (!seen_pairs[pair_xor]) {
                    seen_pairs[pair_xor] = true;
                    pair_list.push_back(pair_xor);
                }
            }
        }
        
        // Count total unique XOR values
        int count = 0;
        for (bool present : ans) {
            if (present) count++;
        }
        return count;
    }
};