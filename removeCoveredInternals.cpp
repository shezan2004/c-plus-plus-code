#include <vector>
#include <algorithm>

class Solution {
public:
    int removeCoveredIntervals(std::vector<std::vector<int>>& intervals) {
        // Sort: Ascending by start, Descending by end if starts are equal
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        
        int remainingCount = 0;
        int maxEnd = 0;
        
        for (const auto& interval : intervals) {
            // If the current interval's end is greater than the max end seen so far,
            // it is NOT covered by any previous interval.
            if (interval[1] > maxEnd) {
                remainingCount++;
                maxEnd = interval[1]; // Update the boundary
            }
            // If interval[1] <= maxEnd, it is covered, so we skip it.
        }
        
        return remainingCount;
    }
};