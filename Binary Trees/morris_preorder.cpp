/* A binary tree node has data, pointer to left child
   and a pointer to right child  

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

//Function to return a list containing the preorder traversal of the tree.
vector <int> preorder(Node* root)
{
        vector<int> preOrder;
        Node* curr = root;
        
        while(curr){
            if(!curr->left){
                preOrder.push_back(curr->data);
                curr = curr->right;
            }
            else{
                Node* prev = curr->left;
                while(prev->right && prev->right != curr){
                    prev = prev->right ;
                }
                
                if(!prev->right){
                    prev->right = curr;
                    preOrder.push_back(curr->data);
                    curr = curr->left;
                }
                else{
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return preOrder;
}