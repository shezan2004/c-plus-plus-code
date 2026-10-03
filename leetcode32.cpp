class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);          // base index just before the current valid window
        int best = 0;

        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i);   // new base: this ')' can't be matched
                } else {
                    best = max(best, i - st.top());
                }
            }
        }
        return best;
    }
};