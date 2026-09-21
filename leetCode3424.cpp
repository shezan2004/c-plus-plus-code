class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        vector<long long> dp(k, 0);
        
        for (int num : nums) {
            vector<long long> ndp(k, 0);
            int a = num % k;
            ndp[a] += 1;
            for (int r = 0; r < k; r++) {
                if (dp[r] > 0) {
                    int nr = (r * a) % k;
                    ndp[nr] += dp[r];
                }
            }
            dp = ndp;
            for (int r = 0; r < k; r++) {
                result[r] += dp[r];
            }
        }
        
        return result;
    }
};