class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long even = 1, odd = 0, ans = 0;
        int parity = 0;

        for (int x : arr) {
            parity ^= (x & 1);
            if (parity) {
                ans += even;   // odd prefix pairs with earlier even prefixes
                odd++;
            } else {
                ans += odd;    // even prefix pairs with earlier odd prefixes
                even++;
            }
            ans %= MOD;
        }
        return (int)ans;
    }
};