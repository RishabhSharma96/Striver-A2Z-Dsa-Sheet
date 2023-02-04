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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2 ;
        if(l2 == NULL) return l1 ;

        ListNode* temp = new ListNode(-1) ;
        ListNode* head = temp ;
        int carry = 0 ;

        while(l1 != NULL || l2 != NULL || carry != 0){
            int a=0,b=0 ;
            if(l1 != NULL){
                a=l1->val ;
                l1 = l1->next ;
            }
            if(l2 != NULL){
                b=l2->val ;
                l2 = l2->next ;
            }
            int sum = a+b+carry ;
            cout<<sum<<" " ;
            int value = sum%10 ;
            carry = sum/10 ;

            ListNode* newNode = new ListNode(value) ;
            temp->next = newNode ;
            temp = temp->next ;
        }
        
        return head->next;
    }
};