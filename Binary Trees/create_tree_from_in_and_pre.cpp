/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode* solve(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder,
    int inStart, int inEnd, map<int,int> & elIn){
        if(inStart > inEnd || preStart > preEnd){
            return NULL ;
        }

        TreeNode* root = new TreeNode(preorder[preStart]);
        int ElementIndex = elIn[root->val];
        int ElementsOnLeft = ElementIndex - inStart ;

        root->left = solve(preorder,preStart+1,preStart+ElementsOnLeft,inorder,inStart,ElementIndex-1,elIn);
        root->right = solve(preorder,preStart+ElementsOnLeft+1,preEnd,inorder,ElementIndex+1,inEnd,elIn);

        return root;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preSize = preorder.size() ;
        int inSize = inorder.size() ;

        map<int,int> inorderElementIndexes ;

        for(int i=0 ; i<inSize ; i++){
            inorderElementIndexes[inorder[i]] = i;
        }

        return solve(preorder,0,preSize-1,inorder,0,inSize-1,inorderElementIndexes);
    }
};