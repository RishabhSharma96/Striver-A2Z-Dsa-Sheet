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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans ;
        if(!root) return ans;

        map<int, map<int,multiset<int>>> mp ; // [vlevel][hlevel][node-<val]
        queue<pair<TreeNode*, pair<int,int>>> q ; // {node,{vlevel,hlevel}}
        q.push({root,{0,0}});

        while(!q.empty()){

            auto node = q.front().first;
            auto vlevel = q.front().second.first ;
            auto hlevel = q.front().second.second ;
            q.pop();
            
            mp[vlevel][hlevel].insert(node->val);

            if(node->left) {
                q.push({node->left,{vlevel-1, hlevel+1}});
            }
            if(node->right) {
                q.push({node->right,{vlevel+1, hlevel+1}});
            }
        }

        for(auto it:mp){
            vector<int> temp ;
            for(auto it2: it.second){
                temp.insert(temp.end(), it2.second.begin(), it2.second.end());
            }
            ans.push_back(temp);
        }

        return ans ;

    }
};