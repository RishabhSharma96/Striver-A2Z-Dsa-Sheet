/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.

void solve(Node* root, vector<int> & ans, int level, int & maxLevel){
        if(!root) return ;

        if(level > maxLevel){
            ans.push_back(root->data);
        }

        maxLevel = max(level,maxLevel) ;

        solve(root->left,ans,level+1,maxLevel);
        solve(root->right,ans,level+1,maxLevel);
    }

vector<int> leftView(Node *root)
{
    vector<int> ans ;
    if(!root) return ans ;
    int level=0 ;
    int maxLevel = 0;
    ans.push_back(root->data);
    solve(root,ans,level,maxLevel) ;
    return ans ;
}