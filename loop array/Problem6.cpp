#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "How many characters you want to take: ";
    cin >> n;
char a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Vowels in the input: ";
    for (int i = 0; i < n; i++) {
        switch (a[i]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                cout << a[i]<< " ";
                break;
        }
    }

    return 0;
}
