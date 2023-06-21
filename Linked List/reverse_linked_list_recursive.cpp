/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution
{
    public:
    //Function to reverse a linked list.
    
    struct Node* revHead = NULL;
    
    struct Node* solve(struct Node* head){
        
        if(!head){
            return NULL ;
        }
        
        if(!head->next){
            revHead = head;
            return head;
        }
        
        struct Node* temp = solve(head->next);
        temp->next = head;
        head->next = NULL ;
        return head;
        
    }
    
    struct Node* reverseList(struct Node *head)
    {
        solve(head);
        return revHead;
    }
    
};