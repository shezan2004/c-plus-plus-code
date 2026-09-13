class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int,int>> ones1, ones2;
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1) ones1.push_back({i, j});
                if (img2[i][j] == 1) ones2.push_back({i, j});
            }
        
        if (ones1.empty() || ones2.empty()) return 0;
        
        unordered_map<int, int> shiftCount; // encode (dx,dy) -> count
        int best = 0;
        
        for (auto& p1 : ones1) {
            for (auto& p2 : ones2) {
                int dx = p2.first - p1.first;
                int dy = p2.second - p1.second;
                int key = (dx + n) * 2 * n + (dy + n); // unique encoding
                int cnt = ++shiftCount[key];
                best = max(best, cnt);
            }
        }
        
        return best;
    }
};