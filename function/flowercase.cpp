#include <iostream>
#include <string>

using namespace std;


string makeLowercase(const string& inputString) {
    string result = inputString;
    for (int i = 0; i < result.length(); i++) {
        if (result[i] >= 'A' && result[i] <= 'Z') {
            result[i] = result[i] + 32;
        }
    }
    return result;
}

int main() {

    string defaultString = "Hello World";


    string lowercaseString = makeLowercase(defaultString);


    cout << "String in Lowercase: " << lowercaseString << endl;

    return 0;
}

