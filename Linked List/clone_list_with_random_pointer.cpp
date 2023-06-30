/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

    Node* duplicate(Node* head){

        // INSERTING OUR OWN COPY OF LIST WITHOUT RANDOM POINTERS -> 
        Node* curr = head;
        while(curr!=NULL){
            Node* temp = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = temp;
            curr = temp;
        }

        // COPYING RANDOM POINTERS ->
        curr = head;
        while(curr != NULL) {
            if(curr->random != NULL){
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // SEPERATING THE LISTS ->
        Node* dummy = new Node(0);
        curr = head;
        Node* temp = dummy;
        Node* fast;
        while(curr != NULL) {
            fast = curr->next->next;
            temp->next = curr->next;
            curr->next = fast;
            temp = temp->next;
            curr = fast;
        }

        //RETURNING COPY OF LIST ->
        return dummy->next;
    }

    Node* copyRandomList(Node* head) {
        return duplicate(head);;
    }
};