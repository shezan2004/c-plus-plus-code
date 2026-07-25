class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());
        int sz = s.size();
        // The product of the two largest digits will be the maximum
        return (s[sz - 1] - '0') * (s[sz - 2] - '0');
    }
};