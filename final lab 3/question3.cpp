#include <iostream>
#include <string>
using namespace std;

string findLCS(const string &word1, const string &word2) {
    int n = word1.length();
    int m = word2.length();
    
    int lcsTable[n + 1][m + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                lcsTable[i][j] = 0;
            } else if (word1[i - 1] == word2[j - 1]) {
                lcsTable[i][j] = lcsTable[i - 1][j - 1] + 1;
            } else {
                lcsTable[i][j] = max(lcsTable[i - 1][j], lcsTable[i][j - 1]);
            }
        }
    }

    
    string lcs;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (word1[i - 1] == word2[j - 1]) {
            lcs = word1[i - 1] + lcs;
            i--;
            j--;
        } else if (lcsTable[i - 1][j] > lcsTable[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    return lcs;
}

int main() {
    string target = "Australia";
    string country1 = "Austria";
    string country2 = "Argentina";

    string lcs1 = findLCS(target, country1);
    string lcs2 = findLCS(target, country2);

    cout << "Target: " << target << endl;
    cout << "Country 1: " << country1 << " | LCS: " << lcs1 << " | Length: " << lcs1.length() << endl;
    cout << "Country 2: " << country2 << " | LCS: " << lcs2 << " | Length: " << lcs2.length() << endl;

    if (lcs1.length() > lcs2.length()) {
        cout << "\n" << country1 << " is more similar to " << target << " than " << country2 << "." << endl;
    } else if (lcs2.length() > lcs1.length()) {
        cout << "\n" << country2 << " is more similar to " << target << " than " << country1 << "." << endl;
    } else {
        cout << "\nBoth " << country1 << " and " << country2 << " are equally similar to " << target << "." << endl;
    }

    return 0;
}
