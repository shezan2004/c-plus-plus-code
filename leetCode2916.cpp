class Solution {
    static const int MOD = 1e9 + 7;
    vector<long long> S, Q, lazy;
    int n;

    void apply(int node, int len, long long v) {
        Q[node] = (Q[node] + 2 * v % MOD * S[node] + v * v % MOD * len) % MOD;
        S[node] = (S[node] + v * len) % MOD;
        lazy[node] = (lazy[node] + v) % MOD;
    }

    void push(int node, int l, int r) {
        if (lazy[node]) {
            int m = (l + r) / 2;
            apply(node * 2, m - l + 1, lazy[node]);
            apply(node * 2 + 1, r - m, lazy[node]);
            lazy[node] = 0;
        }
    }

    void update(int node, int l, int r, int ql, int qr, long long v) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            apply(node, r - l + 1, v);
            return;
        }
        push(node, l, r);
        int m = (l + r) / 2;
        update(node * 2, l, m, ql, qr, v);
        update(node * 2 + 1, m + 1, r, ql, qr, v);
        S[node] = (S[node * 2] + S[node * 2 + 1]) % MOD;
        Q[node] = (Q[node * 2] + Q[node * 2 + 1]) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        S.assign(4 * n, 0);
        Q.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        vector<int> last(100001, -1);
        long long ans = 0;
        for (int j = 0; j < n; j++) {
            int prev = last[nums[j]];
            update(1, 0, n - 1, prev + 1, j, 1);
            last[nums[j]] = j;
            ans = (ans + Q[1]) % MOD;
        }
        return (int)ans;
    }
};