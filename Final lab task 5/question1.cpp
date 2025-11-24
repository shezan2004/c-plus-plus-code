#include <iostream>
#include <queue>
#include <list>
#include <vector>

using namespace std;

void topologicalSort(int vertices, list<int> adj[]) {
    int inDegree[vertices] = {0};

    
    for (int i = 0; i < vertices; i++) {
        for (int neighbor : adj[i]) {
            inDegree[neighbor]++;
        }
    }

    cout << "Nodes with zero in-degree: ";
    bool hasZeroInDegree = false;
    for (int i = 0; i < vertices; i++) {
        if (inDegree[i] == 0) {
            cout << i << " ";
            hasZeroInDegree = true;
        }
    }
    if (!hasZeroInDegree) {
        cout << "None";
    }
    cout << endl;

    queue<int> zeroInDegree;
    for (int i = 0; i < vertices; i++) {
        if (inDegree[i] == 0) {
            zeroInDegree.push(i);
        }
    }

    cout << "Topological Order Step by Step:\n";
    int count = 0;
    vector<int> topologicalOrder;

    while (!zeroInDegree.empty()) {
        int vertex = zeroInDegree.front();
        zeroInDegree.pop();
        topologicalOrder.push_back(vertex);
        count++;

        
        for (int neighbor : adj[vertex]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                zeroInDegree.push(neighbor);
            }
        }

        cout << "Topological Order: ";
        for (int v : topologicalOrder) {
            cout << v << " ";
        }
        cout << endl;
    }

  
    if (count != vertices) {
        cout << "\nThe graph contains a cycle and is not a DAG (Directed Acyclic Graph)." << endl;
    } else {
        cout << "\nThe graph is a DAG. Final Topological Order: ";
        for (int v : topologicalOrder) {
            cout << v << " ";
        }
        cout << endl;
    }
}

int main() {
    int vertices = 6;
    int edges = 6;

    list<int> adj[vertices];

    
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);
 
    cout << "Number of vertices: " << vertices << endl;
    cout << "Number of edges: " << edges << endl;
    cout << "Edges (u -> v):" << endl;
    cout << "5 -> 2\n5 -> 0\n4 -> 0\n4 -> 1\n2 -> 3\n3 -> 1" << endl;
    topologicalSort(vertices, adj);
    return 0;
}
