/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode * solve(TreeNode* root, int val){

        if(root == NULL){
            return nullptr ;
        }

        if(root -> val == val){
            return root ;
        }
        else if(root->val < val){
            return solve(root->right,val);
        }
        return solve(root->left,val);
        
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        return solve(root,val);
    }
};