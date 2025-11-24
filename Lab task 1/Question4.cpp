#include<bits/stdc++.h>
using namespace std;
void findEvenNumbers(int arr[], int size, int evenNumbers[], int& evenSum, int& evenCount) {
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            evenNumbers[evenCount++] = arr[i]; 
            evenSum += arr[i];                  
        }
    }
}
void findOddNumbers(int arr[], int size, int oddNumbers[], int& oddSum, int& oddCount) {
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 != 0) {
            oddNumbers[oddCount++] = arr[i]; 
            oddSum += arr[i];                 
        }
    }
}

int main() {
    int size;
    cout << "Enter the size of the array (positive integer): ";
    cin >> size;
    while (size <= 0) {
        cout << "Please enter a positive integer for the size of the array: ";
        cin >> size;
    }

    int arr[size];           
    int evenNumbers[size];  
    int oddNumbers[size];    
    int evenSum = 0, oddSum = 0;
    int evenCount = 0, oddCount = 0;
    cout << "Enter " << size << " integers (space-separated): ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

   
    findEvenNumbers(arr, size, evenNumbers, evenSum, evenCount);
    findOddNumbers(arr, size, oddNumbers, oddSum, oddCount);
    cout << "Even numbers: ";
    for (int i = 0; i < evenCount; i++) {
        cout << evenNumbers[i] << " ";
    }
    cout << endl;
    cout << "Odd numbers: ";
    for (int i = 0; i < oddCount; i++) {
        cout << oddNumbers[i] << " ";
    }
    cout << endl;
    cout << "Sum of even numbers: " << evenSum << endl;
    cout << "Sum of odd numbers: " << oddSum << endl;

    return 0;
}
