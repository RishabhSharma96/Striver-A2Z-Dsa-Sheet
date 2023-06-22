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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* temp = new ListNode(-1);
        ListNode* ans = temp;

        if(lists.size() == 0){
            return ans->next ;
        }
        
        priority_queue <pair<int,pair<ListNode*,ListNode*>>,
        vector<pair<int,pair<ListNode*,ListNode*>>>,
        greater<pair<int,pair<ListNode*,ListNode*>>>> pq ;
        // for -> {first_element, {list_ref,element_ref}}


        for(int i=0 ; i<lists.size() ; i++){
            if(lists[i]){
                pq.push({lists[i]->val, {lists[i],lists[i]}});
            }
        }

        while(!pq.empty()){
            auto node = pq.top();
            pq.pop() ;
            
            int element = node.first;
            auto listPointer = node.second.first;
            auto elementPointer = node.second.second;
            
            if(elementPointer->next && listPointer->next){
                pq.push({elementPointer->next->val,{listPointer->next,elementPointer->next}});
            }

            temp->next = elementPointer;
            temp = temp->next;
        }

        return ans->next;

    }
};