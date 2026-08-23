class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int leftSum = 0, rightSum = 0;
        int leftQ = 0, rightQ = 0;

        for (int i = 0; i < n / 2; ++i) {
            if (num[i] == '?') ++leftQ;
            else leftSum += num[i] - '0';
        }

        for (int i = n / 2; i < n; ++i) {
            if (num[i] == '?') ++rightQ;
            else rightSum += num[i] - '0';
        }

        // If total count of '?' is odd, Alice always wins because Bob cannot balance the final odd '?'
        if ((leftQ + rightQ) % 2 != 0) {
            return true;
        }

        // Otherwise, Bob wins if and only if the sum difference can be exactly offset 
        // by the remaining question mark pairs (each pair can scale up to 9).
        return (rightSum - leftSum) * 2 != (leftQ - rightQ) * 9;
    }
};