#include <iostream>
#include <string>
using namespace std;

int main() {
    string word1, word2;
    cout << "Enter the first word: ";
    cin >> word1;
    cout << "Enter the second word: ";
    cin >> word2;
    
    
    int commonCount = 0;

    
    cout << "Common characters: ";
    for (int i = 0; i < word1.length(); i++) {
        for (int j = 0; j < word2.length(); j++) {
            if (word1[i] == word2[j]) {
                cout << word1[i] << " ";
               
                commonCount++;
                
                word2[j] = '*';  
                break;  
            }
        }
    }

    if (commonCount == 0) {
        cout << "No common elements found." << endl;
    } else {
        cout << "\nNumber of common characters: " << commonCount << endl;
    }

    return 0;
}
