#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> counts;
        for (int num : nums) {
            counts[num]++;
        }

        int maxLength = 1;

        // Handle the special case for 1
        if (counts.count(1)) {
            int countOne = counts[1];
            if (countOne % 2 == 0) {
                maxLength = max(maxLength, countOne - 1);
            } else {
                maxLength = max(maxLength, countOne);
            }
        }

        // Handle numbers > 1
        for (auto& [val, count] : counts) {
            if (val == 1) continue;

            long long current = val;
            int currentLength = 0;

            // Build the chain x, x^2, x^4...
            while (counts.count(current) && counts[current] >= 2) {
                currentLength += 2;
                current = current * current; // Move to x^2
            }

            // The peak element can just have a count of 1
            if (counts.count(current) && counts[current] >= 1) {
                currentLength += 1;
            } else {
                // If the last element didn't even have 1 copy, 
                // the previous element must act as the peak instead of a duplicate pair.
                currentLength -= 1; 
            }

            maxLength = max(maxLength, currentLength);
        }

        return maxLength;
    }
};