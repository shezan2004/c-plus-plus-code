#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <string>

using namespace std;

const int UNVISITED = 0;
const int VISITING = 1;
const int VISITED = 2;

void DFS(int u, const vector<vector<int> > &graph, vector<int> &state, vector<int> &parent, map<string, vector<pair<int, int> > > &edgeClassification) {
    state[u] = VISITING;

    for (size_t i = 0; i < graph[u].size(); ++i) {
        int v = graph[u][i];
        if (state[v] == UNVISITED) {
            parent[v] = u;
            edgeClassification["Tree Edge"].push_back(make_pair(u, v));
            DFS(v, graph, state, parent, edgeClassification);
        } else if (state[v] == VISITING) {
            if (v != parent[u]) {
                edgeClassification["Back Edge"].push_back(make_pair(u, v));
            }
        } else if (state[v] == VISITED) {
            if (parent[v] == u) {
                edgeClassification["Forward Edge"].push_back(make_pair(u, v));
            } else {
                edgeClassification["Cross Edge"].push_back(make_pair(u, v));
            }
        }
    }

    state[u] = VISITED;
}

void ClassifyEdges(const vector<vector<int> > &graph, int numVertices) {
    vector<int> state(numVertices, UNVISITED);
    vector<int> parent(numVertices, -1);
    map<string, vector<pair<int, int> > > edgeClassification;

    for (int u = 0; u < numVertices; ++u) {
        if (state[u] == UNVISITED) {
            DFS(u, graph, state, parent, edgeClassification);
        }
    }

    for (map<string, vector<pair<int, int> > >::iterator it = edgeClassification.begin(); it != edgeClassification.end(); ++it) {
        cout << it->first << ":\n";
        for (size_t i = 0; i < it->second.size(); ++i) {
            cout << "(" << it->second[i].first << ", " << it->second[i].second << ")\n";
        }
        cout << endl;
    }
}

int main() {
    int numVertices = 6;

    vector<vector<int> > graph(6);
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[2].push_back(3);
    graph[3].push_back(4);
    graph[3].push_back(5);
    graph[4].push_back(5);
    graph[5].push_back(2);
    graph[2].push_back(0);

    cout << "Classifying edges of the graph:\n\n";
    ClassifyEdges(graph, numVertices);

    return 0;
}
