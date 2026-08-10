#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string smallestPalindrome(string s) {
        // Step 1: Count character frequencies
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        
        int odd_count = 0;
        char middle_char = 0;
        
        // Step 2: Find if there's an odd character for the middle
        for (int i = 0; i < 26; i++) {
            if (count[i] % 2 != 0) {
                odd_count++;
                middle_char = i + 'a';
            }
        }
        
        // If more than 1 character has an odd count, a palindrome is mathematically impossible
        if (odd_count > 1) {
            return ""; 
        }
        
        // Step 3: Build the left half in alphabetical order
        string left_half = "";
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                // Append exactly half of the current character's count
                left_half += string(count[i] / 2, i + 'a');
            }
        }
        
        // Step 4: Mirror the left half to create the right half
        string right_half = left_half;
        reverse(right_half.begin(), right_half.end());
        
        // Assemble the final palindrome
        string result = left_half;
        if (odd_count == 1) {
            result += middle_char;
        }
        result += right_half;
        
        return result;
    }
};