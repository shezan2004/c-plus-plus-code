#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
private:
    int memo[20][20];
    
    int solve(const vector<int>& nums, int i, int j) {
        if (i == j) {
            return nums[i];
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        
        int pickLeft = nums[i] - solve(nums, i + 1, j);
        int pickRight = nums[j] - solve(nums, i, j - 1);
        
        return memo[i][j] = max(pickLeft, pickRight);
    }

public:
    bool predictTheWinner(vector<int>& nums) {
        memset(memo, -1, sizeof(memo));
        return solve(nums, 0, nums.size() - 1) >= 0;
    }
};