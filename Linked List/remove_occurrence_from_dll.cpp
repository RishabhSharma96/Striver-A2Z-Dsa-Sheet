// User function Template for C++


/* a Node of the doubly linked list 
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        
        if((*head_ref) == NULL) return ;
        
        struct Node* temp = *head_ref;
        
        while(temp != NULL){
            
            if(temp->data == x){
                if(temp->prev == NULL){
                    (*head_ref) = (*head_ref)->next ;
                }
                else if(temp->next == NULL){
                    temp->prev->next = NULL;
                }
                else{
                    temp->prev->next = temp->next ;
                    temp->next->prev = temp->prev;
                }
            }
            
            temp = temp->next;
        }
        
    }
};