class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<array<int, 3>> v(n);
        for (int i = 0; i < n; i++) {
            int x = nums[i], s = 0;
            while (x) { s += x % 10; x /= 10; }
            v[i] = {s, nums[i], i};
        }
        sort(v.begin(), v.end());

        vector<bool> vis(n, false);
        int cycles = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            cycles++;
            int j = i;
            while (!vis[j]) {
                vis[j] = true;
                j = v[j][2];
            }
        }
        return n - cycles;
    }
};