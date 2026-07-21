#include <string>
#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int maxActiveSectionsAfterTrade(std::string s) {
        int n = s.length();
        int total_ones = 0;
        int max_gain = 0;
        int prev_zero_len = INT_MIN; // Tracks length of previous '0' block
        
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) {
                j++;
            }
            
            int cur_len = j - i;
            if (s[i] == '1') {
                total_ones += cur_len;
            } else {
                // If there was a previous '0' block, consider merging with it
                if (prev_zero_len != INT_MIN) {
                    max_gain = std::max(max_gain, prev_zero_len + cur_len);
                }
                prev_zero_len = cur_len;
            }
            
            i = j;
        }
        
        return total_ones + max_gain;
    }
};