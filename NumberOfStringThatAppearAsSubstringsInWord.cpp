class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        
        for (const string& p : patterns) {
            // Check if the pattern 'p' exists anywhere inside 'word'
            if (word.find(p) != string::npos) {
                count++;
            }
        }
        
        return count;
    }
};