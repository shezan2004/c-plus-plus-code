#include <iostream>
using namespace std;

void printHouseNumbers(int n) {
    
    int houseNumbers[n];
    houseNumbers[0] = 0; 
    houseNumbers[1] = 1; 
    for (int i = 2; i < n; i++) {
        houseNumbers[i] = 0;
       
        for (int j = 0; j < i; j++) {
            houseNumbers[i] += houseNumbers[j];
        }
    }
    for (int i = 0; i < n; i++) {
        cout << (i + 1) << "th house number is: " << houseNumbers[i] << endl;
    }
}

int main() {
    int n = 10;
    printHouseNumbers(n);
    
    return 0;
}
