// User function Template for C++

// Function to return the ceil of given number in BST.

void solve(Node* root, int & ans, int input){
    if(!root) return ;
    
    if(root->data < ans && root->data >= input){
        ans = root->data ;
    }
    if(root->data > input){
        solve(root->left, ans, input);
    }
    else{
        solve(root->right, ans, input); 
    }
}

int findCeil(Node* root, int input) {
    int ans = 1e8 ;
    solve(root, ans, input);
    return ans == 1e8 ? -1 : ans ;

}