#include <iostream>
using namespace std;

void combineArrays(int arr1[], int n1, int arr2[], int n2, int combined[], int &n) {
    for (int i = 0; i < n1; i++) {
        combined[i] = arr1[i];
    }
    for (int i = 0; i < n2; i++) {
        combined[n1 + i] = arr2[i];
    }
    n = n1 + n2;
}

void insertAtEnd(int arr[], int &n, int item, int maxSize) {
    if (n >= maxSize) {
        cout << "Array is full, cannot insert at the end." << endl;
        return;
    }
    arr[n] = item;
    n++;
}

void findLargestAndSmallest(int arr[], int n, int &largest, int &smallest) {
    largest = arr[0];
    smallest = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }
}

void sortArray(int arr[], int n) {
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

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    const int maxSize = 100;
    int arr1[] = {3, 5, 1, 9, 7};
    int arr2[] = {8, 2, 4, 6, 0};
    int n1 = 5, n2 = 5;

    int combined[maxSize];
    int combinedSize;

    combineArrays(arr1, n1, arr2, n2, combined, combinedSize);
    
    cout << "Combined array: ";
    printArray(combined, combinedSize);

    
    int newItem;
    cout << "Enter the element to insert at the end: ";
    cin >> newItem;

    
    insertAtEnd(combined, combinedSize, newItem, maxSize);
    cout << "After inserting " << newItem << " at the end: ";
    printArray(combined, combinedSize);

   
    int largest, smallest;
    findLargestAndSmallest(combined, combinedSize, largest, smallest);
    cout << "Largest element: " << largest << endl;
    cout << "Smallest element: " << smallest << endl;

    
    sortArray(combined, combinedSize);
    cout << "Sorted array: ";
    printArray(combined, combinedSize);

    return 0;
}
