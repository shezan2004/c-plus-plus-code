#include<iostream>
using namespace std;

int main() {
    int size1;
    cout << "Enter the Size of array (Must be more than five): ";
    cin >> size1;
    
    if (size1 < 5) {
        cout << "Size must be more than 5 .";
        return 0;
    }
    
    int arr[size1];
    cout << "Enter " << size1 << " integer numbers for array: " << endl;
    for (int i = 0; i < size1; i++) {
        cin >> arr[i];
    }
    
    int flag =0;
    int newSize = size1;
    
    
    for (int i = 0; i < newSize; i++) {
        for (int j = i + 1; j < newSize; j++) {
            if (arr[i] == arr[j]) {
                flag = 1;
                
                for (int k = j; k < newSize - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                newSize--; 
                j--; 
            }
        }
    }
    
    if (flag==0) {
        cout << "Array already unique!";
    } else {
        cout << "Array after removing duplicates: ";
        for (int i = 0; i < newSize; i++) {
            cout << arr[i] << " ";
        }
    }
    
    return 0;
}
