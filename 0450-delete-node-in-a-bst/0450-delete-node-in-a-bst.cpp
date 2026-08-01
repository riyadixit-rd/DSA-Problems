class Solution {
public:
    TreeNode* findMin(TreeNode* root) {
        while (root->left)
            root = root->left;
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {
            // Node found

            // No left child
            if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            // No right child
            if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Two children
            TreeNode* temp = findMin(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }

        return root;
    }
};