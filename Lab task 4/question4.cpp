#include <iostream>
using namespace std;

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

int searchElement(int arr[], int n, int item) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == item) {
            return i;
        }
    }
    return -1;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    const int maxSize = 100;
    int arr[maxSize] = {1, 2, 3, 4, 5};
    int n = 5;

    cout << "Original array: ";
    printArray(arr, n);

    int choice, item;
    cout << "Enter the item to insert: ";
    cin >> item;
    cout << "Choose where to insert the item:\n";
    cout << "1. At the start\n";
    cout << "2. In the middle\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        insertAtStart(arr, n, item, maxSize);
        cout << "After inserting " << item << " at the start: ";
    } else if (choice == 2) {
        insertAtMiddle(arr, n, item, maxSize);
        cout << "After inserting " << item << " in the middle: ";
    } else {
        cout << "Invalid choice!" << endl;
        return 1;
    }
    printArray(arr, n);

    int itemToSearch;
    cout << "Enter the element to search: ";
    cin >> itemToSearch;
    int index = searchElement(arr, n, itemToSearch);
    if (index != -1) {
        cout << "Element " << itemToSearch << " found at index " << index << endl;
    } else {
        cout << "Element " << itemToSearch << " not found in the array." << endl;
    }

    return 0;
}
