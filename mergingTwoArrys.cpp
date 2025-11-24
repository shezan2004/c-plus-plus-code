#include <iostream>
using namespace std;

int main() {
    int arry1[] = {40, 30, 70, 90, 100};
    int arry2[] = {10, 15, 45, 20, 65, 6, 1};
    int a_length = sizeof(arry1) / sizeof(arry1[0]);
    int b_length = sizeof(arry2) / sizeof(arry2[0]);
    int c[a_length + b_length];

    // Copy elements from arry1 to c
    for (int i = 0; i < a_length; i++) {
        c[i] = arry1[i];
    }

    // Copy elements from arry2 to c
    for (int i = 0; i < b_length; i++) {
        c[a_length + i] = arry2[i];
    }

    // Print elements of c
    for (int i = a_length + b_length ; i >= 0; i--) {
        cout << c[i] << " ";
    }

    return 0;
}
