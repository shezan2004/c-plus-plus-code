#include <iostream>
using namespace std;

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int key) {
    int start = 0, end = size - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] > key) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return -1;
}

int main() {
    int size;

    cout << "Enter the number of elements: ";
    cin >> size;
    
    int arr[size];
    
    cout << "Enter " << size << " integers: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int choice;
    cout << "Choose search method:\n";
    cout << "1. Linear Search\n";
    cout << "2. Binary Search (array will be sorted if necessary)\n";
    cout << "Enter choice (1 or 2): ";
    cin >> choice;

    int key;
    cout << "Enter the number you want to search: ";
    cin >> key;

    int result = -1;
    if (choice == 1) {
        result = linearSearch(arr, size, key);
    } else if (choice == 2) {
        insertionSort(arr, size);

        cout << "Sorted array: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        result = binarySearch(arr, size, key);
    } else {
        cout << "Invalid choice!" << endl;
        return 0;
    }

    if (result != -1) {
        cout << "Key " << key << " found at index " << result << endl;
    } else {
        cout << "Key " << key << " not found in the array." << endl;
    }

    return 0;
}
