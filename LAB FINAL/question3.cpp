#include <iostream>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <utility>
using namespace std;
class Graph {
private: 
    int V; 
    list<int>* adj; 
    map<pair<int, int>, string> edgeClassification;
    void DFSUtil(int v, bool visited[], stack<int>& Stack);
    void DFSClassify(int v, bool visited[], int discovery[], int low[], int parent[]);
    void SCCUtil(int v, bool visited[], stack<int>& Stack, int discovery[], int low[], int& time);
    bool isCyclicUtil(int v, bool visited[], bool* recStack);
public:
    Graph(int V);
    ~Graph();
    void addEdge(int v, int w);
    void classifyEdges();
    void findSCCs();
    bool isDAG();
    void printGraph();
};
Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}
Graph::~Graph() {
    delete[] adj;
}
void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}
void Graph::DFSUtil(int v, bool visited[], stack<int>& Stack) {
    visited[v] = true;

    for (auto it = adj[v].begin(); it != adj[v].end(); ++it) {
        if (!visited[*it]) {
            DFSUtil(*it, visited, Stack);
        }
    }
    Stack.push(v);
}
void Graph::DFSClassify(int v, bool visited[], int discovery[], int low[], int parent[]) {
    static int time = 0;
    visited[v] = true;
    discovery[v] = low[v] = ++time;
    for (auto it = adj[v].begin(); it != adj[v].end(); ++it) {
        int u = *it;

        if (!visited[u]) {
            parent[u] = v;
            DFSClassify(u, visited, discovery, low, parent);

            low[v] = min(low[v], low[u]);

            if (low[u] > discovery[v]) {
                edgeClassification[{v, u}] = "Tree Edge";
            }
        } else if (u != parent[v]) {
            if (discovery[u] < discovery[v]) {
                edgeClassification[{v, u}] = "Back Edge";
            } else {
                edgeClassification[{v, u}] = "Forward/Cross Edge";
            }
            low[v] = min(low[v], discovery[u]);
        }
    }
}
void Graph::classifyEdges() {
    bool* visited = new bool[V]();
    int* discovery = new int[V];
    int* low = new int[V];
    int* parent = new int[V];
    for (int i = 0; i < V; ++i) {
        parent[i] = -1;
    }
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            DFSClassify(i, visited, discovery, low, parent);
        }
    }
    for (auto& edge : edgeClassification) {
        cout << "Edge " << edge.first.first << " -> " << edge.first.second
             << " is a " << edge.second << "\n";
    }
    delete[] visited;
    delete[] discovery;
    delete[] low;
    delete[] parent;
}
void Graph::SCCUtil(int v, bool visited[], stack<int>& Stack, int discovery[], int low[], int& time) {
    static int sccCount = 0;
    visited[v] = true;
    discovery[v] = low[v] = ++time;
    Stack.push(v);
    for (auto it = adj[v].begin(); it != adj[v].end(); ++it) {
        int u = *it;
        if (!visited[u]) {
            SCCUtil(u, visited, Stack, discovery, low, time);
            low[v] = min(low[v], low[u]);
        } else {
            low[v] = min(low[v], discovery[u]);
        }
    }
    if (low[v] == discovery[v]) {
        cout << "SCC " << ++sccCount << ": ";
        while (Stack.top() != v) {
            cout << Stack.top() << " ";
            Stack.pop();
        }
        cout << Stack.top() << "\n";
        Stack.pop();
    }
}
void Graph::findSCCs() {
    bool* visited = new bool[V]();
    int* discovery = new int[V];
    int* low = new int[V];
    stack<int> Stack;
    int time = 0;
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            SCCUtil(i, visited, Stack, discovery, low, time);
        }
    }
    delete[] visited;
    delete[] discovery;
    delete[] low;
}
bool Graph::isCyclicUtil(int v, bool visited[], bool* recStack) {
    visited[v] = true;
    recStack[v] = true;
    for (auto it = adj[v].begin(); it != adj[v].end(); ++it) {
        if (!visited[*it] && isCyclicUtil(*it, visited, recStack)) {
            return true;
        } else if (recStack[*it]) {
            return true;
        }
    }
    recStack[v] = false;
    return false;
}
bool Graph::isDAG() {
    bool* visited = new bool[V]();
    bool* recStack = new bool[V]();
    for (int i = 0; i < V; ++i) {
        if (!visited[i] && isCyclicUtil(i, visited, recStack)) {
            delete[] visited;
            delete[] recStack;
            return false;
        }
    }
    delete[] visited;
    delete[] recStack;
    return true;
}
void Graph::printGraph() {
    cout << "Graph adjacency list:\n";
    for (int i = 0; i < V; ++i) {
        cout << i << ": ";
        for (auto it = adj[i].begin(); it != adj[i].end(); ++it) {
            cout << *it << " ";
        }
        cout << "\n";
    }
}
int main() {
    int V = 5;
    Graph g(V);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4 );
    cout << "\nChecking if the graph is a DAG:\n";
    if (g.isDAG()) {
        cout << "The graph is a DAG.\n";
    } else {
        cout << "The graph is not a DAG.\n";
        return 0;
    }
    cout << "Graph structure:\n";
    g.printGraph();
    cout << "\nClassifying edges:\n";
    g.classifyEdges();
    cout << "\nFinding strongly connected components:\n";
    g.findSCCs();
    return 0;
}
