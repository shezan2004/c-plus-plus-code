class Solution {
public:
    int minInsertions(string s) {
        int ans = 0, need = 0;
        for (char c : s) {
            if (c == '(') {
                need += 2;
                if (need % 2 == 1) {   // previous '(' had only one ')' -> add one ')'
                    ans++;
                    need--;
                }
            } else {
                need--;
                if (need == -1) {      // unmatched ')' -> add a '('
                    ans++;
                    need = 1;          // that '(' still needs one more ')'
                }
            }
        }
        return ans + need;
    }
};