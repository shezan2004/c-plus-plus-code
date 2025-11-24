#include <iostream>
using namespace std;

void maxHeapify(int arr[], int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[largest] < arr[left]) {
        largest = left;
    }

    if (right < size && arr[largest] < arr[right]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, size, largest);
    }
}


void buildMaxHeap(int arr[], int size) {
    cout << "Building Max Heap..." << endl;
    for (int i = size / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, size, i);
    }
}


void heapSortAscending(int arr[], int n) {
    
    buildMaxHeap(arr, n);

    int size = n;

    
    while (size > 1) {
    
        swap(arr[size - 1], arr[0]);
        size--;
        maxHeapify(arr, size, 0);
    }
}



void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[smallest] > arr[left]) {
        smallest = left;
    }
    if (right < n && arr[smallest] > arr[right]) {
        smallest = right;
    }

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void buildMinHeap(int arr[], int n) {
    cout << "Building Min Heap..." << endl;
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(arr, n, i);
    }
}

void heapSortDescending(int arr[], int n) {
    buildMinHeap(arr, n);

    int size = n;

    while (size > 1) {
        swap(arr[size - 1], arr[0]);
        size--;
        minHeapify(arr, size, 0);
    }
}



void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
    int arr[] = {1, 5, 3, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Enter 1 for ascending order (Max Heap) or 2 for descending order (Min Heap): ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        heapSortAscending(arr, n);
        cout << "Sorted array in ascending order (using Max Heap): ";
    } else if (choice == 2) {
        heapSortDescending(arr, n);
        cout << "Sorted array in descending order (using Min Heap): ";
    } else {
        cout << "Invalid choice!" << endl;
        return 1;
    }

    printArr(arr, n);
    return 0;
}
