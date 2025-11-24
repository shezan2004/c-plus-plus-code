#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    int swapCount = 0;

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        // Find the index of the minimum element in the remaining unsorted part
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
            swapCount++;  // Increment swap count
        }
    }

    cout << "Count swap: " << swapCount << endl;
}

int main() {
   // int swapCount = 0;
    vector<int> arr = {5,3,7,0,3};
    selectionSort(arr);
  //  cout << "Number of swaps: " << swapCount << endl;

    return 0;
}
