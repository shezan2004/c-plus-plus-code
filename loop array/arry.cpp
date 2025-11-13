#include <iostream>
using namespace std;

int main() {
    int number;
    cout << "Input any number: ";
    cin >> number;


    int digitFrequency[10] = {0};


    while (number > 0) {
        int digit = number % 10;
        digitFrequency[digit]++;
        number /= 10;
    }


    for (int i = 0; i < 10; i++) {
        cout << "The frequency of " << i << " = " << digitFrequency[i] << endl;
    }

    return 0;
}
