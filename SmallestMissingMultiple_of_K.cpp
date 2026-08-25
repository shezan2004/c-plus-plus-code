#include <vector>
#include <unordered_set>

class Solution {
public:
    int missingMultiple(std::vector<int>& nums, int k) {
        std::unordered_set<int> num_set(nums.begin(), nums.end());
        
        int multiple = k;
        while (true) {
            if (num_set.find(multiple) == num_set.end()) {
                return multiple;
            }
            multiple += k;
        }
    }
};