#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        // Count the frequency of each digit in the input array
        unordered_map<int, int> count;
        for (int d : digits) {
            count[d]++;
        }
        
        int validCount = 0;
        
        // Iterate through all 3-digit even numbers
        for (int num = 100; num < 1000; num += 2) {
            int hundreds = num / 100;
            int tens = (num / 10) % 10;
            int units = num % 10;
            
            // Count frequency of digits for the current 3-digit number
            unordered_map<int, int> numCount;
            numCount[hundreds]++;
            numCount[tens]++;
            numCount[units]++;
            
            // Check if the input digits have enough copies for this number
            bool possible = true;
            for (auto& pair : numCount) {
                int digit = pair.first;
                int freq = pair.second;
                if (count[digit] < freq) {
                    possible = false;
                    break;
                }
            }
            
            if (possible) {
                validCount++;
            }
        }
        
        return validCount;
    }
};