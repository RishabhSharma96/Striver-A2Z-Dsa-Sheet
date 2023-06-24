/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        vector<int> inorder;
        Node* curr = root;
        
        while(curr){
            if(!curr->left){
                inorder.push_back(curr->data);
                curr = curr->right;
            }
            else{
                Node* prev = curr->left;
                while(prev->right && prev->right != curr){
                    prev = prev->right ;
                }
                
                if(!prev->right){
                    prev->right = curr;
                    curr = curr->left;
                }
                else{
                    prev->right = NULL;
                    inorder.push_back(curr->data);
                    curr = curr->right;
                }
            }
        }
        return inorder;
    }
};
