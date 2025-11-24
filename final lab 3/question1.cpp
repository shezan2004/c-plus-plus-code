#include <iostream>
#include <cstring> 
using namespace std;

const int MAX_NODES = 10; 
const int MAX_EDGES = 10; 


struct Graph {
    char nodes[MAX_NODES];
    char edges[MAX_NODES][MAX_EDGES];
    int edgeCount[MAX_NODES]; 
    int nodeCount;
};


void addEdge(Graph &graph, char from, char to) {
    for (int i = 0; i < graph.nodeCount; ++i) {
        if (graph.nodes[i] == from) {
            graph.edges[i][graph.edgeCount[i]] = to;
            graph.edgeCount[i]++;
            return;
        }
    }
}


int findNodeIndex(const Graph &graph, char node) {
    for (int i = 0; i < graph.nodeCount; ++i) {
        if (graph.nodes[i] == node) {
            return i;
        }
    }
    return -1;
}


bool bfsPath(const Graph &graph, char start, char destination, char path[], int &pathLength) {
    bool visited[MAX_NODES] = {false};
    char parent[MAX_NODES];
    memset(parent, 0, sizeof(parent));
    char queue[MAX_NODES];
    int front = 0, rear = 0;

   
    queue[rear++] = start;
    visited[findNodeIndex(graph, start)] = true;

    while (front < rear) {
        char current = queue[front++];
        int currentIndex = findNodeIndex(graph, current);

        
        if (current == destination) {
            pathLength = 0;
            for (char at = destination; at != 0; at = parent[findNodeIndex(graph, at)]) {
                path[pathLength++] = at;
            }
            
            for (int i = 0; i < pathLength / 2; ++i) {
                swap(path[i], path[pathLength - i - 1]);
            }
            return true;
        }

        
        for (int i = 0; i < graph.edgeCount[currentIndex]; ++i) {
            char neighbor = graph.edges[currentIndex][i];
            int neighborIndex = findNodeIndex(graph, neighbor);

            if (!visited[neighborIndex]) {
                queue[rear++] = neighbor;
                visited[neighborIndex] = true;
                parent[neighborIndex] = current;
            }
        }
    }
    return false; 
}

int main() {
    
    Graph graph = {{'A', 'F', 'C', 'B', 'D', 'E', 'G', 'J', 'K'}, {}, {}, 9};

    
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

    char path[MAX_NODES];
    int pathLength = 0;

    if (bfsPath(graph, start, destination, path, pathLength)) {
        cout << "Path from " << start << " to " << destination << ": ";
        for (int i = 0; i < pathLength; ++i) {
            cout << path[i] << " ";
        }
        cout << endl;
    } else {
        cout << "No path found from " << start << " to " << destination << endl;
    }

    return 0;
}
