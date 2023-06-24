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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        queue<pair<TreeNode*,int>> q;
        q.push({root,0});

        int ans=INT_MIN;

        while(!q.empty()){
            auto minIndex = q.front().second; 
            int size = q.size() ;
            int first = 0 ; int last = 0 ;

            for(int i=0 ; i<size; i++){
                auto node = q.front().first;
                auto curr_element_index = q.front().second;
                q.pop();

                if(i==0) first = curr_element_index;
                if(i==size-1) last = curr_element_index;

                if(node->left){
                    q.push({node->left,(long long)2*curr_element_index+1});
                }
                if(node->right){
                    q.push({node->right,(long long)2*curr_element_index+2});
                }
            }

            ans = max(ans, last-first+1);
        }

        return ans;
    }
};