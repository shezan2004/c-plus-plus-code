class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void dfs(vector<int>& candidates, int target, int idx) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        if (target < 0 || idx >= candidates.size()) {
            return;
        }

        temp.push_back(candidates[idx]);
        dfs(candidates, target - candidates[idx], idx); // reuse same number
        temp.pop_back();

        dfs(candidates, target, idx + 1); // move to next number
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, target, 0);
        return ans;
    }
};