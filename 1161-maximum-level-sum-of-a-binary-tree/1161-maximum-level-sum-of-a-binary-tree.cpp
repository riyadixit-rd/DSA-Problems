class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int level = 1, ans = 1;
        long long maxi = LLONG_MIN;

        while (!q.empty()) {
            int n = q.size();
            long long sum = 0;

            while (n--) {
                TreeNode* node = q.front();
                q.pop();

                sum += node->val;

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            if (sum > maxi) {
                maxi = sum;
                ans = level;
            }

            level++;
        }

        return ans;
    }
};