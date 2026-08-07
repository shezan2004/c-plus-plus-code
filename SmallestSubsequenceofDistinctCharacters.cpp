#include <string>
#include <vector>

class Solution {
public:
    string smallestSubsequence(string s) {
        // Track the last occurrence index of each character
        vector<int> last_occurrence(26, 0);
        for (int i = 0; i < s.length(); ++i) {
            last_occurrence[s[i] - 'a'] = i;
        }

        // Track if a character is already included in our result stack
        vector<bool> visited(26, false);
        string result = ""; // Using a string directly as a monotonic stack

        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];

            // If the character is already in our result, skip it
            if (visited[c - 'a']) {
                continue;
            }

            // Greedy/Monotonic check:
            // While the current character is smaller than the last character in our result,
            // AND that last character appears again later in the string,
            // we pop it out to maintain the smallest lexicographical order.
            while (!result.empty() && c < result.back() && last_occurrence[result.back() - 'a'] > i) {
                visited[result.back() - 'a'] = false;
                result.pop_back();
            }

            // Add the current character and mark it as visited
            result.push_back(c);
            visited[c - 'a'] = true;
        }

        return result;
    }
};