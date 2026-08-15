#include <vector>

using namespace std;

class Solution {
private:
    const int MOD = 1e9 + 7;

    // Helper function to multiply two matrices
    vector<vector<long long>> multiply(const vector<vector<long long>>& A, const vector<vector<long long>>& B, int size) {
        vector<vector<long long>> C(size, vector<long long>(size, 0));
        for (int i = 0; i < size; ++i) {
            for (int k = 0; k < size; ++k) {
                if (A[i][k] == 0) continue;
                for (int j = 0; j < size; ++j) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    // Helper function for matrix exponentiation
    vector<vector<long long>> power(vector<vector<long long>> A, long long p, int size) {
        vector<vector<long long>> res(size, vector<long long>(size, 0));
        for (int i = 0; i < size; ++i) res[i][i] = 1; // Identity matrix
        
        while (p > 0) {
            if (p & 1) res = multiply(res, A, size);
            A = multiply(A, A, size);
            p >>= 1;
        }
        return res;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        int M = r - l + 1;
        int size = 2 * M;

        // Base cases for length n = 2
        // State encoding: 
        // dp[j][0] (decreasing to j) maps to index j
        // dp[j][1] (increasing to j) maps to index M + j
        vector<long long> base(size, 0);
        for (int j = 0; j < M; ++j) {
            base[j] = M - 1 - j;     // Count of elements > j (can transition downwards to j)
            base[M + j] = j;         // Count of elements < j (can transition upwards to j)
        }

        if (n == 2) {
            long long ans = 0;
            for (int i = 0; i < size; ++i) ans = (ans + base[i]) % MOD;
            return ans;
        }

        // Construct transition matrix T
        vector<vector<long long>> T(size, vector<long long>(size, 0));
        for (int j = 0; j < M; ++j) {
            // From dp[j][0] (last step was decreasing), next step must be increasing (k > j)
            // It contributes to dp[k][1] (which is at index M + k)
            for (int k = j + 1; k < M; ++k) {
                T[M + k][j] = 1;
            }
            // From dp[j][1] (last step was increasing), next step must be decreasing (k < j)
            // It contributes to dp[k][0] (which is at index k)
            for (int k = 0; k < j; ++k) {
                T[k][M + j] = 1;
            }
        }

        // Raise T to the power of (n - 2)
        vector<vector<long long>> T_pow = power(T, n - 2, size);

        // Compute final configurations
        long long total_arrays = 0;
        for (int i = 0; i < size; ++i) {
            long long current_state_ways = 0;
            for (int j = 0; j < size; ++j) {
                current_state_ways = (current_state_ways + T_pow[i][j] * base[j]) % MOD;
            }
            total_arrays = (total_arrays + current_state_ways) % MOD;
        }

        return total_arrays;
    }
};