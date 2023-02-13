class MyStack
{
public:
    queue<int> q1;
    queue<int> q2;

    MyStack()
    {
    }

    void push(int x)
    {

        q1.push(x);
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }

        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
    }

    int pop()
    {
        int x = q2.front();
        q2.pop();
        return x;
    }

    int top()
    {
        return q2.front();
    }

    bool empty()
    {
        if (q2.empty() == false)
        {
            return false;
        }
        return true;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */