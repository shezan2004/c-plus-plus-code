#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumProduct(std::vector<int>& nums) {
        int n = nums.size();
        
        // Sort the array to easily access the smallest and largest elements
        std::sort(nums.begin(), nums.end());
        
        // Compare the product of the three largest elements 
        // with the product of the two smallest and the largest element
        int option1 = nums[n - 1] * nums[n - 2] * nums[n - 3];
        int option2 = nums[0] * nums[1] * nums[n - 1];
        
        return std::max(option1, option2);
    }
};