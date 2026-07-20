class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Map to store the last seen index of each character
        // Initialize with -1 to indicate the character hasn't been seen yet
        vector<int> lastSeen(128, -1);
        
        int maxLength = 0;
        int left = 0;
        
        for (int right = 0; right < s.length(); ++right) {
            char currentChar = s[right];
            
            // If the character was seen inside the current window,
            // move the left pointer to the right of its last occurrence
            if (lastSeen[currentChar] >= left) {
                left = lastSeen[currentChar] + 1;
            }
            
            // Update the last seen position of the character
            lastSeen[currentChar] = right;
            
            // Calculate the window size and update maxLength
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};