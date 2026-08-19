class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rowMask; // row -> bitmask of reserved seats among 2..9

        for (auto& rs : reservedSeats) {
            int row = rs[0], seat = rs[1];
            if (seat < 2 || seat > 9) continue; // seats 1 and 10 never block any block
            rowMask[row] |= (1 << (seat - 2));
        }

        long long total = (long long)(n - rowMask.size()) * 2LL;

        const int LEFT  = 0b00001111; // seats 2-5
        const int MID   = 0b00111100; // seats 4-7
        const int RIGHT = 0b11110000; // seats 6-9

        for (auto& [row, mask] : rowMask) {
            if ((mask & LEFT) == 0 && (mask & RIGHT) == 0) {
                total += 2;
            } else if ((mask & LEFT) == 0 || (mask & MID) == 0 || (mask & RIGHT) == 0) {
                total += 1;
            }
        }

        return (int)total;
    }
};