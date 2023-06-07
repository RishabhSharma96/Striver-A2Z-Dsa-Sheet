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

    void solve(TreeNode* root, vector<int> & ans, int level, int & maxLevel){
        if(!root) return ;

        if(level > maxLevel){
            ans.push_back(root->val);
        }

        maxLevel = max(level,maxLevel) ;

        solve(root->right,ans,level+1,maxLevel);
        solve(root->left,ans,level+1,maxLevel);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans ;
        if(!root) return ans ;
        int level=0 ;
        int maxLevel = 0;
        ans.push_back(root->val);
        solve(root,ans,level,maxLevel) ;
        return ans ;
    }
};