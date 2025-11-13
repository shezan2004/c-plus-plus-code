#include <iostream>

using namespace std;


void multiplyMatrices(const double matrix1[3][3], const double matrix2[3][3], double result[3][3]) {

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            result[i][j] = 0.0;
        }
    }


    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}


void displayMatrix(const double matrix[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

    double matrix1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    double matrix2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    cout << "Matrix 1:" << endl;
    displayMatrix(matrix1);

    cout << "Matrix 2:" << endl;
    displayMatrix(matrix2);


    double resultMatrix[3][3];
    multiplyMatrices(matrix1, matrix2, resultMatrix);

    cout << "Resultant Matrix:" << endl;
    displayMatrix(resultMatrix);

    return 0;
}

