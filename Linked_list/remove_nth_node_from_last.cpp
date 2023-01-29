/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    int nodes(ListNode* head){
        auto temp = head ;
        int cnt=0 ;
        while(temp!=NULL){
            cnt++ ;
            temp=temp->next ;
        }
        return cnt ;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == NULL) return NULL ;
        
        auto curr=head;

        while(n--){
            curr=curr->next;
        }

        auto prev=head ;

        while(curr!=NULL){
            prev=prev->next ;
            curr=curr->next ;
        }

        prev->next = prev->next->next; 
        return head ;


    }
};