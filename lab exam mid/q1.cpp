#include <iostream>
using namespace std;

void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2, int merged[]) {
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

    while (i < size1) {
        merged[k++] = arr1[i++];
    }

    while (j < size2) {
        merged[k++] = arr2[j++];
    }
}

int main() {
    int packet1[] = {5, 15, 25, 35};
    int packet2[] = {10, 20, 30, 40, 50};

    int size1 = sizeof(packet1) / sizeof(packet1[0]);
    int size2 = sizeof(packet2) / sizeof(packet2[0]);

    int mergedSize = size1 + size2;
    int merged[mergedSize];

    cout << "Packet 1: ";
    for (int i = 0; i < size1; i++) {
        cout << packet1[i] << " ";
    }
    cout << endl;

    cout << "Packet 2: ";
    for (int i = 0; i < size2; i++) {
        cout << packet2[i] << " ";
    }
    cout << endl;

    mergeSortedArrays(packet1, size1, packet2, size2, merged);

    cout << "After merging two packets by sorted shelf prices: ";
    for (int i = 0; i < mergedSize; i++) {
        cout << merged[i] << " ";
    }
    cout << endl;

    return 0;
}
