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

    int solve(TreeNode* root, int &ans){
        if(!root) return 0 ;

        int left = solve(root->left, ans) ;
        if(left<0) left=0 ;
        int right = solve(root->right, ans);
        if(right<0) right=0 ;

        ans = max(ans, left+right+root->val);
        return max(left,right)+root->val;
    }

    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN ;
        int f_call = solve(root,ans);
        return ans ;
    }
};