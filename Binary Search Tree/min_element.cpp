// Function to find the minimum element in the given BST.

/*
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
*/

void solve(Node* root, int & ans){
    if(!root) return ;
    
    ans = min (ans, root->data);
    
    if(root->left){
        solve(root->left, ans);
    }
    else{
        solve(root->right, ans); 
    }
}

int minValue(Node* root) {
    int ans = 1e8 ;
    solve(root, ans);
    return ans == 1e8 ? -1 : ans ;
}