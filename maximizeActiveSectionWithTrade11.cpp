#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

class SparseTable {
private:
    int n;
    vector<vector<int>> st;

public:
    SparseTable(const vector<int>& nums) {
        n = nums.size();
        if (n == 0) return;
        int max_log = 32 - __builtin_clz(n);
        st.assign(max_log, vector<int>(n));
        
        for (int j = 0; j < n; ++j) {
            st[0][j] = nums[j];
        }
        
        for (int i = 1; i < max_log; ++i) {
            for (int j = 0; j + (1 << i) <= n; ++j) {
                st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    int query(int l, int r) const {
        if (l > r) return 0;
        int len = r - l + 1;
        int k = 31 - __builtin_clz(len);
        return max(st[k][l], st[k][r - (1 << k) + 1]);
    }
};

struct Group {
    int start;
    int length;
};

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        
        // 1. Prefix sum for counting existing '1's
        vector<int> pref_ones(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pref_ones[i + 1] = pref_ones[i] + (s[i] == '1');
        }

        // 2. Identify all contiguous '0' blocks
        vector<Group> zeroGroups;
        vector<int> zeroGroupIndex(n, -1);
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                if (i > 0 && s[i - 1] == '0') {
                    zeroGroups.back().length++;
                } else {
                    zeroGroups.push_back({i, 1});
                }
                zeroGroupIndex[i] = zeroGroups.size() - 1;
            }
        }

        int numZeroGroups = zeroGroups.size();

        // 3. Precompute sum of adjacent zero groups
        vector<int> adjacentSums;
        if (numZeroGroups > 1) {
            adjacentSums.resize(numZeroGroups - 1);
            for (int i = 0; i < numZeroGroups - 1; ++i) {
                adjacentSums[i] = zeroGroups[i].length + zeroGroups[i + 1].length;
            }
        }

        // 4. Build Sparse Table over adjacent zero group sums
        SparseTable st(adjacentSums);

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];

            int total_ones = pref_ones[r + 1] - pref_ones[l];
            int max_active = total_ones;

            int g_l = zeroGroupIndex[l];
            int g_r = zeroGroupIndex[r];

            // Length of truncated '0' block at left bound
            int left_len = (g_l == -1) ? 0 : (zeroGroups[g_l].start + zeroGroups[g_l].length - l);
            // Length of truncated '0' block at right bound
            int right_len = (g_r == -1) ? 0 : (r - zeroGroups[g_r].start + 1);

            int start_group = (s[l] == '0') ? g_l + 1 : g_l;
            int end_group = (s[r] == '0') ? g_r - 1 : g_r;

            // Option 1: Fully internal adjacent zero group pairs
            if (start_group <= end_group - 1 && numZeroGroups > 1) {
                int st_l = start_group;
                int st_r = end_group - 1;
                if (st_l <= st_r) {
                    max_active = max(max_active, total_ones + st.query(st_l, st_r));
                }
            }

            // Option 2: Merging left truncated zero block with the next internal zero block
            if (s[l] == '0') {
                if (g_l + 1 <= (s[r] == '0' ? g_r - 1 : g_r)) {
                    max_active = max(max_active, total_ones + left_len + zeroGroups[g_l + 1].length);
                }
            }

            // Option 3: Merging right truncated zero block with the previous internal zero block
            if (s[r] == '0') {
                if ((s[l] == '0' ? g_l + 1 : g_l) <= g_r - 1) {
                    max_active = max(max_active, total_ones + right_len + zeroGroups[g_r - 1].length);
                }
            }

            // Option 4: Direct merge between left and right boundary zero blocks
            if (s[l] == '0' && s[r] == '0') {
                if (g_l + 1 == g_r) {
                    max_active = max(max_active, total_ones + left_len + right_len);
                }
            }

            ans.push_back(max_active);
        }

        return ans;
    }
};