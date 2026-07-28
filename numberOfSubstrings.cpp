class Solution {
public:
    int numberOfSubstrings(string s) {
        // Track the last seen index of 'a', 'b', and 'c'
        // Initialized to -1 because we haven't seen them yet
        int lastPos[3] = {-1, -1, -1};
        int count = 0;
        
        for (int right = 0; right < s.length(); ++right) {
            // Update the last seen position of the current character
            lastPos[s[right] - 'a'] = right;
            
            // If we have seen all three characters at least once
            if (lastPos[0] != -1 && lastPos[1] != -1 && lastPos[2] != -1) {
                // The number of valid substrings ending at 'right' is 
                // determined by the smallest index among the three characters.
                int minPos = min({lastPos[0], lastPos[1], lastPos[2]});
                count += (minPos + 1);
            }
        }
        
        return count;
    }
};