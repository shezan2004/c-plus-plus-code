class Solution {
public:
    int n, K;
    struct Node {
        int M[5][5];
        int P[5];
    };
    vector<Node> tree;
    vector<int> a;

    Node identityNode(){
        Node nd;
        for(int r=0;r<K;r++){
            for(int s=0;s<K;s++) nd.M[r][s]=0;
            nd.P[r]=r;
        }
        return nd;
    }

    Node leafNode(long long val){
        Node nd;
        int vm = (int)(val % K);
        for(int r=0;r<K;r++){
            int ns = (r*vm)%K;
            for(int s=0;s<K;s++) nd.M[r][s] = (s==ns)?1:0;
            nd.P[r]=ns;
        }
        return nd;
    }

    Node mergeNodes(const Node&L, const Node&R){
        Node res;
        for(int r=0;r<K;r++){
            int p = L.P[r];
            for(int s=0;s<K;s++){
                res.M[r][s] = L.M[r][s] + R.M[p][s];
            }
            res.P[r] = R.P[p];
        }
        return res;
    }

    void build(int idx,int l,int r){
        if(l==r){ tree[idx]=leafNode(a[l]); return;}
        int mid=(l+r)/2;
        build(2*idx,l,mid);
        build(2*idx+1,mid+1,r);
        tree[idx]=mergeNodes(tree[2*idx], tree[2*idx+1]);
    }

    void update(int idx,int l,int r,int pos,int val){
        if(l==r){ a[l]=val; tree[idx]=leafNode(val); return;}
        int mid=(l+r)/2;
        if(pos<=mid) update(2*idx,l,mid,pos,val);
        else update(2*idx+1,mid+1,r,pos,val);
        tree[idx]=mergeNodes(tree[2*idx],tree[2*idx+1]);
    }

    Node query(int idx,int l,int r,int ql,int qr){
        if(qr<l || r<ql) return identityNode();
        if(ql<=l && r<=qr) return tree[idx];
        int mid=(l+r)/2;
        Node L = query(2*idx,l,mid,ql,qr);
        Node R = query(2*idx+1,mid+1,r,ql,qr);
        return mergeNodes(L,R);
    }

    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        n = (int)nums.size();
        K = k;
        a = nums;
        tree.assign(4*n, Node());
        build(1,0,n-1);
        vector<int> result;
        result.reserve(queries.size());
        int rInit = 1 % K;
        for(auto& q: queries){
            int index=q[0], value=q[1], start=q[2], x=q[3];
            update(1,0,n-1,index,value);
            Node res = query(1,0,n-1,start,n-1);
            result.push_back(res.M[rInit][x]);
        }
        return result;
    }
};