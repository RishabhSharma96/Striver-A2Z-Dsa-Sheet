/* Structure of a node in Queue
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

And structure of MyQueue
struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
}; */

// Function to push an element into the queue.
void MyQueue::push(int x)
{
    // Your Code
    QueueNode *newNode = new QueueNode(x);
    if (front == NULL)
    {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

// Function to pop front element from the queue.
int MyQueue ::pop()
{
    // Your Code
    if (front == NULL && rear == NULL)
        return -1;
    int f = front->data;
    if (rear == front)
        rear = front = NULL;
    else
        front = front->next;
    return f;
}