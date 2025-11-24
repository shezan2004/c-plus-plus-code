#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter array numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Modified Bubble sort in decreasing order
    for (int i = 0; i < n - 1; i++) {
        bool swap = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swap = true;
            }
        }
        if (swap == false) {
            break;
        }
    }
    
    cout << "Sorted array in decreasing order: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    int num;
    cout << "Enter a number to search for: ";
    cin >> num;
    
    int comparisons = 0;
    int first = 0;
    int last = n - 1;
    int middle;
    int position = -1;
    
    // Binary search
    while (first <= last) {
        comparisons++;
        middle = (first + last) / 2;

        if (arr[middle] == num) {
            position = middle;
            break;
        } else if (arr[middle] < num) {
            first = middle + 1;
        } else {
            last = middle - 1;
        }
    }

    if (position == -1) {
        cout << num << " is not found in array." << endl;
    } else {
        cout << num << " is found at index no " << position << "." << endl;
    }
    cout << "Number of comparisons to find " << num << " is: " << comparisons << endl;
    
    return 0;
}
