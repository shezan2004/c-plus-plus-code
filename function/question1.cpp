#include<iostream>
using namespace std;

void inputMatrix(int mainMatrix[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> mainMatrix[i][j];
        }
    }
}

int dSum(int mainMatrix[5][5]) {
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += mainMatrix[i][i];
        sum += mainMatrix[i][4 - i];
    }
    sum -= mainMatrix[2][2];
    return sum;
}

int calculateBorderSum(int mainMatrix[5][5]) {
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += mainMatrix[i][0];
        sum += mainMatrix[i][4];
        if (i != 2) {
            sum += mainMatrix[0][i];
            sum += mainMatrix[4][i];
        }
    }
    return sum;
}

int main() {
    int mainMatrix[5][5];

    inputMatrix(mainMatrix);

    cout << "Sum of diagonal elements: " << dSum(mainMatrix) << endl;
    cout << "Sum of border elements: " << calculateBorderSum(mainMatrix) << endl;

    return 0;
}

