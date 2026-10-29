class Solution {
public:
    vector<int> bit;
    int N;

    void upd(int i, int v) {
        for (i++; i <= N; i += i & -i) bit[i] ^= v;
    }
    int pre(int i) { // xor of [0, i]
        int r = 0;
        for (i++; i > 0; i -= i & -i) r ^= bit[i];
        return r;
    }
    int range(int l, int r) {
        return pre(r) ^ (l ? pre(l - 1) : 0);
    }

    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        N = n;
        bit.assign(n + 1, 0);
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> parent(n, -1), depth(n, 0), sz(n, 1), heavy(n, -1), order;
        order.reserve(n);

        // iterative DFS for order
        vector<int> stk = {0};
        while (!stk.empty()) {
            int u = stk.back();
            stk.pop_back();
            order.push_back(u);
            for (int v : adj[u]) {
                if (v != parent[u]) {
                    parent[v] = u;
                    depth[v] = depth[u] + 1;
                    stk.push_back(v);
                }
            }
        }
        // sizes and heavy child
        for (int i = n - 1; i > 0; i--) {
            int u = order[i];
            sz[parent[u]] += sz[u];
        }
        for (int u : order) {
            int best = -1;
            for (int v : adj[u]) {
                if (v != parent[u] && (best == -1 || sz[v] > sz[best])) best = v;
            }
            heavy[u] = best;
        }

        // assign head and positions
        vector<int> head(n), pos(n);
        int cur = 0;
        for (int u : order) {
            if (parent[u] == -1 || heavy[parent[u]] != u) {
                for (int v = u; v != -1; v = heavy[v]) {
                    head[v] = u;
                    pos[v] = cur++;
                }
            }
        }

        // build BIT
        vector<int> cs(n);
        for (int i = 0; i < n; i++) {
            cs[i] = 1 << (s[i] - 'a');
            upd(pos[i], cs[i]);
        }

        auto pathXor = [&](int u, int v) {
            int res = 0;
            while (head[u] != head[v]) {
                if (depth[head[u]] < depth[head[v]]) swap(u, v);
                res ^= range(pos[head[u]], pos[u]);
                u = parent[head[u]];
            }
            if (depth[u] > depth[v]) swap(u, v);
            res ^= range(pos[u], pos[v]);
            return res;
        };

        vector<bool> ans;
        for (auto& q : queries) {
            if (q[0] == 'u') {
                int u, ch;
                char c;
                sscanf(q.c_str(), "update %d %c", &u, &c);
                int nm = 1 << (c - 'a');
                if (nm != cs[u]) {
                    upd(pos[u], cs[u] ^ nm);
                    cs[u] = nm;
                }
            } else {
                int u, v;
                sscanf(q.c_str(), "query %d %d", &u, &v);
                int m = pathXor(u, v);
                ans.push_back((m & (m - 1)) == 0);
            }
        }
        return ans;
    }
};