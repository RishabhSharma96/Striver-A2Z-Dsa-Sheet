class node
{

public:
    int data;
    node *next;
    node *previous;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->previous = NULL;
    }

    ~node(){
        if(this -> next != NULL){
            delete next ;
            this->next = NULL ;
        }
    }
};

void print(node *&head)
{

    node *temp = head;

    while (temp != NULL)
    {
        cout<<temp -> data<<" " ;
        temp = temp -> next;
    }
    cout<<endl ;
}

int length(node* &head){

    node *temp = head;

    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count ;
}

void insertAtHead(node* &head,node* &tail, int data){
    
    if(head == NULL){
        node* temp = new node(data) ;
        head = temp ;
        tail = temp ;

    }
    else{

    node* temp = new node(data) ;
    temp -> next = head ;
    head -> previous = temp ;
    head = temp ;
    }

}

void insertAtTail(node* &head, node* &tail, int data){
    
    if(tail == NULL){
        node* temp = new node(data) ;
        head = temp ;
        tail = temp ;

    }
    else{

    node* temp = new node(data) ;
    tail -> next = temp ;
    temp -> previous = tail ;
    tail = temp ;
    }

}

void insertAtMiddle(node* &head, node* &tail, int data, int position){

    if(position == 1){
        insertAtHead(head,tail,data) ;
        return ;
    }
    node* temp = head ;
        int count = 1 ;

        while(count < position - 1){

            temp = temp -> next ;
            count++ ;
        }

    if(temp->next == NULL){

        insertAtTail(head,tail, data);
        return;
    }

    else{

        node *nodeToInsert = new node(data) ;

        nodeToInsert -> previous = temp ;
        nodeToInsert -> next = temp -> next ;
        temp -> next -> previous = nodeToInsert ;
        temp -> next = nodeToInsert ;
    }
}

void deleteNode(node* &head , node* &tail , int position){

    if(position == 1){
        node* temp = head ;
        temp -> next -> previous = NULL ;
        head = temp -> next ;
        temp -> next = NULL ;
        
        delete temp ;
    }
    else{

        node *curr = head;
        node *prev = NULL;

        int counter = 1;
        while (counter < position)
        {
            counter++;
            prev = curr;
            curr = curr->next;
        }

        curr -> previous = NULL ;
        prev -> next = curr -> next ;
        curr -> next = NULL ;
        delete curr ;

        delete curr;
    }
};