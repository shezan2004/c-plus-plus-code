#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();

void printMatrix(const vector<vector<int>>& matrix, const string& name, int step) {
    cout << name << "(" << step << "):\n";
    for (const auto& row : matrix) {
        for (const auto& value : row) {
            if (value == INF) {
                cout << setw(5) << "INF";
            } else {
                cout << setw(5) << value;
            }
        }
        cout << endl;
    }
    cout << endl;
}

void floydWarshall(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<int>> dist = graph;
    vector<vector<int>> pred(n, vector<int>(n, -1));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j && graph[i][j] != INF) {
                pred[i][j] = i + 1;
            }
        }
    }

    cout << "Initial Distance Matrix:\n";
    printMatrix(dist, "D", 0);
    cout << "Initial Predecessor Matrix:\n";
    printMatrix(pred, "Π", 0);

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    pred[i][j] = pred[k][j];
                }
            }
        }

        cout << "After step " << k + 1 << ":\n";
        printMatrix(dist, "D", k + 1);
        printMatrix(pred, "Π", k + 1);
    }
}

int main() {
    vector<vector<int>> graph = {
        {0, 3, 8, INF, -4},
        {INF, 0, INF, 1, 7},
        {INF, 4, 0, INF, INF},
        {2, INF, -5, 0, INF},
        {INF, INF, INF, 6, 0}
    };

    floydWarshall(graph);

    return 0;
}
