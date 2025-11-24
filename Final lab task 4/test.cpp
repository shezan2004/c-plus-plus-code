#include <iostream>
#include <vector>
#include <climits> // For INT_MAX

using namespace std;

// Matrix-Chain-Order function
pair<vector<vector<int>>, vector<vector<int>>> MatrixChainOrder(const vector<int> &d) {
    int n = d.size() - 1; // Number of matrices
    vector<vector<int>> M(n + 1, vector<int>(n + 1, 0)); // Cost table
    vector<vector<int>> S(n + 1, vector<int>(n + 1, 0)); // Split table

    for (int len = 2; len <= n; len++) {       // Chain length
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            M[i][j] = INT_MAX;                // Initialize to infinity
            for (int k = i; k < j; k++) {
                int q = M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j];
                if (q < M[i][j]) {            // Update minimum cost
                    M[i][j] = q;
                    S[i][j] = k;             // Store the split point
                }
            }
        }
    }
    return {M, S}; // Return the cost and split tables
}

// Function to print the optimal parenthesis order
void PrintOptimalParens(const vector<vector<int>> &S, int i, int j) {
    if (i == j) {
        cout << "A" << i;
    } else {
        cout << "(";
        PrintOptimalParens(S, i, S[i][j]);
        PrintOptimalParens(S, S[i][j] + 1, j);
        cout << ")";
    }
}

int main() {
    // Example input: dimensions of matrices
    vector<int> d = {30, 35, 15, 5, 10, 20, 25};

    // Call MatrixChainOrder to calculate M and S
    auto result = MatrixChainOrder(d);
    vector<vector<int>> M = result.first; // Cost matrix
    vector<vector<int>> S = result.second; // Split matrix

    // Output the minimum cost
    cout << "Minimum number of multiplications is: " << M[1][d.size() - 1] << endl;

    // Output the optimal parenthesis order
    cout << "Optimal parenthesis order: ";
    PrintOptimalParens(S, 1, d.size() - 1);
    cout << endl;

    return 0;
}
