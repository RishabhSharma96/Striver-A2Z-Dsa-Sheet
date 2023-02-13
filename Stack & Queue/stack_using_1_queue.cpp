class MyStack {
public:

    queue<int> q ;

    MyStack() {
        
    }
    
    void push(int x) {
        
        q.push(x) ;
        int size = q.size() - 1;

        while(size--){
            int x = q.front() ;
            q.pop() ;
            q.push(x) ;
        }
    }
    
    int pop() {
        int x = q.front() ;
        q.pop() ;
        return x ;
    }
    
    int top() {
        return q.front() ;
    }
    
    bool empty() {
        if (q.empty() == false)
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