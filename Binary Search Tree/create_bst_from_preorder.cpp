// BRUTE FORCE METHOD -
class Solution {
public:

    TreeNode* solve(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);
        
        TreeNode* temp = root ;

        while(temp != NULL){
            if(val > temp->val){
                if(temp->right == NULL){
                    TreeNode* newNode = new TreeNode(val);
                    temp->right = newNode ;
                    break ;
                }
                else{
                    temp = temp->right;
                }
            }
            else{
                if(temp->left == NULL){
                    TreeNode* newNode = new TreeNode(val);
                    temp->left = newNode ;
                    break ;
                }
                else{
                    temp = temp->left;
                }
            }
        }
        return root ;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {

        TreeNode* root = new TreeNode(preorder[0]);

        for(int i=1 ; i<preorder.size() ; i++){
            root = solve(root,preorder[i]);
        }

        return root;
    }
};

// OPTIMIZED
class Solution {
public:

    TreeNode* solve (vector<int>& preorder, int & i, int ub){

        if(i >= preorder.size() || preorder[i] > ub) return NULL ;

        TreeNode* root = new TreeNode(preorder[i]);
        i++;

        root->left = solve(preorder,i,preorder[i-1]);
        root->right = solve(preorder,i,ub);

        return root ;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0 ;
        return solve(preorder,i,INT_MAX);
    }
};