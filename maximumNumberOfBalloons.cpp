class Solution {
public:
    int maxNumberOfBalloons(string text) {
        // Frequency array for all 26 lowercase English letters
        int counts[26] = {0};
        
        // Count the occurrences of each character in the input string
        for (char c : text) {
            counts[c - 'a']++;
        }
        
        // Extract the counts for the specific letters needed
        int b_count = counts['b' - 'a'];
        int a_count = counts['a' - 'a'];
        int l_count = counts['l' - 'a'] / 2; // Needs 2 'l's per balloon
        int o_count = counts['o' - 'a'] / 2; // Needs 2 'o's per balloon
        int n_count = counts['n' - 'a'];
        
        // The limiting factor determines the maximum number of words formed
        return min({b_count, a_count, l_count, o_count, n_count});
    }
};