class Solution {
public:
    struct Node {
        int len = 0;
        int pref = 0, suf = 0, best = 0;
        char leftChar = 0, rightChar = 0;
    };
    
    vector<Node> tree;
    string str;
    int n;
    
    Node merge(const Node& L, const Node& R) {
        Node res;
        res.len = L.len + R.len;
        res.leftChar = L.leftChar;
        res.rightChar = R.rightChar;
        
        res.pref = L.pref;
        if (L.pref == L.len && L.rightChar == R.leftChar) {
            res.pref += R.pref;
        }
        
        res.suf = R.suf;
        if (R.suf == R.len && R.leftChar == L.rightChar) {
            res.suf += L.suf;
        }
        
        res.best = max(L.best, R.best);
        if (L.rightChar == R.leftChar) {
            res.best = max(res.best, L.suf + R.pref);
        }
        
        return res;
    }
    
    void build(int node, int l, int r) {
        if (l == r) {
            tree[node].len = 1;
            tree[node].pref = tree[node].suf = tree[node].best = 1;
            tree[node].leftChar = tree[node].rightChar = str[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2*node, l, mid);
        build(2*node+1, mid+1, r);
        tree[node] = merge(tree[2*node], tree[2*node+1]);
    }
    
    void update(int node, int l, int r, int idx, char c) {
        if (l == r) {
            tree[node].leftChar = tree[node].rightChar = c;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid) update(2*node, l, mid, idx, c);
        else update(2*node+1, mid+1, r, idx, c);
        tree[node] = merge(tree[2*node], tree[2*node+1]);
    }
    
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        str = s;
        n = s.size();
        tree.assign(4 * n, Node());
        build(1, 0, n - 1);
        
        int k = queryCharacters.size();
        vector<int> ans(k);
        for (int i = 0; i < k; i++) {
            int idx = queryIndices[i];
            char c = queryCharacters[i];
            str[idx] = c; // keep str in sync (not strictly needed but safe)
            update(1, 0, n - 1, idx, c);
            ans[i] = tree[1].best;
        }
        
        return ans;
    }
};