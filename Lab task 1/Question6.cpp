#include <iostream>
using namespace std;

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int sum = 0;
    int count = 0;

    for (int i = 2; i <= 100; i++) {
        if (isPrime(i)) {
            sum += i;
            count++;
        }
    }

    float average;
    if (count > 0) {
        average = (sum * 1.0) / count;
    } else {
        average = 0;
    }

    cout << "Sum of prime numbers between 1 and 100: " << sum << endl;
    cout << "Average of prime numbers between 1 and 100: " << average << endl;

    return 0;
}
