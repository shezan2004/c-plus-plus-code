class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        int left = 0, maxLength = 0;
        int count[26] = {0}; // Frequency array for lowercase English letters

        for (int right = 0; right < n; ++right) {
            char c = s[right];
            count[c - 'a']++;

            // If any character count exceeds 2, shrink the window from the left
            while (count[c - 'a'] > 2) {
                count[s[left] - 'a']--;
                left++;
            }

            // Update the maximum length of the valid substring
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};