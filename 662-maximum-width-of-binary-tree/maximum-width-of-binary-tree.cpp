class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int ans = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        
        while (!q.empty()) {
            int s = q.size();
            unsigned long long min = q.front().second;
            unsigned long long first = 0, last = 0;
            for (int i = 0; i < s; i++) {
                unsigned long long curr = q.front().second - min;
                TreeNode* node = q.front().first;
                q.pop();
                if (i == 0) first = curr;
                if (i == s - 1) last = curr;
                if (node->left) q.push({node->left, curr * 2});
                if (node->right) q.push({node->right, curr * 2 + 1});
            }
            ans = max(ans, static_cast<int>(last - first + 1));
        }
        return ans;
    }
};
