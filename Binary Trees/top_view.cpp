/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans ;
        
        if(!root) return ans ;
        
        map<int,int> mp ; // maps level -> rootData
        queue<pair<Node*,int>> q ; // for -> node,level
        q.push({root,0}) ;
        
        while(!q.empty()){
            auto temp = q.front().first;
            auto level = q.front().second ;
            q.pop();
            
            mp.insert({level , temp->data}) ;
            
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