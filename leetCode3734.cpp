class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        int freq[26] = {0};
        for (char c : s) freq[c-'a']++;
        int oddCount = 0, oddChar = -1;
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 != 0) { oddCount++; oddChar = i; }
        }
        if ((n % 2 == 0 && oddCount != 0) || (n % 2 == 1 && oddCount != 1)) return "";
        
        int m = n / 2;
        int cnt[26];
        for (int i = 0; i < 26; i++) cnt[i] = freq[i] / 2;
        bool odd = (n % 2 == 1);
        char midChar = odd ? char('a' + oddChar) : 0;
        
        string targetLeft = target.substr(0, m);
        
        // Case A: try using target's left half exactly
        {
            int tcnt[26] = {0};
            for (char c : targetLeft) tcnt[c-'a']++;
            bool match = true;
            for (int i = 0; i < 26; i++) if (tcnt[i] != cnt[i]) { match = false; break; }
            if (match) {
                string full = targetLeft;
                if (odd) full += midChar;
                string rev = targetLeft;
                reverse(rev.begin(), rev.end());
                full += rev;
                if (full > target) return full;
            }
        }
        
        // Case B: find smallest half > target's left half
        bool found;
        string h = findSmallestGreater(cnt, targetLeft, m, found);
        if (found) {
            string full = h;
            if (odd) full += midChar;
            string rev = h;
            reverse(rev.begin(), rev.end());
            full += rev;
            return full;
        }
        
        return "";
    }
    
private:
    string findSmallestGreater(int cnt[26], const string& X, int m, bool &found) {
        found = false;
        if (m == 0) return "";
        vector<array<int,26>> history(m+1);
        array<int,26> avail;
        for (int i = 0; i < 26; i++) avail[i] = cnt[i];
        history[0] = avail;
        int feasibleLen = 0;
        for (int pos = 0; pos < m; pos++) {
            int c = X[pos]-'a';
            if (avail[c] > 0) {
                avail[c]--;
                feasibleLen = pos+1;
                history[pos+1] = avail;
            } else break;
        }
        for (int i = feasibleLen; i >= 0; i--) {
            if (i == m) continue;
            array<int,26> &avail_i = history[i];
            int xchar = X[i]-'a';
            int chosen = -1;
            for (int c = xchar+1; c < 26; c++) {
                if (avail_i[c] > 0) { chosen = c; break; }
            }
            if (chosen != -1) {
                string h = X.substr(0, i);
                h += char('a'+chosen);
                array<int,26> remaining = avail_i;
                remaining[chosen]--;
                for (int c = 0; c < 26; c++)
                    for (int k = 0; k < remaining[c]; k++) h += char('a'+c);
                found = true;
                return h;
            }
        }
        return "";
    }
};