class Solution {
public:
    int dfs(TreeNode* root, int mx) {
        if (!root) return 0;

        int ans = root->val >= mx;
        mx = max(mx, root->val);

        ans += dfs(root->left, mx);
        ans += dfs(root->right, mx);

        return ans;
    }

    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};