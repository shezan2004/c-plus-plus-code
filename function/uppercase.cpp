#include<iostream>
#include<string>
using namespace std;

string upper(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = s[i] - 32;  // Subtract 32 to convert to uppercase
        }
    }
    return s;
}

int main() {
    string stri = "Hello world";

    cout << upper(stri);

    return 0;
}

