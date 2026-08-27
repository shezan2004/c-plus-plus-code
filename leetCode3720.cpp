class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;

        int best_i = -1;
        vector<int> best_snapshot;

        for (int i = 0; i < n; i++) {
            int t = target[i] - 'a';
            // check if we can deviate here (place something > target[i])
            bool found = false;
            for (int c = t + 1; c < 26; c++) {
                if (cnt[c] > 0) { found = true; break; }
            }
            if (found) {
                best_i = i;
                best_snapshot = cnt; // copy current counts
            }
            // try to continue matching target's prefix exactly
            if (cnt[t] > 0) {
                cnt[t]--;
            } else {
                break; // can't extend exact-match prefix further
            }
        }

        if (best_i == -1) return "";

        string result = target.substr(0, best_i);
        int t = target[best_i] - 'a';
        int chosen = -1;
        for (int c = t + 1; c < 26; c++) {
            if (best_snapshot[c] > 0) { chosen = c; break; }
        }
        result += char('a' + chosen);
        best_snapshot[chosen]--;

        for (int c = 0; c < 26; c++) {
            result += string(best_snapshot[c], char('a' + c));
        }

        return result;
    }
};