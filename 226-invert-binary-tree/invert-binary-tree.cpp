/**
 * Definition for a binary tree node. and Basic structure of a tree
 * struct TreeNode {
 *     int val; // defining val 
 *     TreeNode *left; // defining left pointer 
 *     TreeNode *right;  // defining right pointer 
// defining three types of function based upon how much parameters are passed in it 


 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}  // if no parameter is there then only value is assigned by default with zero (0) and other as null
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} // if val is defined as x then val got defined 
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} // if everything is defined 
 * };
 */


//  Wanna give a Complete breif of binary trees for revision:
// ->heirarichal data structure having nodes and each node having left and right pointer pointing to new nodes having atmost 2 childrens . 
// root node, children node (have both child and parent node) , leaf node 
//  subtree , anscestor (nodes before particular this node ) , 
//  either have 0 or 2 nodes -> full binary tree
//  complete -> All levels are complete except the last one (last one if having less nodes should have direction of nodes from left to right  )
// perfect binary tree : All leaf nodes should be at the same level
// balanced binary tree : height of tree at maximum of logn , where n is the number of nodes log(8) = 3  then height should be 3 at max .
// Degenerate / skewed tree : singly linked list type structure of trees .



// Traversals:  BFS and DFS 
// DFS : Explore deepest nodes first then backtrackes and explores again the most recent unexplored node and till all nodes are not visited 
// DFS use recursion & stack to traverse deeper and keeping record 

// Three types :
// Preorder : root->left->right
// void preorder(Node){                                     // T.C. = O(N) , S.C. = (height of tree)
//     if(Node == NULL){
//         return ;
//     }
//     cout<<Node->val<<endl;
//     preorder(Node->left);
//     preorder(Node->right); // Recursive calls are there 
// }

// Postorder : left->right->root

// void inorder(Node){                                     // T.C. = O(N) , S.C. = (height of tree)
//     if(Node == NULL){
//         return ;
//     }
//     preorder(Node->left);
//     cout<<Node->val<<endl;
//     preorder(Node->right); // Recursive calls are there 
// }
// Inorder : left->root->right
//    void preorder(Node){                                     // T.C. = O(N) , S.C. = (height of tree)
//     if(Node == NULL){
//         return ;
//     }
//     preorder(Node->left);
//     preorder(Node->right); // Recursive calls are there 
//     cout<<Node->val<<endl;
// }



// Now lets look up for iterative approach of traversal for Binary Tree 
// using stack (iterative method):
// steps :
// 1.) push root in stack 
// once you remove top of stack push stack right first and then push stack left inside the stack and add popped element in traversal line wise 

// vector<int> preorder(TreeNode *root){
//     vector<int> pre;
//     if(root == NULL) return pre;
//     stack<TreeNode*> st;
//     st.push(root);
//     while(!st.empty()){
//         root= st.top();
//         st.pop();
//         pre.push_back(root->val);
//         if(root->right !=NULL){
//             st.push(root->right);
//         }
//         if(root->left != NULL){
//             st.push(root->left);
//         }
//     }
//     return pre;
// }


// BFS: 
// Breadth first search : In this type of search we transverse all nodes of current level first in left to right manner and then proceed to next level and same process is repeated till last level .
// Level order traversal utilises a queue data structure to maintain the nodes at each level, ensuring that nodes at higher levels are visited before moving to lower levels.


// T.C. = O(N)
// S.C. = O(N)

// vector<vector<int>> levelorder(TreeNode* root){
//     vector<vector<int>> ans;
//     if(root == NULL) return ans;
//     queue<TreeNode*> q;
//     q.push(root);
//     while(!q.empty()){
//         int size = q.size();
//         vector<int> level;
//         for(int i =0; i<size; i++){
//             TreeNode* node = q.front();
//             q.pop();
//             if(node->left != NULL) q.push(node->left);
//             if(node->right != NULL ) q.push(node->right);
//             level.push_back(node->val);
//         }
//         ans.push_back(level);
//     }
//     return ans;
// }








class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)
            return NULL ;
    
        invertTree(root->left);
        invertTree(root->right);
  
	    swap(root->left, root->right);
        return root;
    }
};