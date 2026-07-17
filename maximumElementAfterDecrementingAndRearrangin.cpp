#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(std::vector<int>& arr) {
        // Step 1: Sort the array to process elements in increasing order
        std::sort(arr.begin(), arr.end());
        
        // Step 2: The first element must be 1
        arr[0] = 1;
        
        // Step 3: Iterate through the array and enforce the adjacent difference constraint
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] > arr[i - 1] + 1) {
                arr[i] = arr[i - 1] + 1;
            }
        }
        
        // The last element will hold the maximum possible value
        return arr.back();
    }
};