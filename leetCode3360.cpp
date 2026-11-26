class Solution {
public:
    bool canAliceWin(int n) {
        int take = 10;
        bool aliceTurn = true;
        while (n >= take && take > 0) {
            n -= take;
            take--;
            aliceTurn = !aliceTurn;
        }
        // The player whose turn it is cannot move and loses.
        // If it's Bob's turn, Alice wins.
        return !aliceTurn;
    }
};