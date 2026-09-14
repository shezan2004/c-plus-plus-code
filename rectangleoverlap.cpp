class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // Check if rec1 is to the left of rec2, to the right of rec2,
        // below rec2, or above rec2. If any of these conditions hold true,
        // there is no overlap.
        return !(rec1[2] <= rec2[0] || // rec1 is to the left of rec2
                 rec1[0] >= rec2[2] || // rec1 is to the right of rec2
                 rec1[3] <= rec2[1] || // rec1 is below rec2
                 rec1[1] >= rec2[3]);   // rec1 is above rec2
    }
};