#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int count[3] = {0, 0, 0};
        for (int stone : stones) {
            count[stone % 3]++;
        }
        
        // If the count of remainder 0 stones is even
        if (count[0] % 2 == 0) {
            return min(count[1], count[2]) > 0;
        }
        
        // If the count of remainder 0 stones is odd
        return abs(count[1] - count[2]) > 2;
    }
};