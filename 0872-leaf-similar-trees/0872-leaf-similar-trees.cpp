class Solution {
public:
    void dfs(TreeNode* root, vector<int>& leaves) {
        if (!root) return;

        if (!root->left && !root->right) {
            leaves.push_back(root->val);
            return;
        }

        dfs(root->left, leaves);
        dfs(root->right, leaves);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a, b;

        dfs(root1, a);
        dfs(root2, b);

        return a == b;
    }
};