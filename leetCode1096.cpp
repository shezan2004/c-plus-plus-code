class Solution {
public:
    string s;
    int pos;

    set<string> parseUnion() {
        set<string> result = parseConcat();
        while (pos < (int)s.size() && s[pos] == ',') {
            pos++; // skip comma
            set<string> next = parseConcat();
            for (auto& w : next) result.insert(w);
        }
        return result;
    }

    set<string> parseConcat() {
        vector<set<string>> factors;
        while (pos < (int)s.size() && s[pos] != ',' && s[pos] != '}') {
            factors.push_back(parseFactor());
        }
        // cartesian product concatenation
        set<string> result;
        result.insert("");
        for (auto& f : factors) {
            set<string> newResult;
            for (auto& prefix : result) {
                for (auto& w : f) {
                    newResult.insert(prefix + w);
                }
            }
            result = newResult;
        }
        return result;
    }

    set<string> parseFactor() {
        if (s[pos] == '{') {
            pos++; // skip {
            set<string> res = parseUnion();
            pos++; // skip }
            return res;
        } else {
            // single letter
            string letter(1, s[pos]);
            pos++;
            return {letter};
        }
    }

    vector<string> braceExpansionII(string expression) {
        s = expression;
        pos = 0;
        set<string> result = parseUnion();
        return vector<string>(result.begin(), result.end());
    }
};