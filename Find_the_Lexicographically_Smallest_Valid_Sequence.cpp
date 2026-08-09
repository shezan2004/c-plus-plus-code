#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        
        // last[j] stores the last occurrence index in word1 where word1[i] == word2[j]
        vector<int> last(m, -1);
        int i = n - 1;
        int j = m - 1;
        
        while (i >= 0 && j >= 0) {
            if (word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }
            i--;
        }
        
        vector<int> ans(m);
        bool canSkip = true;
        j = 0;
        
        for (i = 0; i < n; ++i) {
            if (j == m) break;
            
            if (word1[i] == word2[j]) {
                ans[j++] = i;
            } else if (canSkip && (j == m - 1 || i < last[j + 1])) {
                canSkip = false;
                ans[j++] = i;
            }
        }
        
        return j == m ? ans : vector<int>();
    }
};