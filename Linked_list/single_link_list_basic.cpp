class node
{

public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~node()
    {
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};

void insertNodeAtHead(node *&head, int data)
{

    node *tempnode = new node(data);
    tempnode->next = head;
    head = tempnode;
}

void insertNodeAtTail(node *&tail, int data)
{

    node *tempnode = new node(data);
    tail->next = tempnode;
    tail = tail->next;
}

void insertNodeInMiddle(node *&head, node *&tail, int position, int data)
{
    node *temp = head;

    if (position == 1)
    {
        insertNodeAtHead(head, data);
        return;
    }
    else if (temp->next == NULL)
    {
        insertNodeAtTail(tail, data);
        return;
    }

    int count = 1;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    node *nodeToInsert = new node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deletionOfNode(node *&head, node *&tail, int pos)
{

    if (pos == 1)
    {

        node *temp = head;
        head = head->next;
        temp->next = NULL;

        delete temp;
    }

    else
    {

        node *current = head;
        node *previous = NULL;

        int counter = 1;
        while (counter < pos)
        {
            counter++;
            previous = current;
            current = current->next;
        }

        previous->next = current->next;
        current->next = NULL;

        delete current;
    }
}