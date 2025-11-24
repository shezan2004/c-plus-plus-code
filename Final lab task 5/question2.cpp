#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int v, vector<int> adj[], vector<bool>& visited, stack<int>& Stack) {
    visited[v] = true;
    for (int neighbor : adj[v]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, Stack);
        }
    }
    Stack.push(v);
}

void reverseGraph(int vertices, vector<int> adj[], vector<int> transpose[]) {
    for (int v = 0; v < vertices; v++) {
        for (int neighbor : adj[v]) {
            transpose[neighbor].push_back(v);
        }
    }
}

void dfsPrint(int v, vector<int> transpose[], vector<bool>& visited) {
    visited[v] = true;
    cout << v << " ";
    for (int neighbor : transpose[v]) {
        if (!visited[neighbor]) {
            dfsPrint(neighbor, transpose, visited);
        }
    }
}

void findSCCs(int vertices, vector<int> adj[]) {
    stack<int> Stack;
    vector<bool> visited(vertices, false);


    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, Stack);
        }
    }

    vector<int> transpose[vertices];
    reverseGraph(vertices, adj, transpose);


    fill(visited.begin(), visited.end(), false);
    cout << "Strongly Connected Components:\n";
    while (!Stack.empty()) {
        int v = Stack.top();
        Stack.pop();

        if (!visited[v]) {
            dfsPrint(v, transpose, visited);
            cout << endl;
        }
    }
}

int main() {
    int vertices = 5;
    vector<int> adj[vertices];

    adj[0].push_back(2);
    adj[0].push_back(3);
    adj[1].push_back(0);
    adj[2].push_back(1);
    adj[3].push_back(4);

    cout << "Number of vertices: " << vertices << endl;
    cout << "Edges (u -> v):" << endl;
    cout << "0 -> 2\n0 -> 3\n1 -> 0\n2 -> 1\n3 -> 4" << endl;

    findSCCs(vertices, adj);

    return 0;
}
