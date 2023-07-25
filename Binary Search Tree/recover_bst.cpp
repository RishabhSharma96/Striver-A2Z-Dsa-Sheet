// O(N) SOLUTION
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

    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
    TreeNode* prev;

    void inorder(TreeNode* root){
        if( root == NULL ){ return ;}
        inorder(root->left);

        if((prev!=NULL) && (root->val < prev->val)){
            if(first == NULL){
                first=prev;
                middle=root ;
            }
            else{
                last = root ;
            }
        }
        prev=root ;
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        first = NULL ;
        middle = NULL ;
        last = NULL ;
        prev = new TreeNode(INT_MIN);
        inorder(root) ;

        if(first != NULL && last != NULL){
            swap(first->val, last->val) ;
        }
        else if(last == NULL){
            swap(first->val , middle->val );
        }
    }
};

// O(NlogN) SOLUTION
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

    int iterator = 0;

    void get_inorder(TreeNode* root, vector<int> & inorder){
        if(!root) return ;
        get_inorder(root->left,inorder);
        inorder.push_back(root->val);
        get_inorder(root->right,inorder);
    }

    void set_inorder(TreeNode* &root, vector<int> & inorder){
        if(!root) return ;
        set_inorder(root->left,inorder);
        root->val = inorder[iterator++];
        set_inorder(root->right,inorder);
    }

    void recoverTree(TreeNode* root) {
        vector<int> inorder;
        get_inorder(root,inorder);
        sort(inorder.begin(), inorder.end());
        set_inorder(root,inorder);
    }
};