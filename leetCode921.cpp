class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;   // unmatched '(' so far
        int added = 0;  // insertions needed for unmatched ')'
        for (char c : s) {
            if (c == '(') {
                open++;
            } else if (open > 0) {
                open--;
            } else {
                added++;
            }
        }
        return added + open;
    }
};