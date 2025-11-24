#include <iostream>
#include <vector>
#include <limits>
#include <unordered_map>
#include <tuple>
#include <set>
#include <climits>

using namespace std;


vector<tuple<int, int, int>> buildEdgeList(const vector<tuple<int, int, int>>& edges, bool is_directed) {
    vector<tuple<int, int, int>> edgeList = edges;
    if (!is_directed) {
       
        for (const auto& edge : edges) {
            int u = get<0>(edge);
            int v = get<1>(edge);
            int weight = get<2>(edge);
            edgeList.push_back(make_tuple(v, u, weight));
        }
    }
    return edgeList;
}


string bellmanFord(const vector<tuple<int, int, int>>& edges, int source, int destination, const set<int>& vertices) {
    unordered_map<int, int> distances;
    for (int vertex : vertices) {
        distances[vertex] = INT_MAX;
    }
    distances[source] = 0;

    int num_vertices = vertices.size();
    for (int i = 0; i < num_vertices - 1; ++i) {
        for (const auto& edge : edges) {
            int u = get<0>(edge);
            int v = get<1>(edge);
            int weight = get<2>(edge);

            if (distances[u] != INT_MAX && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
            }
        }
    }

  
    for (const auto& edge : edges) {
        int u = get<0>(edge);
        int v = get<1>(edge);
        int weight = get<2>(edge);

        if (distances[u] != INT_MAX && distances[u] + weight < distances[v]) {
            return "Graph contains a negative weight cycle";
        }
    }

    
    if (distances[destination] != INT_MAX) {
        return to_string(distances[destination]);
    } else {
        return "No path";
    }
}

int main() {
    int num_edges = 5;
    vector<tuple<int, int, int>> edges = {
        {1, 2, 1},
        {2, 3, -2},
        {1, 3, 4},
        {3, 4,- 1},
        {2, 4, 5}
    };
    bool is_directed = true;
    int source = 1, destination = 4;
    set<int> vertices = {1, 2, 3, 4};

    edges = buildEdgeList(edges, is_directed);
    
    cout << "Shortest Path from " << source << " to " << destination << ": " 
         << bellmanFord(edges, source, destination, vertices) << endl;

    return 0;
}
