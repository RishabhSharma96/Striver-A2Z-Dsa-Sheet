/*

  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
public:
    Node *segregate(Node *head)
    {

        Node *ptr = head;
        Node *zeroHead = new Node(-1);
        Node *oneHead = new Node(-1);
        Node *twoHead = new Node(-1);
        Node *ptr0 = zeroHead, *ptr1 = oneHead, *ptr2 = twoHead;

        while (ptr)
        {
            if (ptr->data == 0)
            {
                ptr0->next = ptr;
                ptr0 = ptr0->next;
                ptr = ptr->next;
                ptr0->next = nullptr;
            }
            else if (ptr->data == 1)
            {
                ptr1->next = ptr;
                ptr1 = ptr1->next;
                ptr = ptr->next;
                ptr1->next = nullptr;
            }
            else
            {
                ptr2->next = ptr;
                ptr2 = ptr2->next;
                ptr = ptr->next;
                ptr2->next = nullptr;
            }
        }

        ptr1->next = twoHead->next ? twoHead->next : nullptr;
        ptr0->next = oneHead->next ? oneHead->next : nullptr;

        head = zeroHead->next;
        return head;
    }
};