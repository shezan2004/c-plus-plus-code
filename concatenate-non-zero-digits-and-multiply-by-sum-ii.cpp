#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m = s.length();
        long long MOD = 1e9 + 7;
        
        // Arrays to store prefix configurations
        vector<long long> pref_sum(m + 1, 0);
        vector<long long> pref_x(m + 1, 0);
        vector<int> cnt_nonzero(m + 1, 0);
        
        // Precompute powers of 10 modulo 10^9 + 7
        vector<long long> pow10(m + 1, 1);
        for (int i = 1; i <= m; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }
        
        // Build prefix arrays
        for (int i = 0; i < m; i++) {
            int digit = s[i] - '0';
            
            pref_sum[i + 1] = pref_sum[i] + digit;
            
            if (digit != 0) {
                pref_x[i + 1] = (pref_x[i] * 10 + digit) % MOD;
                cnt_nonzero[i + 1] = cnt_nonzero[i] + 1;
            } else {
                pref_x[i + 1] = pref_x[i];
                cnt_nonzero[i + 1] = cnt_nonzero[i];
            }
        }
        
        vector<int> answer;
        answer.reserve(queries.size());
        
        // Process each query in O(1)
        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];
            
            // 1. Calculate sum of digits
            long long current_sum = pref_sum[r + 1] - pref_sum[l];
            
            // 2. Calculate x modulo 10^9 + 7
            int len = cnt_nonzero[r + 1] - cnt_nonzero[l];
            long long x = (pref_x[r + 1] - (pref_x[l] * pow10[len]) % MOD + MOD) % MOD;
            
            // 3. Calculate final query answer
            long long res = (x * (current_sum % MOD)) % MOD;
            answer.push_back(res);
        }
        
        return answer;
    }
};