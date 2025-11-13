#include <iostream>
using namespace std;


int findMax(int a, int b) {
    return (a > b) ? a : b;
}

double findMax(double a, double b) {
    return (a > b) ? a : b;
}

int main() {

    int num1 = 10;
    int num2 = 20;

    cout << "The maximum of " << num1 << " and " << num2 << " is: " << findMax(num1, num2) <<endl;


    double double1 = 3.14;
    double double2 = 2.71;

   cout << "The maximum of " << double1 << " and " << double2 << " is: " << findMax(double1, double2) <<endl;

    return 0;
}

