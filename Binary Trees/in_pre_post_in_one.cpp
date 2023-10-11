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
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> pre;
        vector<int> in;
        vector<int> post;

        if(!root) return pre ; 

        stack<pair<TreeNode*,int>> q; // for {node, num_choice_for_traversal}
        q.push({root,1});

        while(!q.empty()){
            auto node = q.top().first;
            auto num = q.top().second;

            q.pop();

            if(num == 1){
                pre.push_back(node->val);
                q.push({node,num+1});
                if(node->left){
                    q.push({node->left,1});
                }
            }
            else if(num == 2){
                in.push_back(node->val);
                q.push({node,num+1});
                if(node->right){
                    q.push({node->right,1});
                }
            }
            else{
                post.push_back(node->val);
            }
        }

        return pre;
    }
};