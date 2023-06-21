class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    
    bool solve(Node* root ,Node* low ,Node* high){
        if(root == NULL) return true;
        
        if((low && root->data <= low->data) || (high && root->data >= high->data)){
            return false;
        }
        
        return (solve(root->left,low,root) && solve(root->right,root,high));
    }
    
    bool isBST(Node* root) 
    {
        return solve(root,NULL,NULL);
    }
};
