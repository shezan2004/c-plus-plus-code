#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <algorithm>  
using namespace std;

class Graph {
public:
    int vertices;
    unordered_map<int, vector<int>> adjList;  

    Graph(int v) {
        vertices = v;
    }

   
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);  
    }

  
    vector<int> bfs(int start, int destination) {
        vector<bool> visited(vertices, false);
        vector<int> parent(vertices, -1);
        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            if (current == destination) {
                return getPath(parent, start, destination);
            }

            for (int neighbor : adjList[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    parent[neighbor] = current;
                    q.push(neighbor);
                }
            }
        }
        return {};
    }


    vector<int> dfs(int start, int destination) {
        vector<bool> visited(vertices, false);
        vector<int> parent(vertices, -1);
        if (dfsHelper(start, destination, visited, parent)) {
            return getPath(parent, start, destination);
        }
        return {};
    }

private:
   
    bool dfsHelper(int current, int destination, vector<bool>& visited, vector<int>& parent) {
        visited[current] = true;
        if (current == destination) return true;

        for (int neighbor : adjList[current]) {
            if (!visited[neighbor]) {
                parent[neighbor] = current;
                if (dfsHelper(neighbor, destination, visited, parent)) {
                    return true;
                }
            }
        }
        return false;
    }

    
    vector<int> getPath(const vector<int>& parent, int start, int destination) {
        vector<int> path;
        int current = destination;
        while (current != -1) {
            path.push_back(current);
            current = parent[current];
        }
        reverse(path.begin(), path.end());  
        return path;
    }
};

int main() {
    
    Graph g(6);

  
    vector<pair<int, int>> edges = {
        {0, 1}, {0, 2}, {1, 3}, {1, 4}, 
        {2, 4}, {3, 5}, {4, 5}
    };
    for (auto& edge : edges) {
        g.addEdge(edge.first, edge.second);
    }

    
    cout << "Graph - Adjacency List:" << endl;
    for (int node = 0; node < g.vertices; ++node) {
        cout << node << ": ";
        for (int neighbor : g.adjList[node]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }

  
    int start = 0;
    int destination = 5;

   
    cout << "\nFinding path from " << start << " to " << destination << " using BFS:" << endl;
    vector<int> bfs_path = g.bfs(start, destination);
    if (!bfs_path.empty()) {
        cout << "Path (BFS): ";
        for (int node : bfs_path) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        cout << "No path found using BFS." << endl;
    }

   
    cout << "\nFinding path from " << start << " to " << destination << " using DFS:" << endl;
    vector<int> dfs_path = g.dfs(start, destination);
    if (!dfs_path.empty()) {
        cout << "Path (DFS): ";
        for (int node : dfs_path) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        cout << "No path found using DFS." << endl;
    }

    return 0;
}
