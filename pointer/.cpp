#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "Enter a string: ";
    string inputString;
    getline(cin, inputString);
    int length = inputString.length();
    cout << "Length of string is " << length << "." << endl;

    return 0;
}
