class Solution {
public:
    int cnt = 0;
    int result = -1;

    void inorder(TreeNode* root, int k) {
        if (root == nullptr) return;

        inorder(root->left, k);

        cnt++;
        if (cnt == k) {
            result = root->val;
            return;
        }

        inorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return result;
    }
};
