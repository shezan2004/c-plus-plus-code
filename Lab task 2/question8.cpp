#include <iostream>

using namespace std;

int main() {
    const int size = 10;
    int arr[size] = {3, 5, 2, 3, 8, 5, 2, 9, 1, 3};
    int max = arr[0];
    int min = arr[0];
    int sum = 0;
    int duplicateCount = 0;

    const int maxElement = 10; 
    int frequency[maxElement] = {0};

    for (int i = 0; i < size; i++) {
        sum += arr[i];

        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }

        frequency[arr[i]]++;
    }

    for (int i = 0; i < maxElement; i++) {
        if (frequency[i] > 1) {
            cout << "Element " << i << " appears " << frequency[i] << " times." << endl;
            duplicateCount++;
        }
    }

    double average = sum / (double)size;

    cout << "Max: " << max << endl;
    cout << "Min: " << min << endl;
    cout << "Sum: " << sum << endl;
    cout << "Average: " << average << endl;

    return 0;
}
