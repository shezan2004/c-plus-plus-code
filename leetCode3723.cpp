class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if ((long long)sum > 9LL * num) return "";
        string res(num, '0');
        int i = 0;
        while (sum >= 9) {
            res[i++] = '9';
            sum -= 9;
        }
        if (sum > 0) res[i] = '0' + sum;
        return res;
    }
};