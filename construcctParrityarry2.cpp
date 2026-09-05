class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min_odd = INT_MAX;
        for (int x : nums1) {
            if (x % 2 != 0) {
                min_odd = min(min_odd, x);
            }
        }
        
        // If there are no odd numbers, all elements are already even.
        if (min_odd == INT_MAX) {
            return true;
        }
        
        // If there are odd numbers, we can never make all elements even 
        // (because the minimum odd number can never become even). 
        // Therefore, we must make all elements odd. 
        // Every even number must be strictly greater than min_odd so we can subtract min_odd from it.
        for (int x : nums1) {
            if (x % 2 == 0) {
                if (x <= min_odd) {
                    return false;
                }
            }
        }
        
        return true;
    }
};