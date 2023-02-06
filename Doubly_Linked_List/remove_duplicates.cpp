/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        vector<pair<int, int>> ans ;
        if(!head->next) return  ans ;
        
        Node* temp = head ;
        
        while(temp->next != NULL){
            temp = temp->next ;
        }
        
        Node* i=head ;
        Node* j=temp ;
        
        // cout<<i->data<<" "<<j->data<<endl ;
        
        while(i!=j){
            if(i->data + j->data == target){
                ans.push_back({i->data,j->data});
                i=i->next ;
            }
            else if(i->data + j->data > target){
                j=j->prev;
            }
            else{
                i = i->next ;
            }
        }
        return ans ;
    }
};