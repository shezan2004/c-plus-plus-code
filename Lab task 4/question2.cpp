#include <bits/stdc++.h>
using namespace std;

void countSort(int arr[], int n) {
    int k = arr[0];
    for (int i = 1; i < n; i++) {
        k = max(k, arr[i]);
    }
    
    int* count = new int[k + 1]();  // Initialize count array with zeros
    
    // Display the count array after initialization
    cout << "Initialized count array: ";
    for (int i = 0; i <= k; i++) {
        cout << count[i] << " ";
    }
    cout << endl;
    
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    cout << "Array after counting occurrences: ";
    for (int i = 0; i <= k; i++) {
        cout << count[i] << " ";
    }
    cout << endl;

    for (int i = 1; i <= k; i++) {
        count[i] += count[i - 1];
    }

    cout << "Array after cumulative count: ";
    for (int i = 0; i <= k; i++) {
        cout << count[i] << " ";
    }
    cout << endl;

    int* output = new int[n];
    for (int i = n - 1; i >= 0; i--) {
        output[--count[arr[i]]] = arr[i];
    }

    cout << "Array after sorting: ";
    for (int i = 0; i < n; i++) {
        arr[i] = output[i]; 
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] count;   
    delete[] output;  
}

int main() {
    int arr[] = {1, 3, 2, 3, 4, 1, 6, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    countSort(arr, n);
    
    return 0;
}
