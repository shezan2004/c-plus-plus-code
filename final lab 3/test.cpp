#include <iostream>
#include <queue>
#include <map>
#include <algorithm> // For reverse function

using namespace std;

// Max number of neighbors a node can have (adjust if needed)
const int MAX_NEIGHBORS = 10;

// Structure to represent a graph node's adjacency list
struct Node {
    char neighbors[MAX_NEIGHBORS];
    int neighborCount;
};

// Function to add an edge to the graph
void addEdge(map<char, Node> &graph, char from, char to) {
    graph[from].neighbors[graph[from].neighborCount++] = to;
}

// Function to perform BFS and find the path
bool bfsPath(map<char, Node> &graph, char start, char destination, char path[], int &pathLength) {
    map<char, bool> visited;
    map<char, char> parent;
    queue<char> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        char current = q.front();
        q.pop();

        if (current == destination) {
            // Backtrack to build the path
            char temp = destination;
            pathLength = 0;
            while (temp != start) {
                path[pathLength++] = temp;
                temp = parent[temp];
            }
            path[pathLength++] = start;
            reverse(path, path + pathLength);
            return true;
        }

        for (int i = 0; i < graph[current].neighborCount; i++) {
            char neighbor = graph[current].neighbors[i];
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
                parent[neighbor] = current;
            }
        }
    }
    return false; // No path found
}

int main() {
    // Graph adjacency list representation
    map<char, Node> graph;

    // Initialize neighbor counts to zero
    for (auto &entry : graph) {
        entry.second.neighborCount = 0;
    }

    // Constructing the graph
    addEdge(graph, 'A', 'F');
    addEdge(graph, 'A', 'C');
    addEdge(graph, 'A', 'B');
    addEdge(graph, 'F', 'C');
    addEdge(graph, 'F', 'D');
    addEdge(graph, 'C', 'B');
    addEdge(graph, 'B', 'G');
    addEdge(graph, 'D', 'C');
    addEdge(graph, 'E', 'D');
    addEdge(graph, 'E', 'J');
    addEdge(graph, 'E', 'C');
    addEdge(graph, 'G', 'E');
    addEdge(graph, 'G', 'C');
    addEdge(graph, 'J', 'D');
    addEdge(graph, 'J', 'K');
    addEdge(graph, 'K', 'E');
    addEdge(graph, 'K', 'G');

    char start, destination;
    cout << "Enter the starting node: ";
    cin >> start;
    cout << "Enter the destination node: ";
    cin >> destination;

    char path[100]; // Array to store the path
    int pathLength = 0;

    if (bfsPath(graph, start, destination, path, pathLength)) {
        cout << "Path from " << start << " to " << destination << ": ";
        for (int i = 0; i < pathLength; i++) {
            cout << path[i] << " ";
        }
        cout << endl;
    } else {
        cout << "No path found from " << start << " to " << destination << endl;
    }

    return 0;
}
