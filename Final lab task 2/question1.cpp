#include <iostream>
#include <string>
using namespace std;

string findLCS(const string &word1, const string &word2) {
    int n = word1.length();
    int m = word2.length();
    
    int lcsTable[n + 1][m + 1];
    int pathMatrix[n + 1][m + 1];  

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                lcsTable[i][j] = 0;
                pathMatrix[i][j] = -1;  // No move
            } else if (word1[i - 1] == word2[j - 1]) {
                lcsTable[i][j] = lcsTable[i - 1][j - 1] + 1;
                pathMatrix[i][j] = 0;  // Diagonal move (match)
            } else {
                if (lcsTable[i - 1][j] > lcsTable[i][j - 1]) {
                    lcsTable[i][j] = lcsTable[i - 1][j];
                    pathMatrix[i][j] = 1;  // Up move
                } else {
                    lcsTable[i][j] = lcsTable[i][j - 1];
                    pathMatrix[i][j] = 2;  // Left move
                }
            }
        }
    }

    // Print the LCS Table
    cout << "\nLCS Table:\n";
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cout << lcsTable[i][j] << " ";
        }
        cout << endl;
    }

    // Print the Path Matrix with 'D', 'U', and 'L'
    cout << "\nPath Matrix (D: Diagonal, U: Up, L: Left):\n";
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (pathMatrix[i][j] == 0)
                cout << "D ";  // Diagonal
            else if (pathMatrix[i][j] == 1)
                cout << "U ";  // Up
            else if (pathMatrix[i][j] == 2)
                cout << "L ";  // Left
            else
                cout << "- ";  // No move
        }
        cout << endl;
    }

    // Reconstruct LCS and track path directions
    string lcs;
    int i = n, j = m;
    cout << "\nReverse Path Traversal:\n";
    while (i > 0 && j > 0) {
        cout << "(" << i << ", " << j << ") ";
        if (pathMatrix[i][j] == 0) {
            cout << "Match: " << word1[i - 1] << endl;
            lcs = word1[i - 1] + lcs;
            i--;
            j--;
        } else if (pathMatrix[i][j] == 1) {
            cout << "Move Up\n";
            i--;
        } else {
            cout << "Move Left\n";
            j--;
        }
    }

    return lcs;
}

int main() {
    string word1, word2;

    cout << "Enter the first word: ";
    cin >> word1;
    cout << "Enter the second word: ";
    cin >> word2;

    string lcs = findLCS(word1, word2);

    cout << "\nSimilarity (common characters): " << lcs << endl;
    cout << "Length of similarity: " << lcs.length() << endl;

    return 0;
}
