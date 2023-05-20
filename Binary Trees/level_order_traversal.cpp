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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        vector<vector<int>> ans ;

        if(!root){
            return ans ;
        }

        vector<int> levelVector ;

        q.push({root,0});

        while(!q.empty()){
            auto node = q.front().first ;
            int level = q.front().second;
            q.pop();

            levelVector.push_back(node->val);

            if(node->left){
                q.push({node->left,level+1});
            }
            if(node->right){
                q.push({node->right,level+1});
            }

            if((q.front().second == level+1) || q.empty()){
                ans.push_back(levelVector);
                levelVector.clear() ;
            }

        }

        return ans;
    }
};