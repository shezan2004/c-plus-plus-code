class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long power(long long a, long long b, long long mod) {
        a %= mod;
        long long result = 1;
        while (b > 0) {
            if (b & 1) result = result * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return result;
    }

    int numberOfSets(int n, int k) {
        // answer = C(n + k - 1, 2*k) mod MOD
        int N = n + k - 1;
        int K = 2 * k;
        if (K > N) return 0;

        // Compute factorials up to N
        vector<long long> fact(N + 1), invFact(N + 1);
        fact[0] = 1;
        for (int i = 1; i <= N; i++) fact[i] = fact[i - 1] * i % MOD;
        invFact[N] = power(fact[N], MOD - 2, MOD);
        for (int i = N; i > 0; i--) invFact[i - 1] = invFact[i] * i % MOD;

        long long res = fact[N] * invFact[K] % MOD * invFact[N - K] % MOD;
        return (int)res;
    }
};