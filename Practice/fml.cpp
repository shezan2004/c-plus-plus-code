#include <iostream>
using namespace std;

// Function to insert an element at the start of the array
void insertAtStart(int arr[], int &n, int item, int maxSize) {
    if (n >= maxSize) {
        cout << "Array is full, cannot insert at the start." << endl;
        return;
    }
    for (int i = n; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = item;
    n++;
}

// Function to insert an element at the middle of the array
void insertAtMiddle(int arr[], int &n, int item, int maxSize) {
    if (n >= maxSize) {
        cout << "Array is full, cannot insert in the middle." << endl;
        return;
    }
    int middle = n / 2;
    for (int i = n; i > middle; i--) {
        arr[i] = arr[i - 1];
    }
    arr[middle] = item;
    n++;
}

// Function to search for an element in the array
int searchElement(int arr[], int n, int item) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == item) {
            return i;
        }
    }
    return -1; // Return -1 if the element is not found
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    const int maxSize = 100; // Maximum size of the array
    int arr[maxSize] = {1, 2, 3, 4, 5}; // Initial array
    int n = 5; // Current number of elements in the array

    cout << "Original array: ";
    printArray(arr, n);

    int itemToInsertStart = 10;
    insertAtStart(arr, n, itemToInsertStart, maxSize);
    cout << "After inserting " << itemToInsertStart << " at the start: ";
    printArray(arr, n);

    int itemToInsertMiddle = 20;
    insertAtMiddle(arr, n, itemToInsertMiddle, maxSize);
    cout << "After inserting " << itemToInsertMiddle << " in the middle: ";
    printArray(arr, n);

    int itemToSearch = 3;
    int index = searchElement(arr, n, itemToSearch);
    if (index != -1) {
        cout << "Element " << itemToSearch << " found at index " << index << endl;
    } else {
        cout << "Element " << itemToSearch << " not found in the array." << endl;
    }

    return 0;
}
