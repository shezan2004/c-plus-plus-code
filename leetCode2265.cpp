class Solution {
public:
    int result = 0;

    pair<int,int> dfs(TreeNode* node) {
        if (!node) return {0, 0};
        
        auto [leftSum, leftCount] = dfs(node->left);
        auto [rightSum, rightCount] = dfs(node->right);
        
        int sum = leftSum + rightSum + node->val;
        int count = leftCount + rightCount + 1;
        
        if (sum / count == node->val) {
            result++;
        }
        
        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return result;
    }
};