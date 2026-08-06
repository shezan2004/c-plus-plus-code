class Solution {
public:
    int smallestNumber(int n, int t) {
        for (int i = n; ; ++i) {
            int product = 1;
            int temp = i;
            
            // Calculate the product of the digits
            while (temp > 0) {
                product *= (temp % 10);
                temp /= 10;
            }
            
            // Check if the product is divisible by t
            if (product % t == 0) {
                return i;
            }
        }
    }
};