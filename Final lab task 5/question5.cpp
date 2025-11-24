#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int src, dest, weight;
};


class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};


void kruskalMST(vector<Edge>& edges, int V) {
    
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    DisjointSet ds(V);
    vector<Edge> mst;
    int mstWeight = 0;

    cout << "Edge \tWeight\n";
  

   
    for (auto& edge : edges) {
        int u = edge.src;
        int v = edge.dest;

       
        if (ds.find(u) != ds.find(v)) {
            mst.push_back(edge);
            mstWeight += edge.weight;
            ds.unionSets(u, v);
            cout << u << " -> " << v << "\t" << edge.weight << endl;
        }
    }

    
    cout << "Total weight of MST: " << mstWeight << endl;
}

int main() {
    int V = 4; 
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskalMST(edges, V);

    return 0;
}
