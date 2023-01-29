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

    ListNode* middle(ListNode* head){
        ListNode* temp = head ;
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next ;
            if(fast->next){
                fast=fast->next ;
            }
            fast=fast->next ;
        }
        return slow ;
    }

    ListNode* reverse(ListNode* head2){
        ListNode* curr=head2 ;
        ListNode* prev = NULL ;
        ListNode* n = NULL;

        while(curr!=NULL){
            n = curr->next ;
            curr->next = prev ;
            prev=curr ;
            curr=n ;
        }

        return prev ;
    }

    bool isPalindrome(ListNode* head) {

        if(head->next == NULL) return true ;

        ListNode* head1 = head ;
        ListNode* temp = middle(head) ;
        ListNode* head2 = temp->next ;
        temp->next = NULL ;

        head2 = reverse(head2);

        while(head1 != NULL && head2 != NULL){
            if(head1->val != head2->val){
                return false;
            }
            head1=head1->next ;
            head2=head2->next ;
        }
        return true ;
    }
};