/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

TIME COMPLEXITY -> O(n*m) ;

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* temp = headB;  
        while(headA != NULL){
            headB = temp ;
            while(headB != NULL){
                if(headA == headB){
                    return headA ;
                }
                headB = headB->next ;
            }
            headA = headA->next ;
        }

        return NULL ;

    }
};

TIME COMPLEXITY -> O(n+m) ;

class Solution {
public:

    int helper(ListNode* head){
        auto temp = head ;
        int cnt =0 ;
        while(temp){
            cnt++ ;
            temp = temp->next ;
        }
        return cnt ;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = helper(headA) ;
        int len2 = helper(headB) ;

        int diff = abs(len1-len2) ; 

        if(len1 > len2){
            while(diff--){
                headA = headA->next ;
            }
        }
        else{
            while(diff--){
                headB = headB->next ;
            }
        }

        while(headA != NULL && headB != NULL){
            if(headA == headB){
                return headA ;
            }
            headA = headA->next ;
            headB = headB->next ;
        }
        return NULL ;
    }
};