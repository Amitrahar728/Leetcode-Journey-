class Solution {
public:
    void dfs(TreeNode* cur, int level, vector<vector<int>>& ans){
        if(!cur) return;
        
        if(ans.size() == level){
            //in level 0, we totally have 1 level
            ans.push_back(vector<int>());
        }
        
        /*
        the only difference is that 
        we build the ans from left to right or
        from right to left
        */
        if(!(level&1)){
            //level is even
            //in current level, we go from left to right
            ans[level].push_back(cur->val);
        }else{
            ans[level].insert(ans[level].begin(), cur->val);
        }
        
        //we still visit the tree from left to right
        dfs(cur->left, level+1, ans);
        dfs(cur->right, level+1, ans);
    };
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        dfs(root, 0, ans);
        
        return ans;
    }
};