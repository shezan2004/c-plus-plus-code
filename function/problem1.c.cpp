#include<iostream>
using namespace std;
int calculateBorderSum(int matrix[5][5]) {
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum =sum + matrix[i][0];
        sum =sum+ matrix[i][4];
        if (i != 2) {
            sum= sum + matrix[0][i];
            sum= sum + matrix[4][i];
        }
    }
    return sum;
}

void inputMatrix(int matrix[5][5]) {
    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << "Enter element at position (" << i + 1 << "," << j + 1 << "): ";
            cin >> matrix[i][j];
        }
    }
}

int main() {
    int myMatrix[5][5];

    inputMatrix(myMatrix);

    cout << "Sum of border elements: " << calculateBorderSum(myMatrix) << endl;

    return 0;
}
