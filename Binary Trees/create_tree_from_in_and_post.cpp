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

    TreeNode* solve(vector<int>& postorder, int postStart, int postEnd, vector<int>& inorder,
    int inStart, int inEnd, map<int,int> & elIn){

        if(inStart > inEnd || postStart > postEnd){
            return NULL ;
        }

        TreeNode* root = new TreeNode(postorder[postEnd]);
        int ElementIndex = elIn[root->val];
        int ElementsOnLeft = ElementIndex - inStart ;

        root->left = solve(postorder,postStart,postStart+ElementsOnLeft-1,inorder,inStart,ElementIndex-1,elIn);
        root->right = solve(postorder,postStart+ElementsOnLeft,postEnd-1,inorder,ElementIndex+1,inEnd,elIn);

        return root;

    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postSize = postorder.size() ;
        int inSize = inorder.size() ;

        map<int,int> inorderElementIndexes ;

        for(int i=0 ; i<inSize ; i++){
            inorderElementIndexes[inorder[i]] = i;
        }

        return solve(postorder,0,postSize-1,inorder,0,inSize-1,inorderElementIndexes);
    }
};