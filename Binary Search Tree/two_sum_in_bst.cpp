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

class bstiterator {
    private:
    stack<TreeNode*> s ;
    bool reverse=true ;

    void pushall(TreeNode* root){
        while(root!=NULL){
            s.push(root);
            if(reverse){
                root = root->right ;
            }
            else{
                root = root->left;
            }
        }
    }

    public:
    bstiterator(TreeNode* root , bool a){
        this->reverse = a ;
        pushall(root);
    } 

    int next(){
        auto a = s.top();
        s.pop();

        if(reverse){
            pushall(a->left);
        }
        else{
            pushall(a->right);
        }
        return a->val ;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        
        if(root==NULL) return false;

        bstiterator l (root,false);
        bstiterator r (root,true);

        int i = l.next();
        int j = r.next();

        while(i<j){
            if(i+j == k){
                return true;
            }
            else if(i+j < k){
                i=l.next() ;
            }
            else{
                j=r.next() ;
            }
        }

        return false;
    }
};