
#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Enter the number of elements (N): ";
    cin >> N;

    if (N <= 0) {
        cout << "N must be a positive integer." << endl;
        return 0;
    }

    int num[N];
    cout << "Enter " << N << " numbers, one at a time:" <<endl;


    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

cout << "Numbers in reverse order:" <<endl;


    for (int i = N - 1; i >= 0; i--) {
        cout << num[i] << " ";
    }

    cout << endl;

    return 0;
}
