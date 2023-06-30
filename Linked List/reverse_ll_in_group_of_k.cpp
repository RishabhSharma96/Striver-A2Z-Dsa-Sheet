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

    ListNode* solve(ListNode* head, int k){

        ListNode* traverser = head;
        for(int i = 0; i < k; i++){
            if(traverser == nullptr) return head;
            traverser = traverser->next;
        }

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nextt;

        int count=0 ;
        while(count<k && curr != NULL){
            nextt = curr->next;
            curr->next = prev;
            prev=curr;
            curr = nextt;
            count++;
        }
        

        if(curr) head->next = reverseKGroup(curr,k);
        
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        return solve(head,k);
    }
};