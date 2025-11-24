#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <limits>
#include <tuple>
#include <climits>
using namespace std;

unordered_map<int, vector<pair<int, int>>> buildGraph(const vector<tuple<int, int, int>>& edges, bool is_directed) {
    unordered_map<int, vector<pair<int, int>>> graph;
    for (const auto& edge : edges) {
        int u = get<0>(edge);
        int v = get<1>(edge);
        int weight = get<2>(edge);
        graph[u].push_back({v, weight});
        if (!is_directed) {
            graph[v].push_back({u, weight});
        }
    }
    return graph;
}

string dijkstra(const unordered_map<int, vector<pair<int, int>>>& graph, int source, int destination) {
    unordered_map<int, int> distances;
    for (const auto& entry : graph) {
        distances[entry.first] = INT_MAX;  
    }
    distances[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int current_distance = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();

        if (current_distance > distances[current_node]) {
            continue;
        }

        for (const auto& neighbor : graph.at(current_node)) {
            int neighbor_node = neighbor.first;
            int weight = neighbor.second;

            int new_distance = current_distance + weight;
            if (new_distance < distances[neighbor_node]) {
                distances[neighbor_node] = new_distance;
                pq.push({new_distance, neighbor_node});
            }
        }
    }

    if (distances[destination] != INT_MAX) {
        return to_string(distances[destination]);
    } else {
        return "No path";
    }
}

int main() {
    vector<tuple<int, int, int>> edges = {
        {1, 2, 1},
        {2, 3, 2},
        {1, 3, 4},
        {3, 4, 1},
        {2, 4, 5}
    };
    bool is_directed = false;
    int source = 1, destination = 4;

    auto graph = buildGraph(edges, is_directed);

    cout << "Shortest Path from " << source << " to " << destination << ": " 
         << dijkstra(graph, source, destination) << endl;

    return 0;
}
