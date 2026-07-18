#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    int findGCD(std::vector<int>& nums) {
        // Find the iterators to the smallest and largest elements
        auto [min_it, max_it] = std::minmax_element(nums.begin(), nums.end());
        
        // Calculate and return the GCD of the min and max values
        return std::gcd(*min_it, *max_it);
    }
};