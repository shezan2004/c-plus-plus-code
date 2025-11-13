#include <iostream>
using namespace std;
int main() {
    int N;

    cout << "Enter the number of elements: ";
    cin >> N;

    if (N <= 0) {
        cout << "Invalid input. Number of elements should be greater than 0." <<endl;
    }

    int arr[N];

    cout << "Enter " << N << " numbers: ";
    for (int i = 0; i < N; i++) {
      cin >> arr[i];
    }

   cout << "Numbers in reverse order: ";
    for (int i = N - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}
