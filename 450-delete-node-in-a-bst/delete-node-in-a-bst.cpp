class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* ptr = root;
        if(root == NULL) return root;
        if(root->val < key){
            root->right = deleteNode(root->right,key);
        }
        else if (root->val > key){
            root-> left =  deleteNode(root->left,key);
        }
        else{
            if(root->left == NULL){
                ptr = root;
                root = root->right;
                delete ptr;
            }
            else if(root->right == NULL){
                ptr = root;
                root = root->left;
                delete ptr;
            }
            else{
                ptr = root->left;
                while(ptr->right != NULL){
                    ptr = ptr->right;
                }
                root->val = ptr->val;
                root -> left = deleteNode(root->left,ptr->val);
            }
        }
        return root;
    }
};