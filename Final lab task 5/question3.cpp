#include <iostream>
#include <vector>
#include <set>

using namespace std;

void extractSpanningTree(int vertices, vector<pair<int, pair<int, int>>>& edges) {
    set<int> includedVertices;
    vector<pair<int, pair<int, int>>> spanningTreeEdges;
    int totalWeight = 0;
    vector<int> sequence;

    cout << "Input Graph Edges (u -> v, weight):" << endl;
    for (auto edge : edges) {
        cout << edge.first << " -> " << edge.second.first << " (weight: " << edge.second.second << ")" << endl;
    }

    cout << "\nSpanning Tree Construction Sequence:" << endl;
    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second.first;
        int weight = edge.second.second;

        
        if (includedVertices.count(u) == 0 || includedVertices.count(v) == 0) {
            spanningTreeEdges.push_back(edge);
            includedVertices.insert(u);
            includedVertices.insert(v);
            totalWeight += weight;

            sequence.push_back(u);
            sequence.push_back(v);
            cout << "Added edge: " << u << " -> " << v << " (weight: " << weight << ")" << endl;
        }

        
        if (spanningTreeEdges.size() == vertices - 1) {
            break;
        }
    }

    cout << "\nSpanning Tree Edges (u -> v, weight):" << endl;
    for (auto edge : spanningTreeEdges) {
        cout << edge.first << " -> " << edge.second.first << " (weight: " << edge.second.second << ")" << endl;
    }

    cout << "\nTotal Weight of Spanning Tree: " << totalWeight << endl;

    
    cout << "\nSpanning Tree Sequence: ";
    for (size_t i = 0; i < sequence.size(); i++) {
        if (i > 0 && sequence[i] == sequence[i - 1]) continue; 
        if (i > 0) cout << " -> ";
        cout << sequence[i];
    }
    cout << endl;
}

int main() {
    int vertices = 6;
    vector<pair<int, pair<int, int>>> edges = {
        {0, {1, 4}}, {0, {2, 3}}, {1, {3, 2}}, {2, {3, 5}}, {3, {4, 1}}, {4, {5, 6}}, {2, {5, 7}}
    };

    cout << "Number of vertices: " << vertices << endl;
    extractSpanningTree(vertices, edges);

    return 0;
}
