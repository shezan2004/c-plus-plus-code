class Solution {
public:
    bool checkDivisibility(int n) {
        int temp = n;
        int digitSum = 0;
        int digitProduct = 1;
        
        while (temp > 0) {
            int digit = temp % 10;
            digitSum += digit;
            digitProduct *= digit;
            temp /= 10;
        }
        
        int totalSum = digitSum + digitProduct;
        
        // Ensure totalSum is not zero to avoid division by zero (though for n >= 1, product of digits > 0 if no digit is 0, but sum/product logic depends on constraints)
        if (totalSum == 0) {
            return false;
        }
        
        return n % totalSum == 0;
    }
};