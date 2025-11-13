#include <iostream>

using namespace std;

int fact(int f) {
    int result = 1;
    for (int i = 1; i <= f; i++) {
        result = result * i;
    }
    return result;
}

double nCr(int n, int r) {
    double result = fact(n) / (fact(r) * fact(n - r));
    return result;
}

double nPr(int n, int r) {
    double result = fact(n) / fact(n - r);
    return result;
}

void pascalsTriangle(int rows) {
    for (int i = 0; i <= rows; i++) {
        for (int j = 0; j <= i; j++) {
            cout << nCr(i, j) << " ";
        }
        cout << endl;
    }
}

int main() {
    pascalsTriangle(10);
    return 0;
}

