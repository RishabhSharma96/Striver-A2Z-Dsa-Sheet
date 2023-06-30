/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
	}
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
    
Node* merge(Node* r1 , Node* r2){
    Node* temp = new Node(0);
    Node* ans = temp ;
    
    while(r1!=NULL && r2!= NULL){
        if(r1->data < r2->data){
            temp->bottom = r1;
            temp = temp->bottom ;
            r1 = r1->bottom; 
        }
        else{
            temp->bottom = r2;
            temp = temp->bottom ;
            r2 = r2->bottom;
        }
    }
    
    if(r1 != NULL){
        temp->bottom = r1;
    }
    
    if(r2 != NULL){
        temp->bottom = r2;
    }
    
    return ans->bottom ;
}

Node* solve(Node* root){
    if(!root) return NULL;
    
    Node* temp = solve(root->next);
    Node* merged = merge(temp,root);
    return merged;
}

Node *flatten(Node *root)
{
    return solve(root);
}
