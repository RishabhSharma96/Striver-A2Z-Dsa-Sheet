class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next) return NULL ;
        if(!head->next->next){
            head->next = NULL ;
            return head ;
        }

        ListNode* slow = head ;
        ListNode* fast = head->next ;
        int cnt=0 ;

        while(fast!=NULL){

            if(cnt != 0){
                slow = slow->next ;
            }
            if(fast->next != NULL){
                fast=fast->next ;
            }
            fast = fast->next ;
            cnt++ ;
        }

        cout<<slow->val ;

        slow->next = slow->next->next ;

        return head ;
        
    }
};