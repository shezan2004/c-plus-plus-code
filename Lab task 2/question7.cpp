#include <iostream>

using namespace std;

int main() {
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int mainDiagonalSum = 0;
    int secondaryDiagonalSum = 0;

    for (int i = 0; i < 3; i++) {
        mainDiagonalSum += matrix[i][i];      
        secondaryDiagonalSum += matrix[i][2 - i]; 
    }

    cout << "Sum of Main Diagonal: " << mainDiagonalSum << endl;
    cout << "Sum of Secondary Diagonal: " << secondaryDiagonalSum << endl;

    return 0;
}
