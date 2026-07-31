class Solution {
public:
    unordered_map<long long, int> mp;

    int dfs(TreeNode* root, long long sum, int target) {
        if (!root) return 0;

        sum += root->val;
        int ans = mp[sum - target];

        mp[sum]++;
        ans += dfs(root->left, sum, target);
        ans += dfs(root->right, sum, target);
        mp[sum]--;

        return ans;
    }

    int pathSum(TreeNode* root, int targetSum) {
        mp[0] = 1;
        return dfs(root, 0, targetSum);
    }
};