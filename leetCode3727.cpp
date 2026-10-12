class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        int k = (n + 1) / 2; // Number of positive terms
        
        vector<long long> squares(n);
        for (int i = 0; i < n; ++i) {
            long long val = nums[i];
            squares[i] = val * val;
        }
        
        // Sort squares in descending order
        sort(squares.rbegin(), squares.rend());
        
        long long score = 0;
        for (int i = 0; i < n; ++i) {
            if (i < k) {
                score += squares[i];
            } else {
                score -= squares[i];
            }
        }
        
        return score;
    }
};