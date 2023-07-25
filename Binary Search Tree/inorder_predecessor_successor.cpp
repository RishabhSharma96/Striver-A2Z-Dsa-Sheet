/* BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
        key = x;
        left = NULL;
        right = NULL;
	}
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{
    public:
    
    // O(H) method
    void predecessor(Node* root , Node* &pre, int key){
        
        while(root){
            if(root->key < key){
                pre = root;
                root = root->right;
            }    
            else{
                root = root -> left ;
            }
        }
    }
    
    // O(H) method
    void successor(Node* root , Node* &suc, int key){
        
        while(root){
            if(root->key <= key){
                root = root->right;
            }    
            else{
                suc = root;
                root = root -> left ;
            }
        }
    }
    
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        predecessor(root,pre,key);
        successor(root,suc,key);
    }
};