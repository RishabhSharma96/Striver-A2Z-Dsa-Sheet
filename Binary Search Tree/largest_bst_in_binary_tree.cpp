/* Tree node structure  used in the program
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    
    pair<int,pair<int,int>> solve(Node * root){
        if(!root){
            return {0,{INT_MAX,INT_MIN}}; // for -> {size,{minNode,maxNode}}
        }
        
        auto left = solve(root->left);
        auto right = solve(root->right);
        
        if(left.second.second < root->data && root->data < right.second.first){
            return {1+left.first+right.first,{min(left.second.first,root->data),max(root->data, right.second.second)}} ;
        }
        else{
            return {max(left.first,right.first),{INT_MIN,INT_MAX}};
        }
    }
    
    int largestBst(Node *root)
    {
        return solve(root).first; 
    }
};