#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>  // For std::reverse
using namespace std;

bool bfsPathFinder(vector<vector<int> >& graph, int start, int destination, vector<int>& path) {
    vector<bool> visited(graph.size(), false);
    vector<int> parent(graph.size(), -1);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == destination) {
            int temp = destination;
            while (temp != -1) {
                path.push_back(temp);
                temp = parent[temp];
            }
            // Manually reverse the path
            reverse(path.begin(), path.end());
            return true;
        }

        for (size_t i = 0; i < graph[current].size(); ++i) {
            int neighbor = graph[current][i];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = current;
                q.push(neighbor);
            }
        }
    }

    return false; // No path found
}

int main() {
    int nodes, edges, start, destination;

    cout << "Enter the number of nodes: ";
    cin >> nodes;
    cout << "Enter the number of edges: ";
    cin >> edges;

    // Initialize the graph with the given number of nodes
    vector<vector<int> > graph(nodes);

    cout << "Enter the edges (u v format):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v); // Add edge from u to v
        graph[v].push_back(u); // Add edge from v to u (undirected graph)
    }

    cout << "Enter the starting node: ";
    cin >> start;
    cout << "Enter the destination node: ";
    cin >> destination;

    // Find the path using BFS
    vector<int> path;
    if (bfsPathFinder(graph, start, destination, path)) {
        cout << "Path from " << start << " to " << destination << ": ";
        for (size_t i = 0; i < path.size(); ++i) {
            cout << path[i] << " ";
        }
        cout << endl;
    } else {
        cout << "No path found from " << start << " to " << destination << "." << endl;
    }

    return 0;
}
