#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Enter Rows and Columns: ";
    cin >> a >> b;

    int c[a][b];
    cout << "\nEnter Elements: ";
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cin >> c[i][j];
        }
    }

    int rowStart = 0, rowEnd = a - 1;
    int colStart = 0, colEnd = b - 1;
    int sum = 0;

    while (rowStart <= rowEnd && colStart <= colEnd) {
        // Traverse the upper row
        for (int col = colStart; col <= colEnd; col++) {
            sum += c[rowStart][col];
        }
        rowStart++;

        // Traverse the right column
        for (int row = rowStart; row <= rowEnd; row++) {
            sum += c[row][colEnd];
        }
        colEnd--;

        // Traverse the bottom row, if still within bounds
        if (rowStart <= rowEnd) {
            for (int col = colEnd; col >= colStart; col--) {
                sum += c[rowEnd][col];
            }
            rowEnd--;
        }

        // Traverse the left column, if still within bounds
        if (colStart <= colEnd) {
            for (int row = rowEnd; row >= rowStart; row--) {
                sum += c[row][colStart];
            }
            colStart++;
        }
    }

    cout << "Sum: " << sum;

    return 0;
}
