class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> children(n);
        for (int i = 1; i < n; i++) children[parent[i]].push_back(i);

        vector<int> newPar = parent, order, saved(n, -1);
        order.reserve(n);
        vector<int> last(26, -1);

        // iterative DFS: (node, state) state 0 = enter, 1 = exit
        vector<pair<int,int>> st;
        st.push_back({0, 0});
        while (!st.empty()) {
            auto [x, state] = st.back();
            st.pop_back();
            int c = s[x] - 'a';
            if (state == 0) {
                order.push_back(x);
                if (x != 0 && last[c] != -1) newPar[x] = last[c];
                saved[x] = last[c];
                last[c] = x;
                st.push_back({x, 1});
                for (int ch : children[x]) st.push_back({ch, 0});
            } else {
                last[c] = saved[x];
            }
        }

        vector<int> size(n, 1);
        for (int i = n - 1; i >= 1; i--) {
            int x = order[i];
            size[newPar[x]] += size[x];
        }
        return size;
    }
};