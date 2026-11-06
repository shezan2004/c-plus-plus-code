class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int q = queries.size();
        vector<int> order(q);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            return queries[a] < queries[b];
        });

        vector<int> cnt(n + 1, 0);
        vector<int> res(q);
        int active = 0;
        int l = 0, r = 0;
        int m = logs.size();

        for (int idx : order) {
            int hi = queries[idx];
            int lo = hi - x;

            while (r < m && logs[r][1] <= hi) {
                if (cnt[logs[r][0]]++ == 0) active++;
                r++;
            }
            while (l < r && logs[l][1] < lo) {
                if (--cnt[logs[l][0]] == 0) active--;
                l++;
            }

            res[idx] = n - active;
        }

        return res;
    }
};