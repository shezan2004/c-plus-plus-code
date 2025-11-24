#include <iostream>
using namespace std;

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Merge Sort Helper Functions
void merge(int arr[], int s, int e) {
    int mid = (s + e) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int* first = new int[len1];
    int* second = new int[len2];

    int mainIndex = s;
    for (int i = 0; i < len1; i++) {
        first[i] = arr[mainIndex++];
    }
    mainIndex = mid + 1;
    for (int i = 0; i < len2; i++) {
        second[i] = arr[mainIndex++];
    }

    int index1 = 0, index2 = 0;
    mainIndex = s;
    while (index1 < len1 && index2 < len2) {
        if (first[index1] < second[index2]) {
            arr[mainIndex++] = first[index1++];
        } else {
            arr[mainIndex++] = second[index2++];
        }
    }
    while (index1 < len1) arr[mainIndex++] = first[index1++];
    while (index2 < len2) arr[mainIndex++] = second[index2++];

    delete[] first;
    delete[] second;
}

void mergeSort(int arr[], int s, int e) {
    if (s >= e) return;
    int mid = (s + e) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, e);
}

// Insertion Sort
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

// Quick Sort Helper Function
int partition(int arr[], int s, int e) {
    int pivot = arr[s];
    int count = 0;
    for (int i = s + 1; i <= e; i++) {
        if (arr[i] <= pivot) count++;
    }
    int pivotIndex = s + count;
    swap(arr[pivotIndex], arr[s]);

    int i = s, j = e;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i < pivotIndex && j > pivotIndex) swap(arr[i++], arr[j--]);
    }
    return pivotIndex;
}

void quickSort(int arr[], int s, int e) {
    if (s >= e) return;
    int p = partition(arr, s, e);
    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
}

// Counting Sort
void countSort(int arr[], int n) {
    int k = arr[0];
    for (int i = 1; i < n; i++) {
        k = max(k, arr[i]);
    }
    
    int* count = new int[k + 1]();
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    for (int i = 1; i <= k; i++) {
        count[i] += count[i - 1];
    }
    int* output = new int[n];
    for (int i = n - 1; i >= 0; i--) {
        output[--count[arr[i]]] = arr[i];
    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    delete[] count;
    delete[] output;
}

// Print Array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
    int choice;
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Choose a sorting algorithm:" << endl;
    cout << "1. Bubble Sort" << endl;
    cout << "2. Merge Sort" << endl;
    cout << "3. Insertion Sort" << endl;
    cout << "4. Quick Sort" << endl;
    cout << "5. Counting Sort" << endl;
    cin >> choice;

    cout << "Original array: ";
    printArray(arr, n);

    switch (choice) {
        case 1:
            bubbleSort(arr, n);
            break;
        case 2:
            mergeSort(arr, 0, n - 1);
            break;
        case 3:
            insertionSort(arr, n);
            break;
        case 4:
            quickSort(arr, 0, n - 1);
            break;
        case 5:
            countSort(arr, n);
            break;
        default:
            cout << "Invalid choice!" << endl;
            return 1;
    }

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
