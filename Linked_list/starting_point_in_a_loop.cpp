class Solution {
public:

    ListNode *detectCycle(ListNode *head) {

        if(head == NULL) return NULL;

        if(head->next == NULL) return NULL ;
        if(head->next == head) return head ;

        ListNode* slow = head ;
        ListNode* fast = head->next ;

        while(slow!=fast){

            slow = slow->next ;
            if(fast->next!=NULL){
                fast=fast->next ;
            }
            fast = fast->next ;
            if(fast == NULL){
                return NULL ;
            }
        }

        slow = head ;

        while(slow!=fast->next){
            slow = slow->next ;
            fast = fast->next ;
        }

        return slow ;
    }
};