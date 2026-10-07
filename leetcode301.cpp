class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int left = 0, right = 0;
        for (char c : s) {
            if (c == '(') left++;
            else if (c == ')') {
                if (left > 0) left--;
                else right++;
            }
        }
        unordered_set<string> res;
        string cur;
        dfs(s, 0, 0, left, right, cur, res);
        return vector<string>(res.begin(), res.end());
    }

private:
    void dfs(const string& s, int i, int open, int l, int r,
             string& cur, unordered_set<string>& res) {
        if (i == (int)s.size()) {
            if (open == 0 && l == 0 && r == 0) res.insert(cur);
            return;
        }
        char c = s[i];

        // Remove s[i]
        if (c == '(' && l > 0) dfs(s, i + 1, open, l - 1, r, cur, res);
        else if (c == ')' && r > 0) dfs(s, i + 1, open, l, r - 1, cur, res);

        // Keep s[i]
        cur.push_back(c);
        if (c == '(') dfs(s, i + 1, open + 1, l, r, cur, res);
        else if (c == ')') {
            if (open > 0) dfs(s, i + 1, open - 1, l, r, cur, res);
        } else dfs(s, i + 1, open, l, r, cur, res);
        cur.pop_back();
    }
};