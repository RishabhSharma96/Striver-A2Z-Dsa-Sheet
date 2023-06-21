//Function to find the lowest common ancestor in a BST.
class Solution{
    public:
    
        Node* solve(Node *root, int p, int q){
            
            if(!root) return root;
            
            if(root->data == p || root->data == q){
                return root ;
            }
            
            if((root->data > p && root->data < q) || (root->data > q && root->data < p)){
                return root;
            }
            
            if(root->data > p && root->data > q){
                return solve(root->left,p,q);
            }
            return solve(root->right,p,q);
            
        }
    
        Node* LCA(Node *root, int p, int q)
        {
            return solve(root,p,q);
        }

};