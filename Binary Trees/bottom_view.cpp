//Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans ;
        
        if(!root) return ans ;
        
        map<int,int> mp ; // maps level -> rootData
        queue<pair<Node*,int>> q ; // for -> node,level
        q.push({root,0}) ;
        
        while(!q.empty()){
            auto temp = q.front().first;
            auto level = q.front().second ;
            q.pop();
            
            mp[level] = temp->data ;
            
            if(temp->left) {
                q.push({temp->left,level-1});
            }
            if(temp->right) {
                q.push({temp->right,level+1});
            }
        }
        
        
        for(auto it : mp){
            ans.push_back(it.second);
        }
        
        return ans ;
        
    }
};