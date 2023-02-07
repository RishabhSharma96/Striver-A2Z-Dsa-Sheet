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

    int countNodes(ListNode * head){
        auto temp=head;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }

    ListNode* rotateRight(ListNode* head, int k) {

        if(!head) return head;
        k=k%countNodes(head);
        if(!head->next || k==0) return head;

        auto head1=head;
        auto head2=head;
        while(head2->next!=NULL){
            head2=head2->next;
        }

        int n = countNodes(head);
        head2->next = head1;

        int cntr=n-k;

        while(cntr--){
            head2=head2->next;
        }

        head= head2->next;
        head2->next=NULL ;
        return head;
    }
};












