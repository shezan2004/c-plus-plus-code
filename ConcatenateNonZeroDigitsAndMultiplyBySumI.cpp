class Solution {
public:
    long long sumAndMultiply(int n) {
        // Handle the base case where n is 0
        if (n == 0) {
            return 0;
        }

        long long x = 0;
        long long sum = 0;
        long long multiplier = 1;

        // Process digits from right to left
        while (n > 0) {
            int digit = n % 10;
            if (digit != 0) {
                // Add to the sum of digits
                sum += digit;
                // Reconstruct x by placing the digit at its correct positional value
                x += digit * multiplier;
                // Shift the multiplier for the next non-zero digit
                multiplier *= 10;
            }
            n /= 10;
        }

        return x * sum;
    }
};