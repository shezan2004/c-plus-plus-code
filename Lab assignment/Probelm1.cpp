#include <iostream>

using namespace std;

int main() {
    int size;
    cout << "Enter array size: ";
    cin >> size;

    int arr[size];
    cout << "Enter array numbers: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int sumOdd = 0, sumEven = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            sumEven += arr[i];
        } 
        else {
            sumOdd += arr[i];
        }
    }

    cout << "Summation of odd elements: " << sumOdd << endl;
    cout << "Summation of even elements: " << sumEven << endl;

    if (sumEven > sumOdd) {
        cout << "Summation of even elements is greater." << endl;
    } else if (sumOdd > sumEven) {
        cout << "Summation of odd elements is greater." << endl;
    } else {
        cout << "Summation of odd and even elements are equal." << endl;
    }

    return 0;
}
