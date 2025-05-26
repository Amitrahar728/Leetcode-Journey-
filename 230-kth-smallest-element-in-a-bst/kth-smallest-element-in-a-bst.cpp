class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* curr = root;
        int count = 0;
        int result = -1;

        while (curr != nullptr) {
            if (curr->left == nullptr) {
                count++;
                if (count == k) result = curr->val;
                curr = curr->right;
            } else {
                TreeNode* pred = curr->left;
                while (pred->right != nullptr && pred->right != curr) {
                    pred = pred->right;
                }

                if (pred->right == nullptr) {
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    pred->right = nullptr;
                    count++;
                    if (count == k) result = curr->val;
                    curr = curr->right;
                }
            }
        }

        return result;
    }
};
