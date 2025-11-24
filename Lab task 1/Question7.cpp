#include<bits/stdc++.h>
using namespace std;

int fact(int num) {
    int fact = 1;
    for (int i = num; i > 1; i--) {
        fact = fact * i;
    }
    return fact;
}

int main() {
    int num;
    cout << "Enter Number: ";
    cin >> num;
    cout << "Factorial: " << fact(num) << endl;
    return 0;
}
