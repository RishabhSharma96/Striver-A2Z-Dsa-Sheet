// using array
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
class BSTIterator {
public:

    void inorder(TreeNode* root, vector<int> & helper){
        if(!root) return ;

        inorder(root->left,helper);
        helper.push_back(root->val);
        inorder(root->right,helper);
    }

    int head = 0 ;
    vector<int> helper ;

    BSTIterator(TreeNode* root) {
        inorder(root,helper);
    }
    
    int next() {
        return helper[head++];
    }
    
    bool hasNext() {
        return head == helper.size() ? false : true ;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */








// using stack
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
class BSTIterator {
    private :

    stack<TreeNode*> s;
    void partialInorder(TreeNode* root){
        while(root != NULL){
            s.push(root);
            root = root->left;
        }
    }

    public:
    BSTIterator(TreeNode* root) {
        partialInorder(root);
    }
    
    
    int next() {
        TreeNode* top = s.top();
        s.pop();
        partialInorder(top->right);
        return top->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */