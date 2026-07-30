#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    std::vector<int> arrayRankTransform(std::vector<int>& arr) {
        // Step 1: Create a copy of the array and sort it
        std::vector<int> sorted_arr = arr;
        std::sort(sorted_arr.begin(), sorted_arr.end());
        
        // Step 2: Assign ranks to unique elements using a hash map
        std::unordered_map<int, int> rank_map;
        int rank = 1;
        
        for (int num : sorted_arr) {
            // If the element is not already in the map, assign it the current rank
            if (rank_map.find(num) == rank_map.end()) {
                rank_map[num] = rank;
                rank++; // Increment rank only for unique elements
            }
        }
        
        // Step 3: Transform the original array to its ranks
        std::vector<int> result;
        result.reserve(arr.size()); // Optimize memory allocation
        for (int num : arr) {
            result.push_back(rank_map[num]);
        }
        
        return result;
    }
};