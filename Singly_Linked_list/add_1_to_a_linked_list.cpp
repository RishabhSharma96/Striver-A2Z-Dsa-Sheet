struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    
    Node* reverse(Node* head) {
        if(head == NULL || head->next == NULL){
            return head ;
        }

        Node* cur = head ;
        Node* nex = NULL ;
        Node* prev = NULL ;

        while(cur!=NULL){
            nex = cur->next;
            cur->next = prev ;
            prev = cur;
            cur=nex;
        }
        return prev;
    }
    
    Node* addOne(Node *head) 
    {
        if(head==NULL){
            return NULL ;
        }
        
        head = reverse(head) ;
        
        Node* temp= head ;
        int carry = 0 ;
        Node* prevToTemp = NULL ;
        
        int cnt = 0 ;
        
        while(temp != NULL){
            int d = 0 ;
            if(cnt == 0){
                d = temp->data + carry + 1 ;
            }
            else{
                d = temp->data + carry ;
            }
            cnt++ ;
            temp->data = d%10 ;
            carry = d/10 ;
            prevToTemp = temp ;
            temp = temp->next ;
            
            if(temp == NULL && carry!=0){
                Node* a = new Node(carry) ;
                prevToTemp->next = a ;
                prevToTemp = prevToTemp->next ;
            }
        }
        
        head = reverse(head) ;
        return head ;
        
        
    }
};