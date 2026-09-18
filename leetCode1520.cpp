class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, -1), last(26, -1);
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }
        
        vector<pair<int,int>> intervals; // (start, end)
        
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] != i) continue; // only start expansion at first occurrence
            
            int start = i;
            int end = last[c];
            int j = i;
            bool valid = true;
            while (j <= end) {
                int cj = s[j] - 'a';
                if (first[cj] < start) {
                    // shouldn't happen since start is first occurrence of s[i]
                    valid = false;
                    break;
                }
                end = max(end, last[cj]);
                j++;
            }
            
            if (valid) {
                intervals.push_back({start, end});
            }
        }
        
        // sort by end
        sort(intervals.begin(), intervals.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
            return a.second < b.second;
        });
        
        vector<string> result;
        int prevEnd = -1;
        for (auto& [st, en] : intervals) {
            if (st > prevEnd) {
                result.push_back(s.substr(st, en - st + 1));
                prevEnd = en;
            }
        }
        
        return result;
    }
};