#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::vector<int> sequentialDigits(int low, int high) {
        std::vector<int> result;
        std::string digits = "123456789";
        
        // Loop through all possible lengths of sequential numbers (from 2 to 9 digits)
        for (int length = 2; length <= 9; ++length) {
            // Slide a window of 'length' over the digits string
            for (int start = 0; start <= 9 - length; ++start) {
                std::string sub = digits.substr(start, length);
                int num = std::stoi(sub);
                
                // If it fits within the range, add it to our results
                if (num >= low && num <= high) {
                    result.push_back(num);
                }
            }
        }
        
        return result;
    }
};