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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<pair<TreeNode*,int>> s ;
        vector<int> ans ;
        if(!root){
            return ans ;
        }

        s.push({root,0});

        while(!s.empty()){
            if((s.top().first -> left) && (s.top().second == 0)){
                s.top().second = 1 ;
                s.push({s.top().first -> left,0});
            }
            else{
                auto node = s.top().first ;
                s.pop() ;
                ans.push_back(node->val);

                if(node->right){
                    s.push({node->right,0});
                }
            }
        }
        return ans ;
    }
};