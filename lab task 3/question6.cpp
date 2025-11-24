#include <iostream>
using namespace std;

const int MAX = 100;

void multiplyMatrices(int mat1[][MAX], int mat2[][MAX], int resultMatrix[][MAX], int row1, int col1, int row2, int col2) {
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            resultMatrix[i][j] = 0;
            for (int k = 0; k < col1; k++) {
                resultMatrix[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void transposeMatrix(int mat[][MAX], int transposed[][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = mat[i][j];
        }
    }
}

void displayMatrix(int mat[][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int A[3][MAX] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };
    int B[4][MAX] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12} };
    int C[3][MAX] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };
    int D[4][MAX] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12} };

    int row1 = 3, col1 = 4;
    int row2 = 4, col2 = 3;
    int row3 = 3, col3 = 4;
    int row4 = 4, col4 = 3;

    int E[3][MAX], F[3][MAX], G[3][MAX];

    multiplyMatrices(A, B, E, row1, col1, row2, col2);
    multiplyMatrices(E, C, F, row1, col2, row3, col3);
    multiplyMatrices(F, D, G, row1, col3, row4, col4);

    cout << "Resulting Matrix G (after multiplying A, B, C, and D):" << endl;
    displayMatrix(G, row1, col4);

    int G_transpose[MAX][MAX];
    transposeMatrix(G, G_transpose, row1, col4);

    cout << "Transposed Matrix of G:" << endl;
    displayMatrix(G_transpose, col4, row1);

    return 0;
}
