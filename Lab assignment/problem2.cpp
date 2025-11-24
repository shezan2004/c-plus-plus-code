#include <iostream>
using namespace std;

int main() {
    int sizeA, sizeB;
    cout << "Enter array size of A: ";
    cin >> sizeA;
    cout << "Enter array size of B: ";
    cin >> sizeB;

    if (sizeA == sizeB) {
        cout << "Array sizes should be different!" << endl;
        return 1;
    }

    int A[sizeA], B[sizeB];
    cout << "Enter A array elements: ";
    for (int i = 0; i < sizeA; i++) {
        cin >> A[i];
    }
    cout << "Enter B array elements: ";
    for (int i = 0; i < sizeB; i++) {
        cin >> B[i];
    }

    int common[sizeA + sizeB];
    int nonCommon[sizeA + sizeB];
    int commonIndex = 0, nonCommonIndex = 0;

    // Find common elements
    for (int i = 0; i < sizeA; i++) {
        bool foundInB = false;
        for (int j = 0; j < sizeB; j++) {
            if (A[i] == B[j]) {
                foundInB = true;
                break;
            }
        }
        if (foundInB) {
            common[commonIndex++] = A[i];
        } else {
            nonCommon[nonCommonIndex++] = A[i];
        }
    }

    // Find non-common elements in B
    for (int i = 0; i < sizeB; i++) {
        bool foundInA = false;
        for (int j = 0; j < sizeA; j++) {
            if (B[i] == A[j]) {
                foundInA = true;
                break;
            }
        }
        if (!foundInA) {
            nonCommon[nonCommonIndex++] = B[i];
        }
    }

    cout << "Common elements: ";
    for (int i = 0; i < commonIndex; i++) {
        cout << common[i] << " ";
    }
    cout << endl;

    cout << "Non-common elements: ";
    for (int i = 0; i < nonCommonIndex; i++) {
        cout << nonCommon[i] << " ";
    }
    cout << endl;

    if (commonIndex > nonCommonIndex) {
        cout << "Number of common elements is greater which is " << commonIndex << "." << endl;
    } else if (commonIndex < nonCommonIndex) {
        cout << "Number of non-common elements is greater which is " << nonCommonIndex << "." << endl;
    } else {
        cout << "Number of common and non-common elements are equal which is " << commonIndex << "." << endl;
    }

    return 0;
}
