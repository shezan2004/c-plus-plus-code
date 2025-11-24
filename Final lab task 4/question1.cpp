#include <iostream>
#include <iomanip>
#include <climits>

using namespace std;

pair<int**, int**> MatrixChainOrder(const int* d, int n) {
    int** M = new int*[n + 1];
    int** S = new int*[n + 1];
    for (int i = 0; i <= n; i++) {
        M[i] = new int[n + 1]();
        S[i] = new int[n + 1]();
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            M[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j];
                if (q < M[i][j]) {
                    M[i][j] = q;
                    S[i][j] = k;
                }
            }
        }
    }
    return make_pair(M, S);
}

void PrintTable(int** table, int n, const string &name) {
    cout << name << " Table:" << endl;
    cout << "   ";
    for (int j = 1; j <= n; j++) {
        cout << setw(6) << j;
    }
    cout << endl;

    for (int i = 1; i <= n; i++) {
        cout << setw(2) << i << " ";
        for (int j = 1; j <= n; j++) {
            if (i > j)
                cout << setw(6) << " ";
            else
                cout << setw(6) << table[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void PrintOptimalCost(int** M, int n) {
    cout << "Minimum number of multiplications is: " << M[1][n] << endl;
}

int main() {
    int arr[] = {30, 35, 15, 5, 10, 20, 25};
    int n = sizeof(arr) / sizeof(arr[0]) - 1;
    int* d = arr;

    pair<int**, int**> result = MatrixChainOrder(d, n);
    int** M = result.first;
    int** S = result.second;

    PrintTable(M, n, "M");
    PrintTable(S, n, "S");

    PrintOptimalCost(M, n);

    for (int i = 0; i <= n; i++) {
        delete[] M[i];
        delete[] S[i];
    }
    delete[] M;
    delete[] S;

    return 0;
}
