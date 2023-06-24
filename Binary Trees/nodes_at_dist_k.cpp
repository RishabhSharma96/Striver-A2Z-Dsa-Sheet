/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void getParent(TreeNode* root, unordered_map<TreeNode*,TreeNode*> & parent){

        queue<TreeNode*> q ;
        q.push(root);
        parent[root] = NULL;

        while(!q.empty()){
            auto node = q.front() ;
            q.pop();

            if(node->left){
                q.push(node->left);
                parent[node->left] = node;
            }
            if(node->right){
                q.push(node->right);
                parent[node->right] = node;  
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        getParent(root,parent);

        unordered_map<TreeNode*, bool> visited;
        queue<pair<TreeNode*,int>> q ;
        q.push({target,0});
        visited[target] = true;

        vector<int> ans;

        while(!q.empty()){

            auto node = q.front().first;
            auto curr_dist = q.front().second;

            if(curr_dist == k){
                break;
            }

            q.pop();

            if(node->left && visited[node->left] == false){
                q.push({node->left,curr_dist+1});
                visited[node->left] = true;
            }
            if(node->right && visited[node->right] == false){
                q.push({node->right,curr_dist+1});
                visited[node->right] = true;
            }
            if(parent[node] && visited[parent[node]] == false){
                q.push({parent[node],curr_dist+1});
                visited[parent[node]] = true;
            }
            

        }

        while(!q.empty()){
            ans.push_back(q.front().first->val);
            q.pop();
        }

        return ans;

    }
};
