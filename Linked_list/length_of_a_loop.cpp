/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

//Function to find the length of a loop in the linked list.
int countNodesinLoop(struct Node *head)
{
    if(head == NULL || head->next == NULL) return 0 ;
    
    struct Node* slow = head;
    struct Node* fast = head->next;
    
    while(slow!=fast){
        slow = slow->next ;
        if(fast->next){
            fast = fast->next ;
        }
        fast = fast->next ;
        if(fast == NULL){
            return 0 ;
        }
    }
    
    struct Node* temp = slow ;
    int cnt =0 ;
    slow = slow->next ;
    while(temp != slow){
        cnt++ ;
        slow=slow->next ;
    }
    
    return cnt+1 ;    
    
}